/*
 * Person.h
 *
 *  Created on: Dec 24, 2015
 *  Author: abdulaziz & Nada
 *
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> //atoi() , 
#include <fstream>
#include <utility> // what does that do ?? plz write the function uses that one
#include <limits> // what does that do ?? plz write the function uses that one
#include <algorithm> // find()

using namespace std;


class Person {
public:
	///////////////////// Constructor and distructor //////////////
	Person(string name, string title, string company, string address); // our constuctor
	
	Person();

	/** distructor **/
	virtual ~Person(); 

	void printDetails();

	string name; //Person's name
	string title; //Person's job title
	string company; //company name
	string address; //Person's address
	/** Connections that person have , it is a vector of pointers to persons **/
	vector<Person *> connection; 
	bool isMarked; //is traversed or not yet

};

#endif /* PERSON_H_ */
