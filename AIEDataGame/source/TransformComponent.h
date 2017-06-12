#pragma once
#include "BaseComponent.h"
#include "Vector2.h"

/*
* class TransformComponent
*
* a component that holds a position
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class TransformComponent : public BaseComponent
{
public:

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

};