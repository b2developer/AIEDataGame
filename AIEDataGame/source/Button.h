#pragma once
#include "Item.h"
#include "Action.h"
#include "AABB.h"
#include "TextureResource.h"

//custom enum for button settings
enum class INPUT_MODE
{
	EDGE, //only triggers once when the item is pressed
	CONSTANT, //triggers as long as the item is pressed
};

/*
* class Button
* child class of Item
*
* performs an action when clicked
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Button : public Item
{
public:

	TextureResource* boxTexture = nullptr; //the texture of the button to be drawn
	AABB hitbox = AABB(); //the hitbox of the button
	INPUT_MODE inputMode = INPUT_MODE::EDGE; //the input mode of the button
	Action* action = nullptr; //action to execute when pressed

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