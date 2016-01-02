/*
 * main.cpp
 *
 *  Created on: Dec 24, 2015
 *      Author: abdulaziz & Moataz & nada
 */
//

#include "Person.h"

void splitNames(string line, vector<string> & elems, char del);
void splits(string line, vector<string> & elems, char del);
/*
 * search for a name in the vector of persons
 */
Person* find(vector<Person *> & p, string name , bool exactMatch);
void test_nameMatch();
void printNetwork(vector<Person *> & p);
void readFile(string filename);
/*
*	Check if a match is found between 2 strings (used in search )
*	@param String src (have many sub strings )
*	@param String dst (may many sub strings)
*	@return Boolean True if similarity found and false if not
*/
bool nameMatch(string src , string dst);

// array of pointers to vector Person
vector<Person *> person;
// no of Persons
int personCount;


// main method
int main(int argc, char** argv){

	//read file
	readFile( "data.txt");

	//print the network
	printNetwork(person);

	cout<<find(person, "mohamed abdulaziz", false);

	// testing
	test_nameMatch();
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
* splits name to search
*
* */
void splitNames(string line, vector<string> & elems, char del){
	int start=0;
	int end=0;
	for(int j=0 ; j<line.size() ;j++){
		if(line.at(j) == del){
			end = j;
			elems.push_back(line.substr(start, end-start));
			start = end+1;
		}
	}
	elems.push_back(line.substr(start, line.size()-start));

}

/*
 * search for a name in the vector of persons
 */
Person* find(vector<Person *> & p, string name , bool exactMatch){
	// if we want to find a person with name exactly as written
	if(exactMatch){
		for (int i=0 ; i<p.size() ; i++){
		   if(p.at(i)->name == name){
			  return p.at(i);
		   }
		}
	}else{
		// if we want to find a person with name near to what we written
		for (int i=0 ; i<p.size() ; i++){
		   if(nameMatch(p.at(i)->name,name)){
			  return p.at(i);
		   }
		}
	}

	return NULL;
}

/*
*	search for a PART of a name in vector of persons
*	@param String src (have many sub strings )
*	@param String dst (may many sub strings)
*	@return Boolean True if similarity found and false if not
*/
bool nameMatch(string src , string dst){
	// array of strings contains each string components
	vector<string> SrcElems;
	vector<string> DstElems;

	// spletting the strings with " " space
	splitNames(src,SrcElems,' ');
	splitNames(dst,DstElems,' ');

	for(int i =0 ; i<SrcElems.size();i++){
		for(int j=0 ; j<DstElems.size(); j++){
			if(SrcElems.at(i)== DstElems.at(j)){
				return true;
			}
		}
	}

	return false;
}


void test_nameMatch(){
	int noOfTrue = 0;
	int noOfFalse = 0;
	string n1 = "ahmed mohamed hessuin";
	string n2 = "moataz mahmoud";
	string n3 = "abdulaziz mohamed alaa";
	string n4 = "nada diaa";
	cout<<"\n\n\n/////////////////////// UNIT TESTING //////////////////////////////"<<endl;
	cout<<"//////////////////////////// nameMatch() ///////////////////////"<<endl;

	// testcase 1
	cout<<"input ->> "<<n1<<" |||| ";
	string searchfor1 = "mohamed";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	bool out = nameMatch(n1,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output


	// testcase 2
	cout<<"input ->> "<<n2<<" |||| ";
	searchfor1 = "Moataz mahmoud";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n2,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 3
	cout<<"input ->> "<<n3<<" |||| ";
	searchfor1 = "alaa";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n3,searchfor1);
	if(out == true )
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 4
	cout<<"input ->> "<<n3<<" |||| ";
	searchfor1 = "Moataz Farid";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"0 |||| output :";
	out = nameMatch(n3,searchfor1);
	if(out ==  false)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 4
	cout<<"input ->> "<<n2<<" |||| ";
	searchfor1 = "moataz farid";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n2,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 5
	cout<<"input ->> "<<n2<<" |||| ";
	searchfor1 = "Farid";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"0 |||| output :";
	out = nameMatch(n2,searchfor1);
	if(out == false)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 6
	cout<<"input ->> "<<n2<<" |||| ";
	searchfor1 = "Farid moataz";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n2,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 7
	cout<<"input ->> "<<n4<<" |||| ";
	searchfor1 = "nada";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n4,searchfor1);
	if(out == true )
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 8
	cout<<"input ->> "<<n4<<" |||| ";
	searchfor1 = "nada diAa";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :"; // because it pass nada
	out = nameMatch(n4,searchfor1);
	if(out == true )
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 9
	cout<<"input ->> "<<n4<<" |||| ";
	searchfor1 = "dia";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"0 |||| output :";
	out = nameMatch(n4,searchfor1);
	if(out == false)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 10
	cout<<"input ->> "<<n4<<" |||| ";
	searchfor1 = "z";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"0 |||| output :";
	out = nameMatch(n4,searchfor1);
	if(out == false)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output

	// testcase 11
	cout<<"input ->> "<<n3<<" |||| ";
	searchfor1 = "mohamed";
	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
	cout<<"1 |||| output :";
	out = nameMatch(n3,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output


	cout<<"\n\n=====\nTest Result: "<<noOfTrue<<"/"<<noOfFalse+noOfTrue<<" passed \n======\n\n"<<endl;

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
							person.at(i)->connection.push_back(find(person, elems.at(j),true));
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
