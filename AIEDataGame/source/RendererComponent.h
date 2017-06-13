#pragma once
#include "BaseComponent.h"
#include "AABB.h"
#include "TextureResource.h"

//forward declaration
class Application2D;

/*
* class RendererComponent
*
* a component that holds a position
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class RendererComponent : public BaseComponent
{
public:

	TextureResource* textureRes; //the texture that the renderer can render
	AABB region; //the region to render to

	/*
	* RendererComponent
	* default constructor
	*/
	RendererComponent() {};

	/*
	* RendererComponent
	* virtual function
	* default destructor
	*/
	virtual ~RendererComponent() {};

	/*
	* render
	* 
	* draws the texture to the screen
	*
	* @param Application2D* appPtr - pointer to the application that will render it
	* @returns void
	*/
	void render(Application2D* appPtr);

};