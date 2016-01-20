/*
 * Person.cpp
 *
 *  Created on: Dec 24, 2015
 *  Author: abdulaziz
 */

#include "Person.h"

/** Constructor **/
Person::Person(string name, string title, string company, string address) {
	// TODO Auto-generated constructor stub
	this->name = name;
	this->title = title;
	this->company = company;
	this->address = address;
	this->isMarked = false;
}

Person::Person()
{

}

/** Destructor **/
Person::~Person() {
	// TODO Auto-generated destructor stub
}

/*
 * printing a person details along with his connections
 */
void Person::printDetails(){
	cout << "--Details" << endl;
	cout << "Name : "<< name << endl;
	cout << "Title : " << title << endl;
	cout << "Company : " << company << endl;
	cout << "Address : " << address << endl;
	cout << "--Connections" << endl;
	for(int j=0 ; j<connection.size() ; j++){
		cout <<"Connection " << j << " : " << connection.at(j)->name <<endl;
	}
	cout << endl;
}

