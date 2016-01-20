/*
 * Network.h
 *
 *  Created on: Jan 9, 2016
 *      Author: abdulaziz
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include "Person.h"

using namespace std;

class Network {
public:
	Network(string filename);
	virtual ~Network();

	void printNetwork();
	void readFile(string filename);

	void splitNames(string line, vector<string> & elems, char del);
	void splits(string line, vector<string> & elems, char del);

	Person* find(string name , bool exactMatch);
	bool nameMatch(string src , string dst);
	int nameMatchRank(string src , string dst );
	void searchPerson();

	std::pair<int, int> check(string name);
	int numMutual();
	int getMutual(string first, string second);
	vector<pair<string, int> > QueryNameNotExactMatch(string name);
	void KargerMinCut();// karger algo. for min cut 

	//variables
	vector<Person *> person; // array of pointers to vector Person
	int personCount; // no of Persons

};

#endif /* NETWORK_H_ */
