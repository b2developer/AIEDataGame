#pragma once
#include "Resource.h"
#include <Windows.h>
#include "Texture.h"

/*
* class TextureResource
* child class of Resource
*
* manages the memory held by a texture and loads/releases this
* memory when neccessary
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class TextureResource : public Resource
{
public:

	aie::Texture* texture; //texture data

	/*
	* TextureResource()
	* default constructor
	*/
	TextureResource() {};

	/*
	* ~TextureResource
	* default destructor
	*/
	~TextureResource() {};
	
	/*
	* operator=
	*
	* assignment overload
	*
	* @param const TextureResource other - the other object to copy from
	* @returns TextureResource - the new object with copied data
	*/
	TextureResource operator=(const TextureResource other);

	/*
	* loadResource
	* overrides Resource's loadResource(char filePath[MAX_PATH])
	*
	* called when the resource is required to 
	* be loaded for use in the game
	*
	* @param char filePath[MAX_PATH] - c-string of the file path containing the resouce to load
	* @returns void
	*/
	void loadResource(char filePath[MAX_PATH]) override;

	/*
	* releaseResource
	* overrides Resource's releaseResource()
	*
	* called when the resource is no longer
	* required to be used in the game
	*
	* @returns void
	*/
	void releaseResource() override;

};