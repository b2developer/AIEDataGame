#pragma once
#include "Builder.h"
#include "GameObject.h"

//foward declaration of the application and playstate
class Application2D;
class PlayState;

/*
* class Director
*
* manages the process of creating game objects and components
* in those game objects through a builder
*
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Director
{

public:
	
	Builder* builder = nullptr; //polymorphic pointer to the builder that will initialise the gameobjects

	/*
	* Director()
	* default constructor
	*/
	Director() {};

	/*
	* ~Director()
	* default destructor
	*/
	~Director() {};

	/*
	* buildGameObject
	*
	* gets a gameobject from the pool or factory,
	* then calls upon the stored builder to initialise
	* to game object and give it all the required components
	*
	* @param Application2D* appPtr - pointer to the application that called this function (indirectly through a contained playstate)
	* @param PlayState* playState - pointer to the playstate that called this function
	* @returns GameObject* - pointer to the newly created game object
	*/
	GameObject* buildGameObject(Application2D* appPtr, PlayState* playState);

};