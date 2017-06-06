#pragma once
#include "GameState.h"
#include "PushAction.h"

/*
* class PlayState
* child class of GameState
*
* abstract class for a snapshot of gameplay that can be
* used to actually play the game, pause it and resume it
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class PlayState : public GameState
{
public:

	PushAction* pauseAct; //defined action that pauses the game

	/*
	* PlayState
	* default constructor
	*/
	PlayState() {};

	/*
	* PlayState
	* default destructor
	*/
	~PlayState() {};

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