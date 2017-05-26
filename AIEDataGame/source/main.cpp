#include <iostream>
#include <stdio.h>

#include "Log.h"
#include "UnitTest.h"
#include "LinkedList.h"
#include "LinkedTree.h"
#include "KeyList.h"

int main()
{

	LOG->initialise();
	
	if (!UNIT->runTests())
	{
		UNIT->echoFailure();
		return 0;
	}

	return 0;
}