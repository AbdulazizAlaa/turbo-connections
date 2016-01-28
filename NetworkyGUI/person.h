#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> //atoi() ,
#include <fstream>
#include <utility> // what does that do ?? plz write the function uses that one
#include <limits> // what does that do ?? plz write the function uses that one
#include <algorithm> // find()
#include <queue>
#include <map>

#include <QString>
#include <QStringList>
using namespace std;

class Person
{
public:
    ///////////////////// Constructor and distructor //////////////
    Person(QString name, QString title, QString company, QString address); // our constuctor
    Person();

    /** distructor **/
    virtual ~Person();

    QString name; //Person's name
    QString title; //Person's job title
    QString company; //company name
    QString address; //Person's address
    /** Connections that person have , it is a vector of pointers to persons **/
    vector<Person *> connection;
    bool isMarked; //is traversed or not yet
};

#endif // PERSON_H
