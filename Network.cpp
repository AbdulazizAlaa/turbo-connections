/*
 * Network.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: abdulaziz
 */

#include "Network.h"

Network::Network(string filename) {
	// TODO Auto-generated constructor stub
	readFile(filename);
}

Network::~Network() {
	// TODO Auto-generated destructor stub
}

Person* Network::find(string name , bool exactMatch){
	// if we want to find a person with name exactly as written
	if(exactMatch){
		for (int i=0 ; i<person.size() ; i++){
		   if(person.at(i)->name == name){
			  return person.at(i);
		   }
		}
	}else{// if we want to find a person with name near to what we written
		// it wil return first somehow exact name
		for (int i=0 ; i<person.size() ; i++){
		   if(nameMatch(person.at(i)->name,name)){

			  return person.at(i);
		   }
		}
	}

	return NULL;
}

vector<pair<string, int> > Network::QueryNameNotExactMatch(string name){
	// if we want to find a person with name near to what we written
	// it wil return a vector of persons somehow exact name

	vector<pair<string, int> > vNameMatch ; // the vector where found names are stored
	vector<pair<string, int> > NamewithRanks; // this vector holds the names of highest ranks
	int maxRankTemp = 0 ;//that var hold the current max rank 

	for (int i=0 ; i<person.size() ; i++){
		string n1 =person.at(i)->name; 
		string n2 = name;

		std::transform(n1.begin(), n1.end(), n1.begin(), ::tolower);		// convert to small letters
		std::transform(n2.begin(), n2.end(), n2.begin(), ::tolower);		// convert to small letters
		
		int check = nameMatchRank(n1,n2);
		if(check){// this mean there is a match 
			if(check >= maxRankTemp){// now we need to save that person
				
				if(check == maxRankTemp){// now we have to push that new person , 
					// this mean we have many person with same rank ex(ahmed hessen and ahmed alaa , and we are searching for ahmed)
					vNameMatch.push_back(make_pair(person.at(i)->name, i));
				}else{
					// if we entered that block then we have a new One with a hightest rank EVER !!
					vNameMatch.clear();// empty the vector
					vNameMatch.push_back(make_pair(person.at(i)->name, i));
				}
				maxRankTemp++;
			}
		}
		//int rank = nameMatchRank(n1,n2);
	}
	return vNameMatch;
}

bool Network::nameMatch(string src , string dst){
	// array of strings contains each string components
	vector<string> SrcElems;
	vector<string> DstElems;

	// splitting the strings with " " space
	splitNames(src,SrcElems,' ');
	splitNames(dst,DstElems,' ');

	for(int i =0 ; i<SrcElems.size();i++){
		for(int j=0 ; j<DstElems.size(); j++){
			if(SrcElems.at(i)== DstElems.at(j)){
				return true;
			}
		}
	}

	return false;
}

int Network::nameMatchRank(string src , string dst ){
	// array of strings contains each string components
	vector<string> SrcElems;
	vector<string> DstElems;
	int rank= 0;

	// splitting the strings with " " space
	splitNames(src,SrcElems,' ');
	splitNames(dst,DstElems,' ');

	for(int i =0 ; i<SrcElems.size();i++){
		for(int j=i ; j<DstElems.size(); j++){
			if(SrcElems.at(i)== DstElems.at(j)){
				rank++;
				break;
			}
		}
	}
	return rank;
}


/*
 * prints the graph
 * every person details and his/her connections
 */
void Network::printNetwork(){
	for(int i=0; i<person.size() ; i++){
		cout << "person " << i << endl;
		person.at(i)->printDetails();
	}
}

void Network::searchPerson(){
	cout << "Enter name to search for:" << endl;
	string name ;
	getline(cin, name);
	vector<pair<string, int> > temp = QueryNameNotExactMatch(name);
	if(temp.size() == 0 ){
		cout << "Person Not Found. Check you typed correctly." << endl;
	}else{
		// printing results
		cout<< "Choose the no. that indicate your friend you search for : "<<endl;
		for(int i=0; i <temp.size() ; i++){
			cout << i+1 <<".\t"<<temp.at(i).first<<endl;
		}
		int n;
		cin >> n ;
		n = (n<=0)?1:n;
		person.at(temp.at(n-1).second)->printDetails();
	}
}

std::pair<int, int> Network::check(string name){
	int ok ;
	int i=0;

	Person * temp = find(name, false);
	if(temp == NULL){
		ok = 0;
	}else{
		ok = 1;
		for ( i=0 ; i<person.size() ; i++){
			if(person.at(i)->name == temp->name){
				ok = 1;
				break;
			}
		}
	}

	return std::make_pair(ok,i);
}

int Network::getMutual(string first, string second){

	int found=0;///number of mutual friends found

	std::pair<int, int> firstPerson = check(first);
	std::pair<int, int> secondPerson = check(second);

	if(firstPerson.first ==0 && secondPerson.first ==1)////first name is not valid
	{
		cout << "Error: " << "First name is not found on the network"<<endl;
		return found;
	}
	if(firstPerson.first ==1 && secondPerson.first ==0)/////sec name is not valid
	{
		cout << "Error: " << "Second name is not found on the network"<<endl;
		return found;
	}
	if(firstPerson.first ==0 && secondPerson.first ==0)///both names are unvalid
	{
		cout << "Error: " << "Both names are not found on the network"<<endl;
		return found;
	}
	if(firstPerson.second == secondPerson.second){
		cout << "Error: " << "Same Person" << endl;
		return found;
	}

	if(firstPerson.first ==1 && secondPerson.first ==1 )////both names exist
	{
		cout << "Mutual friend(s) are "<<endl;
		for(int i =0;i<person.at(firstPerson.second)->connection.size();i++)///loop through connections of first person
		{
			for(int j =0;j<person.at(secondPerson.second)->connection.size();j++)///loop through connections of second person
			{

				if(person.at(firstPerson.second)->connection.at(i)->name == person.at(secondPerson.second)->connection.at(j)->name)///check if connection->name i equal to connection->name j
				{
					found++;
					cout <<person.at(firstPerson.second)->connection.at(i)->name<<endl;
					break;
				}
			}
		}
	}

	///print number of mutual friends
	cout << "Number of mutual friends between "<<person.at(firstPerson.second)->name << " and "<<person.at(secondPerson.second)->name << " = "<< found<<endl;
	return found;
}

int Network::numMutual()
{
	string first,second;//first: first name, second: second name

	cout <<"Enter first full name"<<endl;
	cin.ignore();
	getline(cin,first);

	cout <<"Enter second full name"<<endl;
	getline(cin,second);

	return getMutual(first, second);

}

void Network::splits(string line, vector<string> & elems, char del){
	int start=0;
	int end=0;
	for(int j=0 ; j<line.size() ;j++){
		if(line.at(j) == del){
			end = j;
			elems.push_back(line.substr(start, end-start));
			start = end+2;
		}
	}
	elems.push_back(line.substr(start, line.size()-start));

}

void Network::splitNames(string line, vector<string> & elems, char del){
	int start=0;
	int end=0;
	for(int j=0 ; j<line.size() ;j++){
		if(line.at(j) == del){
			end = j;
			elems.push_back(line.substr(start, end-start));
			start = end+1;
		}
	}
	elems.push_back(line.substr(start, line.size()-start));

}

int Network::suggestedFriends()
{
	cout << "Enter name of user to get suggested friends for: " << endl;
	string name;
	getline(cin, name);
	int num = getSuggestedFriends(name);
	return num;
}

int Network::getSuggestedFriends(string name)
{
	Person * p = person.at(getExactName(name));
	vector<Person *> suggests;
	recurseFriends(suggests, p, p->name, p->company, 0, 5);

	cout << "number of suggests: " << suggests.size() << endl;
	cout << suggests.at(0)->name;
	for(int i=1 ; i<suggests.size() ; i++){
		cout << ", " << suggests.at(i)->name;
	}
	cout << endl;

	return suggests.size();
}

void Network::recurseFriends(vector<Person *> & suggests, Person * p, string preConn, string company, int count, int limit)
{
	if(count > limit || p->isMarked)
		return;
	p->isMarked = true;
	if(p->company == company && p->name != preConn)
		suggests.push_back(p);
	//p->printDetails();
	for(int i=0 ; i<p->connection.size() ; i++){
		Person * temp = p->connection.at(i);
		if(temp->name != preConn)
			recurseFriends(suggests, temp, p->name, company, count+1, limit);
	}
}

int Network::getExactName(string name)
{
	vector<pair<string, int> > temp = QueryNameNotExactMatch(name);
	if(temp.size() == 0 ){
		cout << "Person Not Found. Check you typed correctly." << endl;
		return -1;
	}else if(temp.size() == 1){
		//person.at(temp.at(0).second)->printDetails();
		return temp.at(0).second;
	}else{
		// printing results
		cout<< "Choose the no. that indicate your friend you search for : "<<endl;
		for(int i=0; i <temp.size() ; i++){
			cout << i+1 <<".\t"<<temp.at(i).first<<endl;
		}
		int n;
		cin >> n ;
		n = (n<=0)?1:n;
		//person.at(temp.at(n-1).second)->printDetails();
		return temp.at(n-1).second;
	}
}

void Network::initializeMarks()
{
	for(int i=0 ; i<person.size() ; i++){
		person.at(i)->isMarked = false;
	}
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
				vector<string> elems;
				splits(line, elems, ',');
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
					vector<string> elems;
					splits(line, elems, ',');
					if(elems.size()>0)
					{
						for(int j=0; j<elems.size() ; j++){
							//search for the name in the vector and get its pointer
							//and then push to the connection vector
							//person.at(i)->connection.push_back()
							person.at(i)->connection.push_back(find(elems.at(j),true));
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
/**
*	this algo is used in Min cut into 2 groups 
*/
void Network::KargerMinCut(){
	vector< vector<Person* > > p1; // vector of vectors of persons 


}
