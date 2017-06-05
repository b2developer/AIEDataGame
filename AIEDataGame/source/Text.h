#pragma once
#include "Item.h"
#include "Action.h"
#include "Vector2.h"
#include "FontResource.h"

const int MAX_TEXT = 500;

/*
* class Text
* child class of Item
*
* displays text at a specific location
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Text : public Item
{
public:

	char message[MAX_TEXT]; //string to display
	FontResource* font = nullptr; //the font of the text to be rendered
	Vector2 origin = Vector2(1, 1); //the bottom-left corner of the text
	Vector2 scale = Vector2(1, 1); //scale multiplier

	/*
	* Text()
	* default constructor
	*/
	Text() {};

	/*
	* ~Text()
	* default destructor
	*/
	~Text() {};

	/*
	* update
	*
	* simulates one frame of the item, does nothing for this child
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void update(Application2D* appPtr, float deltaTime) override {};

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