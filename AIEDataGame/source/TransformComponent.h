#pragma once
#include "BaseComponent.h"
#include "LinkedList.h"
#include "Vector2.h"

/*
* class TransformComponent
* child class of BaseComponent
*
* a component that holds a position
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class TransformComponent : public BaseComponent
{
public:

	LinkedNode<TransformComponent*>* thisNode = nullptr; //position in the transforms array in playState

	Vector2 position; //the vector help by the transform

	/*
	* TransformComponent
	* default constructor
	*/
	TransformComponent() {};

	/*
	* TransformComponent
	* virtual function
	* default destructor
	*/
	virtual ~TransformComponent() {};

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
	* setRelative
	*
	* sets this transform component as if the origin was represented
	* by the transform component passed into it
	*
	* @param TransformComponent* other - pointer to the other transform component that is representing the origin
	* @returns void
	*/
	void setRelative(TransformComponent other);

	/*
	* setRelative
	*
	* sets this transform component as if the origin was represented
	* by the Vector2 passed into it
	*
	* @param Vector2* other - pointer to the Vector2 that is representing the origin
	* @returns void
	*/
	void setRelative(Vector2 other);

};