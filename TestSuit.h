/*
 * TestSuit.h
 *
 *  Created on: Jan 9, 2016
 *      Author: abdulaziz
 */

#ifndef TESTSUIT_H_
#define TESTSUIT_H_

#include "Network.h"
#include "Person.h"

class TestSuit {
public:
	TestSuit();
	virtual ~TestSuit();

	static void test_nameMatch(Network & n);
	static void test_numMutual(Network & n);
	static void test_QueryNameNotExactMatch(Network & n);

};

#endif /* TESTSUIT_H_ */
