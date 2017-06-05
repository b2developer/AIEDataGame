#pragma once

//forward declaration
class Application2D;

/*
* class Action
*
* base class for actions that can occur when a UI element
* calls upon them, allows switching of states, changing of
* internal values and other specific actions
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
	* virtual function
	*
	* runs the action
	* 
	* @param Application2D* appPtr - application pointer to run the action through
	* @returns void
	*/
	virtual void execute(Application2D* appPtr) = 0;
};