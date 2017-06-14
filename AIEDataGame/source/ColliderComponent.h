#pragma once
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "LinkedList.h"
#include "AABB.h"

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

	LinkedNode<ColliderComponent*>* thisNode = nullptr; //position in the renderers array in playState

	AABB region; //the shape of the collider
	float mtvBias = 1.0f; //scores the amount of the push that the collider takes, 

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
	* initialise
	* overrides BaseComponent's initialise()
	*
	* initialises the component, only gets called if component is attached to a gameobject
	*
	* @returns void
	*/
	void initialise() override;

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

	/*
	* getGlobalAABB
	*
	* gets the true aabb that the
	* collider is currently occupying
	* by adding the transform to the AABB
	*
	* @returns AABB - the global AABB
	*/
	AABB getGlobalAABB();

};