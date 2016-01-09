/*
 * Network.h
 *
 *  Created on: Jan 9, 2016
 *      Author: abdulaziz
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> //atoi() ,
#include <fstream>
#include <utility> // what does that do ?? plz write the function uses that one
#include <limits> // what does that do ?? plz write the function uses that one
#include <algorithm> // find()
#include "Person.h"

using namespace std;

class Network {
public:
	Network(string filename);
	virtual ~Network();

	void printNetwork(vector<Person *> & p);
	void printPersonDetails(Person * p);
	void readFile(string filename);

	void splitNames(string line, vector<string> & elems, char del);
	void splits(string line, vector<string> & elems, char del);
	Person* find(vector<Person *> & p, string name , bool exactMatch);
	bool nameMatch(string src , string dst);
	void searchPerson(vector<Person *> & p);

	std::pair<int, int> check(vector<Person *> & p,string name);
	int numMutual(vector<Person *> & p);
	int getMutual(vector<Person *> & p, string first, string second);
	vector<pair<string, int> > QueryNameNotExactMatch(vector<Person *> & p, string name);

	//variables
	vector<Person *> person; // array of pointers to vector Person
	int personCount; // no of Persons

};

#endif /* NETWORK_H_ */
