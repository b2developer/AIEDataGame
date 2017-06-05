#pragma once
#include "Item.h"
#include "Action.h"
#include "LinkedList.h"

/*
* class Timer
* child class of Item
*
* keeps track of time and executes given actions when the time
* runs out. can be executed as an action by other items
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Timer : public Item
{
public:

	LinkedList<Action*> reactions; //list of actions that will take place after the timer has counted down

	float maxTime = 1.0f; //maximum time that the timer can have
	float currentTime = 0.0f; //tracks the current time

	/*
	* Timer()
	* default constructor
	*/
	Timer() {};

	/*
	* ~Timer()
	* default destructor
	*/
	~Timer() {};

	/*
	* begin
	*
	* resets the timer to it's max time
	* this function should be called by a 'Function' action
	*
	* @returns void
	*/
	void begin();

	/*
	* update
	*
	* simulates one frame of the item
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void update(Application2D* appPtr, float deltaTime) override;

	/*
	* draw
	*
	* renders the item, does nothing for this child
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @returns void
	*/
	void draw(Application2D* appPtr) override {};
};