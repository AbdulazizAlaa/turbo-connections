/*
 * Person.h
 *
 *  Created on: Dec 24, 2015
 *      Author: abdulaziz & Nada
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
	Person(string name, string title, string company, string address);
	virtual ~Person();
//private:
	string name;
	string title;
	string company;
	string address;
	vector<Person *> connection;

};

#endif /* PERSON_H_ */
