#pragma once

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



