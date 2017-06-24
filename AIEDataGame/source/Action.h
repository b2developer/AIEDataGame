#pragma once

//forward declaration
class Application2D;

/*
* class Action
*
* base class for objects that perform actions
* on the game when called upon by several different item child objects
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Action
{
public:

	/*
	* Action()
	* default constructor
	*/
	Action() {};

	/*
	* ~Action()
	* virtual function
	* default destructor
	*/
	virtual ~Action() {};

	/*
	* execute
	* abstract function
	* 
	* runs whenever an item associated with it gets called upon
	*
	* @param Application2D* appPtr - pointer to the application to apply the action to
	* @returns void
	*/
	virtual void execute(Application2D* appPtr) = 0;

};