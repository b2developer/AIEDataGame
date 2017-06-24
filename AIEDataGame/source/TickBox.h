#pragma once
#include "Item.h"
#include "Action.h"
#include "AABB.h"
#include "TextureResource.h"
#include "Button.h"

/*
* class TickBox
* child class of Item
*
* performs an action when clicked
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class TickBox : public Item
{
public:

	TextureResource* falseTexture = nullptr; //the texture of the tick box while its off
	TextureResource* trueTexture = nullptr; //the texture of the tick box while its on

	AABB hitbox = AABB(); //the hitbox of the button
	INPUT_MODE inputMode = INPUT_MODE::EDGE; //the input mode of the button

	bool state = false; //state of the tick box

	/*
	* TickBox()
	* default constructor
	*/
	TickBox() {};

	/*
	* ~TickBox()
	* destructor, releases the false and true textures
	*/
	~TickBox();

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