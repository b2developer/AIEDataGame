#pragma once
#include "GameState.h"
#include "LinkedList.h"
#include "Item.h"

/*
* class MenuState
* child class of GameState
*
* abstract class for a snapshot of a menu that can be
* used to modify options, transition to other menu states or game states etc.
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class MenuState : public GameState
{
public:

	LinkedList<Item*> items;

	/*
	* MenuState
	* default constructor
	*/
	MenuState() {};

	/*
	* MenuState
	* default destructor
	*/
	~MenuState() {};

	/*
	* update
	* overrides GameState's update(float deltaTime)
	*
	* simulates one frame of the gamestate
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void update(Application2D* appPtr, float deltaTime) override;

	/*
	* draw
	* overrides GameState's draw()
	*
	* renders the gamestate
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @returns void
	*/
	void draw(Application2D* appPtr) override;

	/*
	* onEnter
	* overrides GameState's onEnter()
	*
	* called when the gamestate becomes the uppermost gamestate in the stack
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @returns void
	*/
	void onEnter(Application2D* appPtr) override;

	/*
	* onExit
	* overrides GameState's onExit()
	*
	* called when the gamestate is no longer the uppermost gamestate in the stack
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @returns void
	*/
	void onExit(Application2D* appPtr) override;
};