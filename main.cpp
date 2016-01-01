/*
 * main.cpp
 *
 *  Created on: Dec 24, 2015
 *      Author: abdulaziz & Moataz & nada
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Person.h"
#include <utility>

using namespace std;

void splits(string line, vector<string> & elems, char del);
Person* find(vector<Person *> & p, string name);
void printNetwork(vector<Person *> & p);
void readFile(string filename);
void numMutual(vector<Person *> & p,string first,string second);
void interface();

// array of pointers to vector Person
vector<Person *> person;
int personCount;
string first, second; /////names to get number of mutual friends between them

// main method
int main(int argc, char** argv){

	
	interface();
system("pause");
return 0;
}

/*
*
*Suggested INTERFACE
*
*/

void interface(){
	int press;
	//read file
	readFile( "data.txt");

	//print the network
	printNetwork(person);
	cout<< endl;
	cout << "Press 1: \" Search for a certain person using their name\" " <<endl;
	cout << "Press 2: \" Show number of mutual friends between any 2 people\" "<<endl;
	cin >> press;
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
	switch (press)
	{
	case 1:
		break;
	case 2:
		numMutual(person,first,second);
		break;
	default:
		break;
	}
}


/*
* splits string on a delimiter
*
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
*
 * search for a name in the vector of persons
*
 */
Person* find(vector<Person *> & p, string name){
	for (int i=0 ; i<p.size() ; i++){
	   if(p.at(i)->name == name){
	      return p.at(i);
	   }
	  
	}
}

void printNetwork(vector<Person *> & p){

	//testing the network
	//ouputing every person and its connections
	for(int i=0; i<p.size() ; i++){
		cout << p.at(i)->name<<" : " << p.at(i)->title<<" : " << p.at(i)->company<<" : " << p.at(i)->address<< endl;
		for(int j=0 ; j<p.at(i)->connection.size() ; j++){
			cout <<"connection " << j << " : " << p.at(i)->connection.at(j)->name <<endl;
		}
		cout << endl;
	}
}

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
							person.at(i)->connection.push_back(find(person, elems.at(j)));
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
*check name is found; return confirmation whether it exists or not(ok) and its index in vector(i)
*
*/
std::pair<int, int> check(vector<Person *> & p,string name){
	int ok ;
	int i=0;
	for ( i=0 ; i<p.size() ; i++){
	   if(p.at(i)->name == name){
	      ok = 1;
		  break;
	   }
	   else {
		   ok = 0;
	   }
	}
	return std::make_pair(ok,i);
}

/*
*
 *number of mutual friends
*
*/
void numMutual(vector<Person *> & p,string first,string  second)//first: first name, second: second name
{
	int found=0;///number of mutual friends found
	cout << endl<<"enter first full name"<<endl;
	getline(cin,first);

	cout << endl<<"enter second full name"<<endl;
	getline(cin,second);

	std::pair<int, int> firstPerson = check(p,first);
	std::pair<int, int> secondPerson = check(p,second);
	if(firstPerson.first ==1 && secondPerson.first ==1 )////both names exist
	{
		cout << "Mutual friend(s) are "<<endl;
		for(int i =0;i<p.at(firstPerson.second)->connection.size();i++)///loop through connections of first person
		{
			for(int j =0;j<p.at(secondPerson.second)->connection.size();j++)///loop through connections of second person
			{
				if(p.at(firstPerson.second)->connection.at(i)->name == p.at(secondPerson.second)->connection.at(j)->name)///check if connection->name i equal to connection->name j
				{
					//k++;
					found++;
					cout <<p.at(firstPerson.second)->connection.at(i)->name<<endl;
					//mutuals[k]=p.at(firstPerson.second)->connection.at(i)->name;
					break;
				}
				else {/**do nothing**/} 
			}
		}
	}
	else if(firstPerson.first ==0 && secondPerson.first ==1)////first name is not valid
	{
		cout << "First name is not found on the network"<<endl;
		return;
	}
	else if(firstPerson.first ==1 && secondPerson.first ==0)/////sec name is not valid
	{
		cout << "Second name is not found on the network"<<endl;
		return;
	}
	else if(firstPerson.first ==0 && secondPerson.first ==0)///both names are unvalid
	{
		cout << "Both names are not found on the network"<<endl;
		return;
	}
	///print number of mutual friends
	cout << "Number of mutual friends between "<<first << " and "<<second << " = "<< found<<endl;
}

