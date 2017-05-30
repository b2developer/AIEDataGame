#include <iostream>
#include <stdio.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Application2D.h"
#include "Log.h"
#include "UnitTest.h"
#include "LinkedList.h"
#include "LinkedTree.h"
#include "KeyList.h"

int main()
{
	_CrtDumpMemoryLeaks(); 
	{
		KeyList<int> keyList1 = KeyList<int>();
		keyList1.insert("double", 4);
		keyList1.insert("banana", 2);
		keyList1.insert("apple", 1);
		keyList1.insert("chocolate", 3);
		keyList1.insert("egg", 5);
		keyList1.insert("zebra", 6);

		keyList1.remove("banana");

		int a = 0;

		std::cout << "\n\n\n\n\n\n";
	}

	_CrtDumpMemoryLeaks();

	LOG->initialise();
	
	if (!UNIT->runTests())
	{
		UNIT->echoFailure();
		return 0;
	}

	RESOURCE_MAN->initialise();

	//create the application
	auto app2D = new Application2D();

	app2D->setVSync(true);
	//app2D->run("AIEDataGame", 1280, 720, false);

	//delete the application
	delete app2D;

	std::cout << "\n\n\n\n\n\n\n";

	return 0;
}