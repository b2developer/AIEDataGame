#pragma once

class GameObject; //forward declaration to game object
class Application2D; //forward declaration of the application
class TransformComponent; //forward declaration of the transform component

enum ComponentType
{
	TRANSFORM,
	RENDERER,
	COLLIDER,
	ENTITY,
};

/*
* class BaseComponent
*
* defines a base class for components that can add functionality
* to game objects (associative relationship with game objects)
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class BaseComponent
{
public:

	GameObject* parent = nullptr; //pointer to the holder of this component
	
	/*
	* BaseComponent()
	* default constructor
	*/
	BaseComponent() {};

	/*
	* ~BaseComponent()
	* virtual function
	* default destructor
	*/
	virtual ~BaseComponent() {};

	/*
	* initialise
	* virtual function
	*
	* initialises the component, only gets called if component is attached to a gameobject
	*
	* @returns void
	*/
	virtual void initialise() {};

	/*
	* update
	* virtual function
	*
	* runs once per frame, only gets called if the component is attached to a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called it
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	virtual void update(Application2D* appPtr, float deltaTime) {};
};