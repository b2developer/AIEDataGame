#pragma once
#include "Resource.h"
#include <Windows.h>

const int MAX_FILE = 10000;

/*
* class TextFileResource
* child class of Resource
*
* manages the memory held by a text file and loads/releases this
* memory when neccessary
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class TextFileResource : public Resource
{
public:

	char stream[MAX_FILE]; //data of the text file

	/*
	* TextFileResource()
	* default constructor
	*/
	TextFileResource() {};

	/*
	* ~TextFileResource
	* default destructor
	*/
	~TextFileResource() {};

	/*
	* operator=
	*
	* assignment overload
	*
	* @param const TextFileResource other - the other object to copy from
	* @returns TextFileResource - the new object with copied data
	*/
	TextFileResource operator=(const TextFileResource other);

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