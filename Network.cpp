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

/*
* search for a name in the vector of persons
* @param string name person name to search for
* @param bool exactMatch true to search for the name as a block
* @param vector<Person *> & p reference to the global vector of persons
*/
/*
 * TO-DO
 * it is not working right. here is a sample of test cases that go wrong
 * - Mohamed Shoukry ==gives==> Mohamed Abdulaziz. althogh thier exists Mohamed Shoukry
 * - Farid Moataz ==gives==> Moataz Farid. this i don't know if should be true or false
 * - when the function finds more than one target should prompt the user which one he really needs
 * and then prints its details.
 * 		= so you have three situations:
 * 			1 - it is an exact match 100% equal to the stored name so return that person.
 * 			2 - it is not an exact match but it is the closet match found and there is only one so return that person.
 * 			3 - it is not an exact match but there are more than one with some similarities
 * 			so prompt user to chose which one he wants in numbered list fashion and he should choose a number.
 */
Person* Network::find(vector<Person *> & p, string name , bool exactMatch){
	// if we want to find a person with name exactly as written
	if(exactMatch){
		for (int i=0 ; i<p.size() ; i++){
		   if(p.at(i)->name == name){
			  return p.at(i);
		   }
		}
	}else{// if we want to find a person with name near to what we written
		// it wil return first somehow exact name
		for (int i=0 ; i<p.size() ; i++){
		   if(nameMatch(p.at(i)->name,name)){

			  return p.at(i);
		   }
		}
	}

	return NULL;
}
/**
* search for a name in the vector of persons and store that match in a vector of strings
* @param string name person name to search for
* @param bool exactMatch true to search for the name as a block
* @param vector<Person *> & p reference to the global vector of persons
* @return vector of Strings have the full names of peop
*/

vector<pair<string, int> > Network::QueryNameNotExactMatch(vector<Person *> & p, string name){
	// if we want to find a person with name near to what we written
	// it wil return a vector of persons somehow exact name

	vector<pair<string, int> > vNameMatch ; // the vector where found names are stored

	for (int i=0 ; i<p.size() ; i++){
		if(nameMatch(p.at(i)->name,name)){
			vNameMatch.push_back(make_pair(p.at(i)->name, i));
		}
	}
	return vNameMatch;
}

/*
*	search for a PART of a name in vector of persons
*	@param String src (have many sub strings )
*	@param String dst (may many sub strings)
*	@return Boolean True if similarity found and false if not
*/
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

/*
 * prints the graph
 * every person details and his/her connections
 * @param vector<Person *> & p reference to the global vector of persons
 */
void Network::printNetwork(vector<Person *> & p){

	for(int i=0; i<p.size() ; i++){
		cout << "person " << i << endl;
		printPersonDetails(p.at(i));
	}
}

/*
 * printing a person details along with his connections
 * @param Person * p reference to a person
 */
void Network::printPersonDetails(Person * p){
	cout << "--Details" << endl;
	cout << "Name : "<< p->name << endl;
	cout << "Title : " << p->title << endl;
	cout << "Company : " << p->company << endl;
	cout << "Address : " << p->address << endl;
	cout << "--Connections" << endl;
	for(int j=0 ; j<p->connection.size() ; j++){
		cout <<"Connection " << j << " : " << p->connection.at(j)->name <<endl;
	}
	cout << endl;
}

/*
 * prompts the user to get the name
 * of the person he/she wants to search for
 * @param vector<Person *> & p reference to the vector of person
 */
void Network::searchPerson(vector<Person *> & p){
	cout << "Enter name to search for:" << endl;
	string name ;
	getline(cin, name);
	vector<pair<string, int> > temp = QueryNameNotExactMatch(p, name);
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
		//printPersonDetails(find(p,temp.at(n-1).first,true));
		printPersonDetails(p.at(temp.at(n-1).second));
	}
}

/*
*
* check name is found; return confirmation whether it exists or not(ok) and its index in vector(i)
* @param vector<Person *> & p reference to the global vector of persons
* @param string name name to check if it exists in the vector
*/
std::pair<int, int> Network::check(vector<Person *> & p,string name){
	int ok ;
	int i=0;

	Person * temp = find(p, name, false);
	if(temp == NULL){
		ok = 0;
	}else{
		ok = 1;
		for ( i=0 ; i<p.size() ; i++){
			if(p.at(i)->name == temp->name){
				ok = 1;
				break;
			}
		}
	}

	return std::make_pair(ok,i);
}

/*
* returns the number of mutual friends between two persons
* @param vector<Person *> & p reference to the global vector of persons
* @param string first name of first person
* @param string second name of second person
* @return int number of mutual friends between two persons
*/
int Network::getMutual(vector<Person *> & p, string first, string second){

	int found=0;///number of mutual friends found

	std::pair<int, int> firstPerson = check(p,first);
	std::pair<int, int> secondPerson = check(p,second);

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
		for(int i =0;i<p.at(firstPerson.second)->connection.size();i++)///loop through connections of first person
		{
			for(int j =0;j<p.at(secondPerson.second)->connection.size();j++)///loop through connections of second person
			{

				if(p.at(firstPerson.second)->connection.at(i)->name == p.at(secondPerson.second)->connection.at(j)->name)///check if connection->name i equal to connection->name j
				{
					found++;
					cout <<p.at(firstPerson.second)->connection.at(i)->name<<endl;
					break;
				}
			}
		}
	}

	///print number of mutual friends
	cout << "Number of mutual friends between "<<p.at(firstPerson.second)->name << " and "<<p.at(secondPerson.second)->name << " = "<< found<<endl;
	return found;
}

/*
* prompts the user to get the names of the two persons
* he/she wants to know number of mutual friends between
* @param vector<Person *> & p reference to the global vector of persons
* @return int number of mutual friends between two persons
*/
int Network::numMutual(vector<Person *> & p)
{
	string first,second;//first: first name, second: second name

	cout <<"Enter first full name"<<endl;
	cin.ignore();
	getline(cin,first);

	cout <<"Enter second full name"<<endl;
	getline(cin,second);

	return getMutual(p, first, second);

}


/*
* splits string on a delimiter
* @param string line string to split into words
* @param vector<string> & elems to keep the splited words
* @param char del delimiter to split on
* */
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


/*
* splits name to search
* @param string line string to split into words
* @param vector<string> & elems to keep the splited words
* @param char del delimiter to split on
* */
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

/*
 * Reads data file and creates person vector
 * also builds the graph
 * @param string filename data file to read
 */
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
							person.at(i)->connection.push_back(find(person, elems.at(j),true));
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

