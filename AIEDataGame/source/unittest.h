#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

#include "Log.h"
#include "LinkedList.h"
#include "LinkedTree.h"
#include "KeyList.h"

#define UNIT UnitTester::getInstance()



/*
* ASSERT_T
*  
* tests a boolean expression, does nothing if it
* evaluates true, throws an error and a log message
* if it evaluates to false
*
* @param bool condition - the boolean expression to evaluate
* @param char display[MAX_MESSAGE] - the message to display if the evaluation is false
* @returns void
*/
#define ASSERT_T(condition, display)								\
do																	\
{ 																	\
	bool b_condition = (bool)condition;								\
																	\
	if (!b_condition)												\
	{																\
		char message[MAX_MESSAGE] = "Assertion Failed: Line: ";		\
		char lineNum[MAX_MESSAGE / 4];								\
																	\
																	\
		sprintf_s(lineNum, "%d", __LINE__);							\
																	\
		strcat_s(message, lineNum);									\
		strcat_s(message, ", Error: ");								\
		strcat_s(message, display);									\
																	\
		std::cout << message << '\n';								\
																	\
		LOG->write(message);										\
		throw;														\
	}																\
} while (false)														\



/*
* ASSERT
*
* wrapper function for the real assert function
* explicitly converts the condition to a bool before
* passing it to the assert function
*
* @param bool condition - the boolean expression to evaluate
* @param char display[MAX_MESSAGE] - the message to display if the evaluation is false
* @returns void
*/
#define ASSERT(condition, display)									\
do																	\
{																	\
	ASSERT_T((bool)(condition), display);							\
}																	\
while(false)														\



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