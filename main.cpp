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


using namespace std;

void splits(string line, vector<string> & elems, char del);
Person* find(vector<Person *> & p, string name);
void printNetwork(vector<Person *> & p);
void readFile(string filename);

// array of pointers to vector Person
vector<Person *> person;
int personCount;


// main method
int main(int argc, char** argv){

	//read file
	readFile( "data.txt");

	//print the network
	printNetwork(person);

	return 0;
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
 * search for a name in the vector of persons
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



