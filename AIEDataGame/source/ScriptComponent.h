#pragma once
#include "BaseComponent.h"
#include "LinkedList.h"

//forward declaration
class Application2D;

/*
* class ScriptComponent
*
* a component that serves as an abstract base for custom scripts
* that serve purposes not covered by the core components (collider, renderer...)
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class ScriptComponent : public BaseComponent
{

public:

	LinkedNode<ScriptComponent*>* thisNode = nullptr; //position in the scripts array in playState

	/*
	* ScriptComponent
	* default constructor
	*/
	ScriptComponent() {};

	/*
	* ScriptComponent
	* virtual function
	* default destructor
	*/
	virtual ~ScriptComponent() {};

	/*
	* initialise
	* virtual function
	* overrides BaseComponent's initialise()
	*
	* initialises the component, only gets called if component is attached to a gameobject
	*
	* @returns void
	*/
	virtual void initialise() override {};

	/*
	* start
	* virtual function
	* overrides BaseComponent's update(Application2D* appPtr, float deltaTime)
	*
	* runs once when the object is created
	*
	* @param Application2D* appPtr - pointer to the application that called it
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	virtual void update(Application2D* appPtr, float deltaTime) override {};

};