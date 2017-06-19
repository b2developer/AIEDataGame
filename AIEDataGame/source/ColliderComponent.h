#pragma once
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "LinkedList.h"
#include "AABB.h"

//forward declaration
class Application2D;
class ColliderComponent;

//type for colliderss
enum ColliderType
{
	NONE,
	SOLID,
	INVISIBLE,
};



/*
* struct CollisionTuple
*
* data returned from a collision, contains the other collider
* the normal and
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
struct CollisionTuple
{
	ColliderComponent* other; //the other collider component involved in the collision
	Vector2 normal; //direction that the normal occurred in
};



/*
* class ColliderComponent
* child class of BaseComponent
*
* a component that holds a region that can be collided with
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class ColliderComponent : public BaseComponent
{
public:

	LinkedNode<ColliderComponent*>* thisNode = nullptr; //position in the renderers array in playState

	LinkedList<CollisionPair> collisions = LinkedList<CollisionPair>(0); //list of collisions

	AABB region; //the shape of the collider
	float mtvBias = 1.0f; //scores the amount of the push that the collider takes, 

	/*
	* ColliderComponent()
	* default constructor
	*/
	ColliderComponent() {};

	/*
	* ~ColliderComponent()
	* virtual function
	* default destructor
	*/
	virtual ~ColliderComponent() {};

	/*
	* initialise
	* virtual function
	* overrides BaseComponent's initialise()
	*
	* initialises the component, only gets called if component is attached to a gameobject
	*
	* @returns void
	*/
	virtual void initialise() override;

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