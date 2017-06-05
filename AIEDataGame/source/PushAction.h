#pragma once
#include "Action.h"
#include "GameState.h"

/*
* class PushAction
* child class of Action
*
* adds the gamestate to the stack
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class PushAction : public Action
{
public:

	GameState* pushed; //gamestate to be added to the stack

	/*
	* PushAction()
	* default constructor
	*/
	PushAction() {};

	/*
	* ~PushAction()
	* virtual function
	* default destructor
	*/
	virtual ~PushAction() {};

	/*
	* execute
	* overrides Action's execute(Application2D* appPtr)
	*
	* adds the stored gamestate to the stack
	*
	* @param Application2D* appPtr - application pointer to run the action through
	* @returns void
	*/
	void execute(Application2D* appPtr) override;
};