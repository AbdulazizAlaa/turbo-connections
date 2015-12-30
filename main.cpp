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

// array of pointers to vector Person
vector<Person *> person;

// main method
int main(int argc, char** argv){

	int personCount;
	string line;
	ifstream file;
	file.open("data.txt");

	if(file.is_open()){
		if(getline(file, line))
			personCount = atoi(line.c_str());
		getline(file, line);
		for(int i=0; i<personCount ; i++){
			if(getline(file, line)){
				if(line == ""){
					i--;
					continue;
				}
				//split the line into words
				vector<string> elems;
				splits(line, elems, ',');
				if(elems.size()>0)
				{
					Person *p = new Person(elems.at(0), elems.at(1), elems.at(2), elems.at(3));
					person.push_back(p);
				}
			}
		}
		getline(file, line);
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
						}
					}
				}
			}
		}

		for(int i=0; i<person.size() ; i++){
			cout << person.at(i)->name<<" : " << person.at(i)->title<<" : " << person.at(i)->company<<" : " << person.at(i)->address<< endl;
		}

		file.close();
	}else{
		cout << "Unable to open file" << endl;
	}

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
		if(line.at(j) == ','){
			end = j;
			elems.push_back(line.substr(start, end-start));
			start = end+2;
		}
	}
	elems.push_back(line.substr(start, line.size()-start));

}



