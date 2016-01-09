/*
 * TestSuit.h
 *
 *  Created on: Jan 9, 2016
 *      Author: abdulaziz
 */

#ifndef TESTSUIT_H_
#define TESTSUIT_H_


#include <iostream>
#include <string>
#include "Network.h"

using namespace std;

class TestSuit {
public:
	TestSuit();
	virtual ~TestSuit();

	static void test_nameMatch(Network & n);
	static void test_numMutual();
};

#endif /* TESTSUIT_H_ */
