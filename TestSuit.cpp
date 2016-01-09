/*
 * TestSuit.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: abdulaziz
 */

#include "TestSuit.h"

TestSuit::TestSuit() {
	// TODO Auto-generated constructor stub

}

TestSuit::~TestSuit() {
	// TODO Auto-generated destructor stub
}

// testing name match function
static void test_nameMatch(){
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
