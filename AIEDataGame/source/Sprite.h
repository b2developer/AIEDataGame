#pragma once
#include "Item.h"
#include "AABB.h"
#include "TextureResource.h"

/*
* class Sprite
* child class of Item
*
* displays a texture onto a rectangle
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Sprite : public Item
{
public:

	TextureResource* boxTexture = nullptr; //the texture of the sprite to be drawn
	AABB hitbox = AABB(); //the drawing rectangle of the sprite

	/*
	* Sprite()
	* default constructor
	*/
	Sprite() {};

	/*
	* ~Sprite()
	* destructor, releases the box texture
	*/
	~Sprite();

	/*
	* update
	*
	* simulates one frame of the item, does nothing for a sprite
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