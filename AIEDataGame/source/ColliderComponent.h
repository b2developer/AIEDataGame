#pragma once
#include "BaseComponent.h"
#include "AABB.h"
#include "TextureResource.h"

//forward declaration
class Application2D;

/*
* class ColliderComponent
*
* a component that holds a region that can be collided with
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class ColliderComponent : public BaseComponent
{
public:

	AABB region; //the shape of the collider

	/*
	* ColliderComponent
	* default constructor
	*/
	ColliderComponent() {};

	/*
	* ColliderComponent
	* virtual function
	* default destructor
	*/
	virtual ~ColliderComponent() {};

	/*
	* add
	*
	* adds a vector to the region contained
	* by the collider component
	*
	* @param Vector2 position
	* @returns void
	*/
	void add(Vector2 position);

};