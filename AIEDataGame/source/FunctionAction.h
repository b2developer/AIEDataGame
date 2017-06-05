#pragma once
#include "Action.h"
#include "GameState.h"
#include "LinkedList.h"

/*
* class FunctionAction
* child class of Action
*
* called upon by items to run a large amount of actions through
* a list of void function pointers
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class FunctionAction : public Action
{
public:

	LinkedList<void (*)(Application2D* appPtr)> functions; //linked list of function pointers with application arguments

	/*
	* FunctionAction()
	* default constructor
	*/
	FunctionAction() {};

	/*
	* ~FunctionAction()
	* virtual function
	* default destructor
	*/
	virtual ~FunctionAction() {};

	/*
	* execute
	* overrides Action's execute(Application2D* appPtr)
	*
	* runs all stored void function pointers
	*
	* @param Application2D* appPtr - application pointer to run the action through
	* @returns void
	*/
	void execute(Application2D* appPtr) override;
};