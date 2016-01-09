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

//testing of mutual friends
void TestSuit::test_numMutual(Network & n){
	int nFalse = 0;
	int nTrue = 0;

	string n1 = "Mohamed Shoukry";		string n11 = "Ahmed Hemaly";
	string n3 = "Mohamed Abdulaziz ";	string n33 = "Ahmed Hemaly";
	string n4 = "Yomna Gad";			string n44 = "Ahmed Mohamed";
	string n5 = "Mostafa Fahmy";		string n55 = "Yomna Gad";
	string n6 = "Yomna Gad";			string n66 = "Ahmed Dia";
	string n7 = "Nada Dia";				string n77 = "Moataz Farid";
	string n8 = "Moataz Farid";			string n88 = "Mostafa Fahmy";
	string n9 = "Mohamed Abdulaziz";	string n99 = "Mohamed Abdulaziz";
	cout<<"\n\n\n/////////////////////// UNIT TESTING //////////////////////////////"<<endl;
	cout<<"//////////////////////////// numMutual() ///////////////////////"<<endl;

	///////test case 1
	cout <<"Test case 1:: "<< "input: " << n1 << " & " << n11 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n1 << " and "<<n11 << " = "<< "1"<<endl;
	int out= n.getMutual(n1, n11) ;
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out == 1){
		nTrue++;
	}
	else nFalse++;

	///////test case 2
	cout <<"Test case 2:: "<< "input: " << n11 << " & " << n1 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n11 << " and "<<n1 << " = "<< "1"<<endl;
	out = n.getMutual(n11, n1);
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out == 1){
		nTrue++;
	}
	else nFalse++;

	///////test case 3
	////Mohamed Abdulaziz has space at the end..
	cout <<"Test case 3 " << "input: " << n3 << " & " << n33 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n3 << " and "<<n33 << " = "<< "0"<<endl;
	out = n.getMutual(n3, n33);
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out ==0){
		nTrue++;
	}
	else nFalse++;

	///////test case 4
	////first name is not in the network
	cout <<"Test case 4 "<< "input: " << n4 << " & " << n44 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n4 << " and "<<n44 << " = "<< "0"<<endl;
	out = n.getMutual(n4, n44);
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out ==0){
		nTrue++;
	}
	else nFalse++;

	///////test case 5
	////2nd name is not in the network
	cout <<"Test case 5 "<< "input: " << n5 << " & " << n55 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n5 << " and "<<n55 << " = "<< "0"<<endl;
	out = n.getMutual(n5, n55);
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out ==0){
		nTrue++;
	}
	else nFalse++;

	///////test case 6
	////both names are not on the network
	cout <<"Test case 6 "<< "input: " << n6 << " & " << n66 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n6 << " and "<<n66 << " = "<< "0"<<endl;
	out = n.getMutual(n6, n66);
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out ==0){
		nTrue++;
	}
	else nFalse++;

	///////test case 7
	////no mutual friends between them
	cout <<"Test case 7 "<< "input: " << n7 << " & " << n77 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n7 << " and "<<n77 << " = "<< "0"<<endl;
	out = n.getMutual(n7, n77);
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out ==0){
		nTrue++;
	}
	else nFalse++;

	///////test case 8
	cout <<"Test case 8 "<< "input: " << n8 << " & " << n88 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n8 << " and "<<n88 << " = "<< "2"<<endl;
	out = n.getMutual(n8, n88);
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out ==2){
		nTrue++;
	}
	else nFalse++;

	///////test case 9
	cout <<"Test case 9 "<< "input: " << n9 << " & " << n99 <<endl;
	cout <<"EXPECTED||" << "Number of mutual friends between "<<n9 << " and "<<n99 << " = "<< "0"<<endl;
	out = n.getMutual(n9, n99);
	cout <<"Actual output = " << out <<"\n"<<endl;
	if (out ==0){
		nTrue++;
	}
	else nFalse++;

	cout << "True cases = " << nTrue << " of total = "<< nTrue+nFalse<<endl;
}


/*
 * Needs to be fixed
 * QueryNameNotExactMatch function no more returns a vector of srings
 * it returns a vector of pair<string, int> int is position of this name in the person array
 */
// testing of QueryNameNotExactMatch
//void TestSuit::test_QueryNameNotExactMatch(Network & n){
//	cout<<"//////////////////////////// Start Testing ///////////////////////////////"<<endl;
//	cout<<"//////////////////////////// test_QueryNameNotExactMatch /////////////////"<<endl;
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
//	vec = n.QueryNameNotExactMatch(i);
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
//	vec = n.QueryNameNotExactMatch(i);
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
//	vec = n.QueryNameNotExactMatch(i);
//	find(vec.begin(), vec.end(), expected)!= vec.end()?(found=true):found=false;
//	found==false?count++:found=true;
//
//	cout<<"search:"<<i<<"\t expectedSearch:"<<expected<<"\tExpectedOutput:0"<<"\tOutput:"<<found<<endl;
//	//////////////////////////////////////////
//	// testcase 4
//
//	i = "Mohamed Abdulazi";
//	expected = "Mohamed Abdulaziz";
//	vec = n.QueryNameNotExactMatch(i);
//	find(vec.begin(), vec.end(), expected)!= vec.end()?(found=true):found=false;
//	found==true?count++:found=false;
//
//	cout<<"search:"<<i<<"\t expectedSearch:"<<expected<<"\tExpectedOutput:1"<<"\tOutput:"<<found<<endl;
//	//////////////////////////////////////////
//	// testcase 5
//
//	i = "ccc";
//	expected = "";
//	vec = n.QueryNameNotExactMatch(i);
//	vec.size()>0?(found=true):found=false;
//	found==false?count++:found=true;
//
//	cout<<"search:"<<i<<"\t expectedSearch:"<<expected<<"\tExpectedOutput:0"<<"\tOutput:"<<found<<endl;
//	//////////////////////////////////////////
//	cout<<"### FinalResults ####"<<endl;
//	cout<<"Passed test "<<count<<"/5"<<endl;
//}


// testing name match function
void TestSuit::test_nameMatch(Network & n){
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
	bool out = n.nameMatch(n1,searchfor1);
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
	out = n.nameMatch(n2,searchfor1);
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
	out = n.nameMatch(n3,searchfor1);
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
	out = n.nameMatch(n3,searchfor1);
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
	out = n.nameMatch(n2,searchfor1);
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
	out = n.nameMatch(n2,searchfor1);
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
	out = n.nameMatch(n2,searchfor1);
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
	out = n.nameMatch(n4,searchfor1);
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
	out = n.nameMatch(n4,searchfor1);
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
	out = n.nameMatch(n4,searchfor1);
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
	out = n.nameMatch(n4,searchfor1);
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
	out = n.nameMatch(n3,searchfor1);
	if(out == true)
		noOfTrue++;
	else
		noOfFalse++;
	cout <<out<<endl; // print output


	cout<<"\n\n=====\nTest Result: "<<noOfTrue<<"/"<<noOfFalse+noOfTrue<<" passed \n======\n\n"<<endl;

}
