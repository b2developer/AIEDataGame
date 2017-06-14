#include "Factory.h"

//gets and or creates the singleton pointer
Factory* Factory::getInstance()
{
	static Factory* singleton = nullptr;

	//check if the singleton has been created
	if (singleton == nullptr)
	{
		//create factory instance
		singleton = new Factory();
	}

	return singleton;
}
