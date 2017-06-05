#pragma once
#include "Action.h"
#include "GameState.h"

/*
* class PopAction
* child class of Action
*
* removes gamestates from the stack
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class PopAction : public Action
{
public:

	unsigned int layers = 0;

	/*
	* PopAction()
	* default constructor
	*/
	PopAction() {};

	/*
	* ~PopAction()
	* virtual function
	* default destructor
	*/
	virtual ~PopAction() {};

	/*
	* execute
	* overrides Action's execute(Application2D* appPtr)
	*
	* removes a specific amount of gamestates from the stack
	*
	* @param Application2D* appPtr - application pointer to run the action through
	* @returns void
	*/
	void execute(Application2D* appPtr) override;
};