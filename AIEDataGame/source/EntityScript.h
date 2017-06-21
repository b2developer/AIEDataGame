#pragma once
#include "ScriptComponent.h"
#include "ColliderComponent.h"
#include "Vector2.h"

/*
* class EntityScript
* child class of ScriptComponent
*
* a component that gives a gameobject realtime movement
* capabilities, with the ability to change these movements
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class EntityScript : public ScriptComponent
{

public:

	ColliderComponent* collider = nullptr; //pointer to the collider to get collisions from
	Vector2 velocity = Vector2(0,0); //movement in units per second
	Vector2 gravity = Vector2(0, -1.8f); //acceleration of gravity per second

	/*
	* EntityScript()
	* default constructor
	*/
	EntityScript() {};

	/*
	* ~EntityScript()
	* default destructor
	*/
	~EntityScript() {};

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