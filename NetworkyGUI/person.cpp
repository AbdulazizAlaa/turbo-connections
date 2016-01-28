#include "person.h"

/** Constructor **/
Person::Person(QString name, QString title, QString company, QString address) {
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
