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

	//print the network
	n.printNetwork(n.person);
	
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
		cout << "Press 1: \" Search for a certain person using their name\" " <<endl;
		cout << "Press 2: \" Show number of mutual friends between any 2 people\" "<<endl;
		cout << "Press 3: \" Testing\" "<<endl;

		getline(cin, choice);

		if(choice == "1"){
			//search for a person
			n.searchPerson(n.person);
		}else if(choice == "2"){
			//get number of mutual friends between two persons
			n.numMutual(n.person);
		}
		else if(choice == "3"){
			//testing
			//TestSuit t;
			//t.test_nameMatch();
			//test_nameMatch();
			//test_numMutual();
			//test_QueryNameNotExactMatch();
		}else{
			//error
			cout << "Error: Enter a valid choice." << endl;
		}

		cout << "Do you want to quit? (Y/N)" << endl;
		cin.ignore();
		getline(cin, q);

		if(q == "y" || q == "Y"){
			cout << "Return Soon :D" << endl;
			break;
		}
	}
}

//// testing name match function
//void test_nameMatch(){
//	int noOfTrue = 0;
//	int noOfFalse = 0;
//	string n1 = "ahmed mohamed hessuin";
//	string n2 = "moataz mahmoud";
//	string n3 = "abdulaziz mohamed alaa";
//	string n4 = "nada diaa";
//	cout<<"\n\n\n/////////////////////// UNIT TESTING //////////////////////////////"<<endl;
//	cout<<"//////////////////////////// nameMatch() ///////////////////////"<<endl;
//
//	// testcase 1
//	cout<<"input ->> "<<n1<<" |||| ";
//	string searchfor1 = "mohamed";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"1 |||| output :";
//	bool out = nameMatch(n1,searchfor1);
//	if(out == true)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//
//	// testcase 2
//	cout<<"input ->> "<<n2<<" |||| ";
//	searchfor1 = "Moataz mahmoud";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"1 |||| output :";
//	out = nameMatch(n2,searchfor1);
//	if(out == true)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 3
//	cout<<"input ->> "<<n3<<" |||| ";
//	searchfor1 = "alaa";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"1 |||| output :";
//	out = nameMatch(n3,searchfor1);
//	if(out == true )
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 4
//	cout<<"input ->> "<<n3<<" |||| ";
//	searchfor1 = "Moataz Farid";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"0 |||| output :";
//	out = nameMatch(n3,searchfor1);
//	if(out ==  false)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 4
//	cout<<"input ->> "<<n2<<" |||| ";
//	searchfor1 = "moataz farid";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"1 |||| output :";
//	out = nameMatch(n2,searchfor1);
//	if(out == true)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 5
//	cout<<"input ->> "<<n2<<" |||| ";
//	searchfor1 = "Farid";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"0 |||| output :";
//	out = nameMatch(n2,searchfor1);
//	if(out == false)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 6
//	cout<<"input ->> "<<n2<<" |||| ";
//	searchfor1 = "Farid moataz";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"1 |||| output :";
//	out = nameMatch(n2,searchfor1);
//	if(out == true)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 7
//	cout<<"input ->> "<<n4<<" |||| ";
//	searchfor1 = "nada";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"1 |||| output :";
//	out = nameMatch(n4,searchfor1);
//	if(out == true )
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 8
//	cout<<"input ->> "<<n4<<" |||| ";
//	searchfor1 = "nada diAa";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"1 |||| output :"; // because it pass nada
//	out = nameMatch(n4,searchfor1);
//	if(out == true )
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 9
//	cout<<"input ->> "<<n4<<" |||| ";
//	searchfor1 = "dia";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"0 |||| output :";
//	out = nameMatch(n4,searchfor1);
//	if(out == false)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 10
//	cout<<"input ->> "<<n4<<" |||| ";
//	searchfor1 = "z";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"0 |||| output :";
//	out = nameMatch(n4,searchfor1);
//	if(out == false)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//	// testcase 11
//	cout<<"input ->> "<<n3<<" |||| ";
//	searchfor1 = "mohamed";
//	cout<<"search for -> "<<searchfor1<<" |||| expected :"; // print testcase
//	cout<<"1 |||| output :";
//	out = nameMatch(n3,searchfor1);
//	if(out == true)
//		noOfTrue++;
//	else
//		noOfFalse++;
//	cout <<out<<endl; // print output
//
//
//	cout<<"\n\n=====\nTest Result: "<<noOfTrue<<"/"<<noOfFalse+noOfTrue<<" passed \n======\n\n"<<endl;
//
//}

////testing of mutual friends
//void test_numMutual(){
//	int nFalse = 0;
//	int nTrue = 0;
//
//	string n1 = "Mohamed Shoukry";		string n11 = "Ahmed Hemaly";
//	string n3 = "Mohamed Abdulaziz ";	string n33 = "Ahmed Hemaly";
//	string n4 = "Yomna Gad";			string n44 = "Ahmed Mohamed";
//	string n5 = "Mostafa Fahmy";		string n55 = "Yomna Gad";
//	string n6 = "Yomna Gad";			string n66 = "Ahmed Dia";
//	string n7 = "Nada Dia";				string n77 = "Moataz Farid";
//	string n8 = "Moataz Farid";			string n88 = "Mostafa Fahmy";
//	string n9 = "Mohamed Abdulaziz";	string n99 = "Mohamed Abdulaziz";
//	cout<<"\n\n\n/////////////////////// UNIT TESTING //////////////////////////////"<<endl;
//	cout<<"//////////////////////////// numMutual() ///////////////////////"<<endl;
//
//	///////test case 1
//	cout <<"Test case 1:: "<< "input: " << n1 << " & " << n11 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n1 << " and "<<n11 << " = "<< "1"<<endl;
//	int out=getMutual(person, n1, n11) ;
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out == 1){
//		nTrue++;
//	}
//	else nFalse++;
//
//	///////test case 2
//	cout <<"Test case 2:: "<< "input: " << n11 << " & " << n1 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n11 << " and "<<n1 << " = "<< "1"<<endl;
//	out = getMutual(person, n11, n1);
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out == 1){
//		nTrue++;
//	}
//	else nFalse++;
//
//	///////test case 3
//	////Mohamed Abdulaziz has space at the end..
//	cout <<"Test case 3 " << "input: " << n3 << " & " << n33 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n3 << " and "<<n33 << " = "<< "0"<<endl;
//	out = getMutual(person, n3, n33);
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out ==0){
//		nTrue++;
//	}
//	else nFalse++;
//
//	///////test case 4
//	////first name is not in the network
//	cout <<"Test case 4 "<< "input: " << n4 << " & " << n44 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n4 << " and "<<n44 << " = "<< "0"<<endl;
//	out = getMutual(person, n4, n44);
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out ==0){
//		nTrue++;
//	}
//	else nFalse++;
//
//	///////test case 5
//	////2nd name is not in the network
//	cout <<"Test case 5 "<< "input: " << n5 << " & " << n55 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n5 << " and "<<n55 << " = "<< "0"<<endl;
//	out = getMutual(person, n5, n55);
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out ==0){
//		nTrue++;
//	}
//	else nFalse++;
//
//	///////test case 6
//	////both names are not on the network
//	cout <<"Test case 6 "<< "input: " << n6 << " & " << n66 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n6 << " and "<<n66 << " = "<< "0"<<endl;
//	out = getMutual(person, n6, n66);
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out ==0){
//		nTrue++;
//	}
//	else nFalse++;
//
//	///////test case 7
//	////no mutual friends between them
//	cout <<"Test case 7 "<< "input: " << n7 << " & " << n77 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n7 << " and "<<n77 << " = "<< "0"<<endl;
//	out = getMutual(person, n7, n77);
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out ==0){
//		nTrue++;
//	}
//	else nFalse++;
//
//	///////test case 8
//	cout <<"Test case 8 "<< "input: " << n8 << " & " << n88 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n8 << " and "<<n88 << " = "<< "2"<<endl;
//	out = getMutual(person, n8, n88);
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out ==2){
//		nTrue++;
//	}
//	else nFalse++;
//
//	///////test case 9
//	cout <<"Test case 9 "<< "input: " << n9 << " & " << n99 <<endl;
//	cout <<"EXPECTED||" << "Number of mutual friends between "<<n9 << " and "<<n99 << " = "<< "0"<<endl;
//	out = getMutual(person, n9, n99);
//	cout <<"Actual output = " << out <<"\n"<<endl;
//	if (out ==0){
//		nTrue++;
//	}
//	else nFalse++;
//
//	cout << "True cases = " << nTrue << " of total = "<< nTrue+nFalse<<endl;
//}

// testing of QueryNameNotExactMatch
//void test_QueryNameNotExactMatch(){
//	cout<<"//////////////////////////// Start Testing ///////////////////////////////"<<endl;
//	cout<<"//////////////////////////// test_QueryNameNotExactMatch /////////////////"<<endl;
//	vector<Person *> &p = person;
//	string i;
//	string expected;
//	vector<pair<string, int> > vec ;
//	bool found;
//	int count=0;
//
//	//testcase 1
//
//	i = "Moataz";
//	expected = "Moataz Farid";
//	vec = QueryNameNotExactMatch(p,i);
//	find(vec.begin(), vec.end(), expected)!= vec.end()?(found=true):found=false;
//	found==true?count++:found=false;
//
//	cout<<"search:"<<i<<"\t expectedSearch:"<<expected<<"\tExpectedOutput:1"<<"\tOutput:"<<found<<endl;
//	//////////////////////////////////////////
//
//	// testcase 2
//
//	i = "Mohamed";
//	expected = "Mohamed Abdulaziz";
//	vec = QueryNameNotExactMatch(p,i);
//	find(vec.begin(), vec.end(), expected)!= vec.end()?(found=true):found=false;
//	found==true?count++:found=false;
//
//	cout<<"search:"<<i<<"\t expectedSearch:"<<expected<<"\tExpectedOutput:1"<<"\tOutput:"<<found<<endl;
//	//////////////////////////////////////////
//
//	// testcase 3
//
//	i = "oataz";
//	expected = "Moataz Farid";
//	vec = QueryNameNotExactMatch(p,i);
//	find(vec.begin(), vec.end(), expected)!= vec.end()?(found=true):found=false;
//	found==false?count++:found=true;
//
//	cout<<"search:"<<i<<"\t expectedSearch:"<<expected<<"\tExpectedOutput:0"<<"\tOutput:"<<found<<endl;
//	//////////////////////////////////////////
//	// testcase 4
//
//	i = "Mohamed Abdulazi";
//	expected = "Mohamed Abdulaziz";
//	vec = QueryNameNotExactMatch(p,i);
//	find(vec.begin(), vec.end(), expected)!= vec.end()?(found=true):found=false;
//	found==true?count++:found=false;
//
//	cout<<"search:"<<i<<"\t expectedSearch:"<<expected<<"\tExpectedOutput:1"<<"\tOutput:"<<found<<endl;
//	//////////////////////////////////////////
//	// testcase 5
//
//	i = "ccc";
//	expected = "";
//	vec = QueryNameNotExactMatch(p,i);
//	vec.size()>0?(found=true):found=false;
//	found==false?count++:found=true;
//
//	cout<<"search:"<<i<<"\t expectedSearch:"<<expected<<"\tExpectedOutput:0"<<"\tOutput:"<<found<<endl;
//	//////////////////////////////////////////
//	cout<<"### FinalResults ####"<<endl;
//	cout<<"Passed test "<<count<<"/5"<<endl;
//}
