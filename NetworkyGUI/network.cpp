#include "network.h"

Network::Network(string filename) {
    // TODO Auto-generated constructor stub
    readFile(filename);
}

Network::~Network() {
    // TODO Auto-generated destructor stub
}

pair<QString, int> Network::getMutual(QString first, QString second, QStringList & mutual){

    int found=0;///number of mutual friends found
    QString error;

    int firstPerson = findIndex(first);
    int secondPerson = findIndex(second);

    if(firstPerson ==-1 && secondPerson !=-1)////first name is not valid
    {
        error = "Error: First name is not found on the network";
        return make_pair(error, found);
    }
    if(firstPerson !=-1 && secondPerson ==-1)/////sec name is not valid
    {
        error = "Error: Second name is not found on the network";
        return make_pair(error, found);
    }
    if(firstPerson ==-1 && secondPerson ==-1)///both names are unvalid
    {
        error = "Error: Both names are not found on the network";
        return make_pair(error, found);
    }
    if(firstPerson == secondPerson){
        error = "Error: Same Person";
        return make_pair(error, found);
    }

    if(firstPerson !=-1 && secondPerson !=-1 )////both names exist
    {
        error = "No Error";
        for(uint i =0;i<person.at(firstPerson)->connection.size();i++)///loop through connections of first person
        {
            for(uint j =0;j<person.at(secondPerson)->connection.size();j++)///loop through connections of second person
            {

                if(person.at(firstPerson)->connection.at(i)->name == person.at(secondPerson)->connection.at(j)->name)///check if connection->name i equal to connection->name j
                {
                    found++;
                    mutual.append(person.at(firstPerson)->connection.at(i)->name);
                    break;
                }
            }
        }
    }
    return make_pair(error, found);
}

vector<Person *> Network::getSuggestedFriends(QString name, bool sameCompany)
{
    int index = findIndex(name);
    vector<Person *> suggests;
    if(index == -1)
        return suggests;
    Person * p = person.at(index);
    if(sameCompany)
        recurseFriends(suggests, p, p->name, p->company, 0, 5);
    else
        recurseFriends(suggests, p, p->name, 0, 5);

    return suggests;
}

void Network::recurseFriends(vector<Person *> & suggests, Person * p, QString preConn, QString company, int count, int limit)
{
    if(count > limit || p->isMarked || p == NULL)
        return;
    p->isMarked = true;
    if(p->company == company && p->name != preConn)
        suggests.push_back(p);
    for(uint i=0 ; i<p->connection.size() ; i++){
        Person * temp = p->connection.at(i);
        if(temp->name != preConn)
            recurseFriends(suggests, temp, p->name, company, count+1, limit);
    }
}

void Network::recurseFriends(vector<Person *> & suggests, Person * p, QString preConn, int count, int limit)
{
    if(count > limit || p->isMarked || p == NULL)
        return;
    p->isMarked = true;
    suggests.push_back(p);
    for(uint i=0 ; i<p->connection.size() ; i++){
        Person * temp = p->connection.at(i);
        if(temp->name != preConn)
            recurseFriends(suggests, temp, p->name, count+1, limit);
    }
}

vector< vector<Person* > > Network::KargerMinCut(){
    // initialization
    vector< vector<Person* > > groups; // vector of vectors of persons

    // nr of persons in my network
    uint nrOfPersons = person.size();

    //filling the vector of vectors
    // such that the first element in the group hold a person
    for(uint i = 0 ; i<nrOfPersons ; i++){
        // insert the element in person to index 0 at the group
        vector<Person* >  n;
        n.push_back(person.at(i));
        groups.push_back(n);
    }

    vector< vector<Person* > > Mingroups; // vector of vectors of persons in MinGroup
    int MinCut = groups.size();// min cut

    //Repeat Algo To get Best Results
    int nrOfRepeats = 30 ;
    while(nrOfRepeats!=0){
        // while decreminator
        nrOfRepeats--;

        //while the no of groups > 2 we need to union the persons in a groups
        while(groups.size()>2){// if we are here then the no of groups are < 2

            int noOfPersons = person.size(); // getting the nr of Groups
            int randPerson = rand() % noOfPersons;// get random group no. to enter
            Person * src = person.at(randPerson);
            int noOfConns = src->connection.size();
            int randConn = rand() % noOfConns;
            Person * dst = src->connection.at(randConn);

            int srcGroup = searchGroups(groups, src->name);
            int dstGroup = searchGroups(groups, dst->name);

            if(srcGroup == dstGroup)
                continue;
            else{
                //copy vector of persons fron dst to the group of src
                int noOfPersonsInDst = groups.at(dstGroup).size(); // no of persons in dst group

                for(int i = 0 ; i<noOfPersonsInDst; i++){
                    groups.at(srcGroup).push_back(groups.at(dstGroup).at(i));
                }
                // delete the group of dst
                groups.erase(groups.begin()+(dstGroup));

            }

        }

        if(getMinCutValue(groups) < MinCut)
        {
            MinCut=getMinCutValue(groups);
            Mingroups = groups;
        }
    }
}

int Network::getMinCutValue(vector< vector<Person *> > & g){
    int count = 0 ;
    // get to each member of group 0
    for(uint i =0 ; i < g.at(0).size() ;i++){
        // get to person i connection
        uint nrOfConns = g.at(0).at(i)->connection.size();

        for(uint j =0 ; j<nrOfConns ; j++){
        // if that person doesn't belongs to group 0
            QString conName = g.at(0).at(i)->connection.at(j)->name;
            if(searchGroups(g,conName) !=0 ){
                count++;
            };
        }
    }
    return count;
}

void Network::readFile(string filename){
    string line;
    ifstream file;
    file.open(filename.c_str());

    //checking the file exists
    if(file.is_open()){
        //getting first line in the file which is a number.
        //stands for number of persons in the file
        //so we need to convert it from string to integer
        if(getline(file, line))
            personCount = atoi(line.c_str());
        //reading an empty line and escaping it
        getline(file, line);
        //looping to read the names of persons in the network
        //creating objects to save each person with his/her details
        for(int i=0; i<personCount ; i++){
            if(getline(file, line)){
                //checking the line is not empty and escaping it if empty
                if(line == ""){
                    i--;
                    continue;
                }
                //split the line into words on a delimiter ","
                QStringList elems = QString::fromStdString(line).split(",", QString::SkipEmptyParts);
                if(elems.size()>0)
                {
                    //creating the object and pushing it to the vector
                    Person *p = new Person(elems.at(0), elems.at(1), elems.at(2), elems.at(3));
                    person.push_back(p);
                }
            }
        }

        //reading an empty line and escaping it
        getline(file, line);
        //looping to read the connections in the network
        //pushing each connection with its respected connection
        for(int i=0; i<personCount ; i++){
            if(getline(file, line)){
                if(line != ""){
                    //split the line into words
                    QStringList elems = QString::fromStdString(line).split(",", QString::SkipEmptyParts);
                    if(elems.size()>0)
                    {
                        for(int j=0; j<elems.size() ; j++){
                            person.at(i)->connection.push_back(find(elems.at(j)));
                        }
                    }
                }
            }
        }
        file.close();
    }else{
        cout << "Unable to open file" << endl;
    }
}

/*
*
*Shortest link when searching
*
*
*/
/*
void Network::getShortestLink(){
    QString src, dst;///source and destination names
    vector <QString> path;

    cout << "Please enter first name:"<<endl;
    getline(cin,src);
    std::pair<int, int> connSRC = check(src); ///check that the name is valid, also get its index in the network
    if (connSRC.first==0){
        cout <<"Name not found on the network"<<endl;
        return;
    }
    cout << "Please enter second name:"<<endl;
    getline(cin,dst);
    std::pair<int, int> connDST = check(dst);///check that the name is valid
    if (connDST.first==0){
        cout <<"Name not found on the network"<<endl;
        return;
    }


    int min=0; ///min link counter
    initializeMarks();

    QString inter;
    queue <QString> q;
    map <QString,QString> track; //first element is person, the second is the parent


    q.push(src); ///put first name into queue
    track.insert(pair<QString,QString>(src,""));

    ////BREADTH FIRST SEARCH
    while(!q.empty()){
        inter = q.front();/////return the froont of the queue without removing it
        std::pair<int, int> temp = check(inter); //get its location in the network aand put it into the temp variable
        q.pop(); ///remove the front of the queue
        person.at(temp.second)->isMarked=true; ///Mark as visited so that we don't visit it again

        for(int i=0;i<person.at(temp.second)->connection.size();i++) ///loop through connections of the front of queue
        {
            QString ok = person.at(temp.second)->connection.at(i)->name; /////leave it for debugging purposes
            track.insert(pair<QString,QString>(ok,inter));
            if(person.at(temp.second)->connection.at(i)->isMarked==false)///check that this person is not visted before
            {
                if(person.at(temp.second)->connection.at(i)->name == dst) ////we found the destination name
                {
                    cout <<"Length of shoretst link "<<min<<endl;
                    cout <<"Nodes between "<<src<<" & "<<dst<<endl;
                    backtrack(track,dst,src); ///call backtrack function once you found the right destination

                    return; ////exit
                }
                q.push(person.at(temp.second)->connection.at(i)->name); //// else we didn't found the name put it into the queue
            }
        }
    }


}
*/

/*
*backtrackingggggggggggggggg
*/
/*
void Network::backtrack(std::map<QString, QString> temp_map,QString dst,QString src){
    QString parent;
    vector <QString> path;
    parent = temp_map.find(dst)->second;///get parent of the dst
    if(src==parent)	return;
    else{
        path.push_back(parent); ///add the node to the path
        for(int i =0;i<path.size();i++){
            cout <<path.at(i)<<endl;
        }

        backtrack(temp_map,parent,src); ///recurse with parent as the new destination (going back)
    }
}
*/

Person* Network::find(QString name){
    for (uint i=0 ; i<person.size() ; i++){
       if(person.at(i)->name.contains(name)){
          return person.at(i);
       }
    }
    return NULL;
}

int Network::findIndex(QString name){
    for (uint i=0 ; i<person.size() ; i++){
       if(person.at(i)->name.contains(name)){
          return i;
       }
    }
    return -1;
}

bool Network::find(vector<Person *> & person, QString name){
    // if we want to find a person with name exactly as written
    for (uint i=0 ; i<person.size() ; i++){
        if(person.at(i)->name.contains(name)){
            return true;
        }
    }
    return false;
}

int Network::searchGroups(vector< vector<Person *> > & groups, QString name)
{
    for(int i=0 ; i<groups.size() ; i++){
        vector< Person *> personVec = groups.at(i);
        if(find(personVec, name)){
            return i;
        }
    }

    return -1;
}

void Network::initializeMarks()
{
    for(int i=0 ; i<person.size() ; i++){
        person.at(i)->isMarked = false;
    }
}

