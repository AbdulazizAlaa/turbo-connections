/*
 * main.cpp
 *
 *  Created on: Dec 24, 2015
 *      Author: abdulaziz & Moataz & nada
 */

#include "Person.h"

void splitNames(string line, vector<string> & elems, char del);
void splits(string line, vector<string> & elems, char del);
Person* find(vector<Person *> & p, string name , bool exactMatch);
void test_nameMatch();
void printNetwork(vector<Person *> & p);
void readFile(string filename);
void numMutual(vector<Person *> & p);
void showMenu();
bool nameMatch(string src , string dst);


//variables
vector<Person *> person; // array of pointers to vector Person
int personCount; // no of Persons
string filename = "data.txt"; //file name to read


// main method
int main(int argc, char** argv){

	//read file
	readFile(filename);

	//print the network
	printNetwork(person);
	
	showMenu();

	// testing
	//test_nameMatch();
	return 0;
}

/*
*
*Suggested INTERFACE
*
*/

void showMenu(){

	char q = ' ';

	while(true){
		int press;

		cout<< endl;
		cout << "Press 1: \" Search for a certain person using their name\" " <<endl;
		cout << "Press 2: \" Show number of mutual friends between any 2 people\" "<<endl;
		cin >> press;

		if(press == 1){

		}else if(press == 2){
			numMutual(person);
		}

		cout << "Do you want to quit? (Y/N)" << endl;
		cin >> q;

		if(q == 'y' || q == 'Y'){
			cout << "Return Soon :D" << endl;
			break;
		}
	}
}

/*
*
 * search for a name in the vector of persons
*
 */
Person* find(vector<Person *> & p, string name , bool exactMatch){
	// if we want to find a person with name exactly as written
	if(exactMatch){
		for (int i=0 ; i<p.size() ; i++){
		   if(p.at(i)->name == name){
			  return p.at(i);
		   }
		}
	}else{
		// if we want to find a person with name near to what we written
		for (int i=0 ; i<p.size() ; i++){
		   if(nameMatch(p.at(i)->name,name)){
			  return p.at(i);
		   }
		}
	}

	return NULL;
}

/*
*	search for a PART of a name in vector of persons
*	@param String src (have many sub strings )
*	@param String dst (may many sub strings)
*	@return Boolean True if similarity found and false if not
*/
bool nameMatch(string src , string dst){
	// array of strings contains each string components
	vector<string> SrcElems;
	vector<string> DstElems;

	// spletting the strings with " " space
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
void printNetwork(vector<Person *> & p){

	for(int i=0; i<p.size() ; i++){
		cout << p.at(i)->name<<" : " << p.at(i)->title<<" : " << p.at(i)->company<<" : " << p.at(i)->address<< endl;
		for(int j=0 ; j<p.at(i)->connection.size() ; j++){
			cout <<"connection " << j << " : " << p.at(i)->connection.at(j)->name <<endl;
		}
		cout << endl;
	}
}



/*
*
* check name is found; return confirmation whether it exists or not(ok) and its index in vector(i)
* @param vector<Person *> & p reference to the global vector of persons
* @param string name name to check if it exists in the vector
*/
std::pair<int, int> check(vector<Person *> & p,string name){
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
*
* number of mutual friends
* @param vector<Person *> & p reference to the global vector of persons
*/
void numMutual(vector<Person *> & p)
{
	string first,second;//first: first name, second: second name

	int found=0;///number of mutual friends found
	cout <<"Enter first full name"<<endl;
	cin.ignore();
	getline(cin,first);

	cout <<"Enter second full name"<<endl;
	getline(cin,second);

	std::pair<int, int> firstPerson = check(p,first);
	std::pair<int, int> secondPerson = check(p,second);

	if(firstPerson.first ==0 && secondPerson.first ==1)////first name is not valid
	{
		cout << "Error: " << "First name is not found on the network"<<endl;
		return;
	}
	if(firstPerson.first ==1 && secondPerson.first ==0)/////sec name is not valid
	{
		cout << "Error: " << "Second name is not found on the network"<<endl;
		return;
	}
	if(firstPerson.first ==0 && secondPerson.first ==0)///both names are unvalid
	{
		cout << "Error: " << "Both names are not found on the network"<<endl;
		return;
	}
	if(firstPerson.second == secondPerson.second){
		cout << "Error: " << "Same Person" << endl;
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
}


/*
* splits string on a delimiter
* @param string line string to split into words
* @param vector<string> & elems to keep the splited words
* @param char del delimiter to split on
* */
void splits(string line, vector<string> & elems, char del){
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
void splitNames(string line, vector<string> & elems, char del){
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
void readFile(string filename){
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

void test_nameMatch(){
	int noOfTrue = 0;
	int noOfFalse = 0;
	string n1 = "ahmed mohamed hessuin";
	string n2 = "moataz mahmoud";
	string n3 = "abdulaziz mohamed alaa";
	string n4 = "nada diaa";
	cout<<"\n\n\n/////////////////////// UNIT TESTING //////////////////////////////"<<endl;
	cout<<"//////////////////////////// nameMatch() ///////////////////////"<<endl;

	// testcase 1
	cout<<"input ->> "<<n1<<" |||| ";
	string searchfor1 = "mohamed";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	bool out = nameMatch(n1,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output


	// testcase 2
	cout<<"input ->> "<<n2<<" |||| ";
	searchfor1 = "Moataz mahmoud";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n2,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 3
	cout<<"input ->> "<<n3<<" |||| ";
	searchfor1 = "alaa";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n3,searchfor1);
	if(out == true )
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 4
	cout<<"input ->> "<<n3<<" |||| ";
	searchfor1 = "Moataz Farid";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"0 |||| output :";
	out = nameMatch(n3,searchfor1);
	if(out ==  false)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 4
	cout<<"input ->> "<<n2<<" |||| ";
	searchfor1 = "moataz farid";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n2,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 5
	cout<<"input ->> "<<n2<<" |||| ";
	searchfor1 = "Farid";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"0 |||| output :";
	out = nameMatch(n2,searchfor1);
	if(out == false)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 6
	cout<<"input ->> "<<n2<<" |||| ";
	searchfor1 = "Farid moataz";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n2,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 7
	cout<<"input ->> "<<n4<<" |||| ";
	searchfor1 = "nada";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n4,searchfor1);
	if(out == true )
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 8
	cout<<"input ->> "<<n4<<" |||| ";
	searchfor1 = "nada diAa";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :"; // because it pass nada
	out = nameMatch(n4,searchfor1);
	if(out == true )
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 9
	cout<<"input ->> "<<n4<<" |||| ";
	searchfor1 = "dia";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"0 |||| output :";
	out = nameMatch(n4,searchfor1);
	if(out == false)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 10
	cout<<"input ->> "<<n4<<" |||| ";
	searchfor1 = "z";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"0 |||| output :";
	out = nameMatch(n4,searchfor1);
	if(out == false)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 11
	cout<<"input ->> "<<n3<<" |||| ";
	searchfor1 = "mohamed";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n3,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output


	cout<<"\n\n=====\nTest Result: "<<noOfTrue<<"/"<<noOfFalse+noOfTrue<<" passed \n======\n\n"<<endl;

}

