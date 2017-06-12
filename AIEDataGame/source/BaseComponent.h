#pragma once

class GameObject; //forward decleration to game object

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
	
	/*
	* BaseComponent
	* default constructor
	*/
	BaseComponent() {};

	/*
	* BaseComponent
	* default destructor
	*/
	~BaseComponent() {};

	/*
	* initialise
	* virtual function
	*
	* initialises the component, only gets called if component is  attached to a gameobject
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
	* @returns void
	*/
	virtual void update() {};
};