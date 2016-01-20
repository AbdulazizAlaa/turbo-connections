/*
 * Network.h
 *
 *  Created on: Jan 9, 2016
 *      Author: abdulaziz
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include "Person.h"

using namespace std;

class Network {
public:
	/*
	 * constructor
	 * takes filename and calls readFile funtion to read the file and build network
	 * @param string filename to read network from
	 */
	Network(string filename);
	virtual ~Network();

	/*
	 * prints the graph
	 * every person details and his/her connections
	 */
	void printNetwork();
	/*
	 * Reads data file and creates person vector
	 * also builds the graph
	 * @param string filename data file to read
	 */
	void readFile(string filename);

	/*
	* splits name to search
	* @param string line string to split into words
	* @param vector<string> & elems to keep the splited words
	* @param char del delimiter to split on
	* */
	void splitNames(string line, vector<string> & elems, char del);
	/*
	* splits string on a delimiter
	* @param string line string to split into words
	* @param vector<string> & elems to keep the splited words
	* @param char del delimiter to split on
	* */
	void splits(string line, vector<string> & elems, char del);

	/*
	* search for a name in the vector of persons
	* @param string name person name to search for
	* @param bool exactMatch true to search for the name as a block
	*/
	/*
	 * TO-DO
	 * it is not working right. here is a sample of test cases that go wrong
	 * - Mohamed Shoukry ==gives==> Mohamed Abdulaziz. althogh thier exists Mohamed Shoukry
	 * - Farid Moataz ==gives==> Moataz Farid. this i don't know if should be true or false
	 * - when the function finds more than one target should prompt the user which one he really needs
	 * and then prints its details.
	 * 		= so you have three situations:
	 * 			1 - it is an exact match 100% equal to the stored name so return that person.
	 * 			2 - it is not an exact match but it is the closet match found and there is only one so return that person.
	 * 			3 - it is not an exact match but there are more than one with some similarities
	 * 			so prompt user to chose which one he wants in numbered list fashion and he should choose a number.
	 */
	Person* find(string name , bool exactMatch);
	/*
	*	search for a PART of a name in vector of persons
	*	@param String src (have many sub strings )
	*	@param String dst (may many sub strings)
	*	@return Boolean True if similarity found and false if not
	*/
	bool nameMatch(string src , string dst);
	/*//////////////// NOT CURRENTLY USED
	*	search for a PART of a name in vector of persons
	*	rank indicate the no of strings match
	*	@param String src (have many sub strings )
	*	@param String dst (may many sub strings)
	*	@return int return the rank of the match and zero if not match
	*/
	int nameMatchRank(string src , string dst );
	/*
	 * prompts the user to get the name
	 * of the person he/she wants to search for
	 */
	void searchPerson();

	/*
	*
	* check name is found; return confirmation whether it exists or not(ok) and its index in vector(i)
	* @param string name to check if it exists in the vector
	*/
	std::pair<int, int> check(string name);
	/*
	* prompts the user to get the names of the two persons
	* he/she wants to know number of mutual friends between
	* @return int number of mutual friends between two persons
	*/
	int numMutual();
	/*
	* returns the number of mutual friends between two persons
	* @param string first name of first person
	* @param string second name of second person
	* @return int number of mutual friends between two persons
	*/
	int getMutual(string first, string second);
	/**
	* search for a name in the vector of persons and store that match in a vector of strings
	* @param string name person name to search for
	* @return vector of pair<string, int> have the full names of persons who are close to the query name.
	* int being the position of this name in the person vector
	*/
	vector<pair<string, int> > QueryNameNotExactMatch(string name);

	/*
	 * get a list of suggested friends using the critria
	 * that the link between them is no more than 5 person
	 * they work for the same company
	 * @param string name name of person to get suggests for
	 */
	int getSuggestedFriends(string name);

	/*
	 * prompt user to get the name of person or user
	 * then gets the list of suggested friends using getSuggestedFriends func
	 */
	int suggestedFriends();

	/*
	 * searches for the person with that name
	 * if there are no matches: prints a clarifying message
	 * else if there is only one matching person: it prints
	 * else: prompt user to get best matching name he wants
	 */
	int getExactName(string name);

	/*
	 * recursively find friends of friends to a defined limit
	 * @param Person * p reference to the person that you are processing now
	 * @param int count current count how far this friend from the user
	 * @param int limit the max length of how far this friend from the user
	 * @param string preConn name of the previous connection
	 * @param vector<Person *> & suggests contains valid suggests conforming to the cratria
	 * @param string company company name to compare suggests with
	 */
	void recurseFriends(vector<Person *> & suggests, Person * p, string preConn, string company, int count, int limit);

	//variables
	vector<Person *> person; // array of pointers to vector Person
	int personCount; // no of Persons

};

#endif /* NETWORK_H_ */
