#pragma once
#include "GameState.h"
#include "Action.h"

/*
* class PushAction
* child class of Action
*
* adds a gamestate to the stack when called upon
* by several different item child objects
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class PushAction : public Action
{
public:

	GameState* pushed = nullptr; //gamestate to push

	/*
	* PushAction()
	* default constructor
	*/
	PushAction() {};

	/*
	* ~PushAction()
	* default destructor
	*/
	~PushAction() {};

	/*
	* execute
	* overrides Action's execute(Application2D* appPtr)
	*
	* runs whenever an item associated with it gets called upon
	* adds the pushed gamestate pointer to the stack
	*
	* Application2D* appPtr - pointer to the application to apply the action to
	* @returns void
	*/
	void execute(Application2D* appPtr) override;

};