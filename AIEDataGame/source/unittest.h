#pragma once
#include <iostream>
#include <vector>
#include "assert.h"

#include "Log.h"
#include "LinkedList.h"
#include "LinkedTree.h"
#include "KeyList.h"

#define UNIT UnitTester::getInstance()

/*
* class UnitTester
*
* a singleton class that tests implemented solutions for logical errors
* and will throw it's own errors based on conducted logical tests
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class UnitTester
{
public:

	/*
	* getInstance
	*
	* gets the pointer to the Log singleton, creates
	* the singleton if it doesn't exist already
	*
	* @returns static UnitTester* - the singleton pointer
	*/
	static UnitTester* getInstance();

	/*
	* testEqual
	* template
	*
	* tests if a vector and LinkedList are equal
	*
	* @param std::vector<T>& correctList - reference to the vector
	* @param LinkedList<T>& otherList - reference to the LinkedList to compare it with
	* @returns bool - indicating whether or not they are the same
	*/
	TEMPLATE
	bool testEqual(std::vector<T>& correctList, LinkedList<T>& otherList)
	{
		size_t size1 = correctList.size();
		size_t size2 = otherList.size;

		//test if the sizes match
		if (size1 != size2)
		{
			return false;
		}

		//check the elements by iterating through them pairwise
		for (int i = 0; i < (int)size1; i++)
		{
			if (correctList[i] != otherList[i])
			{
				return false;
			}
		}

		return true;
	}

	/*
	* testEqual
	* template
	*
	* tests if two LinkedLists are equal
	*
	* @param LinkedList<T>& list1 - reference to the 1st LinkedList
	* @param LinkedList<T>& list2 - reference to the 2nd LinkedList
	* @returns bool - indicating whether or not they are the same
	*/
	TEMPLATE
	bool testEqual(LinkedList<T>& list1, LinkedList<T>& list2)
	{
		size_t size1 = list1.size;
		size_t size2 = list2.size;

		//test if the sizes match
		if (size1 != size2)
		{
			return false;
		}

		//check the elements by iterating through them pairwise
		for (int i = 0; i < (int)size1; i++)
		{
			if (list1[i] != list2[i])
			{
				return false;
			}
		}

		return true;
	}

	/*
	* echoFailure
	*
	* asserts an error notifying the failure of a test
	* echos the details of the failed test to the console
	* also writes the details to a log file
	*
	* @returns void
	*/
	void echoFailure();

	/*
	* runTests
	*
	* tests all implemented data structures for logical errors
	* the 
	a
	*/
	bool runTests();

private:

	/*
	* UnitTester
	* default constructor
	*/
	UnitTester() {};

	/*
	* UnitTester
	* default destructor
	*/
	~UnitTester() {};
};