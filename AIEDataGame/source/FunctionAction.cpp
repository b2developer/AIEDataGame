#include "FunctionAction.h"
#include "Application2D.h"

//runs all of the functions
void FunctionAction::execute(Application2D * appPtr)
{
	LinkedList<void(*)(Application2D* appPtr)>::Iterator iter = functions.begin();

	//iterate through the function list
	for (; iter != functions.end(); iter++)
	{
		//run the function
		iter.m_node->value(appPtr);
	}
}
