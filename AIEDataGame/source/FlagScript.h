#pragma once
#include "ScriptComponent.h"
#include "ColliderComponent.h"
#include "Vector2.h"
#include "MovementState.h"

//forward declaration of PlayState
class PlayState;

/*
* class FlagScript
* child class of ScriptComponent
*
* a component that gives a gameobject the behaviour of a flag
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class FlagScript : public ScriptComponent
{

public:

	PlayState* playState = nullptr; //pointer to the gamestate that is using this script
	ColliderComponent* collider = nullptr; //pointer to the collider to get collisions from

	/*
	* FlagScript()
	* default constructor
	*/
	FlagScript() {};

	/*
	* ~FlagScript()
	* default destructor
	*/
	~FlagScript() {};

	/*
	* initialise
	* overrides ScriptComponent's initialise()
	*
	* initialises the script, only gets called if script is attached to a gameobject
	*
	* @returns void
	*/
	void initialise() override;

	/*
	* start
	* overrides ScriptComponent's update(Application2D* appPtr, float deltaTime)
	*
	* runs once per frame
	*
	* @param Application2D* appPtr - pointer to the application that called it
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void update(Application2D* appPtr, float deltaTime) override;

};