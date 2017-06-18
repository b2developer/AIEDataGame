#pragma once
#include "GameObject.h"

//foward declaration of PlayState and Application2D
class PlayState;
class Application2D;

/*
* class Builder
*
* responsible for initialising game objects
* initialises the objects in a way that the construction process
* can be changed through inheritance
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Builder
{

public:

	/*
	* Builder()
	* default constructor
	*/
	Builder() {};

	/*
	* ~Builder()
	* virtual function 
	* default destructor
	*/
	virtual ~Builder() {};

	/*
	* setObject
	* abstract function
	*
	* initialises the gameobject core
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	virtual void setObject(Application2D* appPtr, PlayState* playState, GameObject* gameObject) = 0;

	/*
	* setTransform
	* abstract function
	*
	* creates and initialises a transfrom component for a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	virtual void setTransform(Application2D* appPtr, PlayState* playState, GameObject* gameObject) = 0;

	/*
	* setScript
	* abstract function
	*
	* creates and initialises script components for a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	virtual void setScript(Application2D* appPtr, PlayState* playState, GameObject* gameObject) = 0;

	/*
	* setCollider
	* abstract function
	*
	* creates and initialises a collider component for a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	virtual void setCollider(Application2D* appPtr, PlayState* playState, GameObject* gameObject) = 0;

	/*
	* setRenderer
	* abstract function
	*
	* creates and initialises a renderer component for a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	virtual void setRenderer(Application2D* appPtr, PlayState* playState, GameObject* gameObject) = 0;

	/*
	* setExtension
	* abstract function
	*
	* initialises and sets additional properties of a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	virtual void setExtension(Application2D* appPtr, PlayState* playState, GameObject* gameObject) = 0;

};