#pragma once
#include "Resource.h"
#include <Windows.h>
#include "Font.h"

/*
* class FontResource
* child class of Resource
*
* manages the memory held by a font and loads/releases this
* memory when neccessary
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class FontResource : public Resource
{
public:

	aie::Font* font; //font data

	/*
	* FontResource()
	* default constructor
	*/
	FontResource() {};

	/*
	* ~FontResource
	* default destructor
	*/
	~FontResource() {};

	/*
	* operator=
	*
	* assignment overload
	*
	* @param const FontResource other - the other object to copy from
	* @returns FontResource - the new object with copied data
	*/
	FontResource operator=(const FontResource other);

	/*
	* loadResource
	* overrides Resource's loadResource(char filePath[MAX_PATH])
	*
	* called when the resource is required to
	* be loaded for use in the game
	*
	* @param char filePath[MAX_PATH] - c-string of the file path containing the resource to load
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