#pragma once

//forward delaration
class Application2D;

/*
* class Item
*
* abstract class for all items in a menu state
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Item
{
public:

	/*
	* Item()
	* default constructor
	*/
	Item() {};

	/*
	* ~Item()
	* default destructor
	*/
	~Item() {};

	/*
	* update
	* abstract function
	*
	* simulates one frame of the item
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	virtual void update(Application2D* appPtr, float deltaTime) = 0;

	/*
	* draw
	* abstract function
	*
	* renders the item
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @returns void
	*/
	virtual void draw(Application2D* appPtr) = 0;

};