/*
 * main.cpp
 *
 *  Created on: Dec 24, 2015
 *      Author: abdulaziz & Moataz & nada
 */

#include "Person.h"
#include "TestSuit.h"
#include "Network.h"

void showMenu(Network & n);

string filename = "data.txt"; //file name to read

// main method
int main(int argc, char** argv){

	//Building the network and reading the file
	Network n(filename);

	//n.printNetwork();

	showMenu(n);
	return 0;
}

/*
* shows a menu to make use of one of the availble algorithms implemented
*/
void showMenu(Network & n){

	string q = " ";

	while(true){
		string choice;

		cout<< endl;
		cout <<"###########################################################"<<endl;
		cout << "Press 1: \" Search for a certain person using their name\" " <<endl;
		cout << "Press 2: \" Show number of mutual friends between any 2 people\" "<<endl;
		cout << "Press 3: \" Show suggested friends between two users\" " << endl;
		cout << "Press 4: \" Apply MinCut\" "<<endl;
		cout << "Press 5: \" Testing\" "<<endl;

		getline(cin, choice);

		if(choice == "1"){
			//search for a person
			n.searchPerson();
		}else if(choice == "2"){
			//get number of mutual friends between two persons
			n.numMutual();
		}else if(choice == "3"){
			//get suggested friends list
			n.suggestedFriends();
		}else if(choice == "5"){
			//testing
			TestSuit t;
			t.test_nameMatch(n);
			t.test_numMutual(n);
			//t.test_QueryNameNotExactMatch(n);
		}else if(choice == "4"){
			n.KargerMinCut();
		}else{
			//error
			cout << "Error: Enter a valid choice." << endl;
		}

		cout << "Do you want to quit? (Y/N)" << endl;
		getline(cin, q);
		if(q == "y" || q == "Y"){
			cout << "Return Soon :D" << endl;
			break;
		}
	}
}
