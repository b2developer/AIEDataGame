#pragma once

//singleton macro
#define FACT Factory::getInstance()

//template macro
#define TEMPLATE template<typename T>

/*
* class Factory
*
* a singleton class that controls the creation of objects
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Factory
{

public:

	/*
	* getInstance
	*
	* gets the pointer to the Factory singleton, creates
	* the singleton if it doesn't exist already
	*
	* @returns static Factory* - the singleton pointer
	*/
	static Factory* getInstance();

	/*
	* createObject
	* template
	*
	* creates a new object of the specified type
	*
	* @returns T* - pointer to the new object
	*/
	TEMPLATE
	T* createObject()
	{
		return new T();
	}


private:

	//hide the constructor and destructor

	/*
	* Factory
	* default constructor
	*/
	Factory() {};

	/*
	* ~Factory
	* default destructor
	*/
	~Factory() {}

};
