#pragma once
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "TextureResource.h"

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

	TransformComponent* transform;
	TextureResource* texture;

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

};