#pragma once
#include "LinkedList.h"
#include "BaseComponent.h"

/*
* class GameObject
*
* an entity that can be updated during the game, has no 
* function on it's own. Components can be added to it to give
* it some behaviour
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class GameObject
{
public:

	LinkedList<BaseComponent*> components;

	/*
	* GameObject
	* default constructor
	*/
	GameObject() {};

	/*
	* ~GameObject
	* default destructor
	*/
	~GameObject() {};
};