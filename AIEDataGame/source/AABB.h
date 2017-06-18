#pragma once
#include "MathLibrary.h"

/*
* class AABB
*
* defines a non-rotating box in 2D space that can be collided with
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class AABB
{
public:

	Vector2 min_ = Vector2(); //bottom left corner
	Vector2 max_ = Vector2(); //top right corner


	/*
	* AABB()
	* default constructor
	*/
	AABB() {};

	/*
	* AABB(Vector2 _min, Vector2 _max)
	* constructor, assigns the internal values for the corners
	*
	* @param _min - the bottom left corner
	* @param _max - the top right corner
	*/
	AABB(Vector2 _min, Vector2 _max) : min_(_min), max_(_max) {};

	/*
	* ~AABB()
	* default destructor
	*/
	~AABB() {};

	/*
	* move
	* 
	* shifts the AABB's centre
	*
	* @param Vector2 movement - the offset to apply to the corners
	* @returns void
	*/
	void move(Vector2 movement)
	{
		//apply the offset to the corners
		min_ += movement;
		max_ += movement;
	}
	
};