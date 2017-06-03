#include <iostream>
#include <stdio.h>

#include "Application2D.h"
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

	RESOURCE_MAN->initialise();

	//create the application
	auto app2D = new Application2D();

	app2D->setVSync(true);
	app2D->run("AIEDataGame", 1280, 720, false);

	//delete the application
	delete app2D;

	return 0;
}