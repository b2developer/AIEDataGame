#pragma once
#include "Item.h"
#include "AABB.h"

/*
* class Button
*
* performs an action when clicked
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Button : public Item
{
public:

	AABB hitbox = AABB(); //the hitbox of the button

	/*
	* Button()
	* default constructor
	*/
	Button() {};

	/*
	* ~Button()
	* default destructor
	*/
	~Button() {};
	
	/*
	* update
	*
	* simulates one frame of the item
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void update(Application2D* appPtr, float deltaTime) override;

	/*
	* draw
	*
	* renders the item
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @returns void
	*/
	void draw(Application2D* appPtr) override;
};