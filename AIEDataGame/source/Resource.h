#pragma once
#include <Windows.h>

/*
* class Resource
*
* abstract class for anything that can be loaded into memory
* eg. sound, texture, text file
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Resource
{
public:

	/*
	* Resource()
	* default constructor
	*/
	Resource() {};

	/*
	* ~Resource
	* virtual function
	* default destructor
	*/
	virtual ~Resource() {};

	/*
	* loadResource
	* abstract function
	*
	* called when the resource is required to 
	* be loaded for use in the game
	*
	* @param char filePath[MAX_PATH] - c-string of the file path containing the resource to load
	* @returns void
	*/
	virtual void loadResource(char filePath[MAX_PATH]) = 0;

	/*
	* releaseResource
	* abstract function
	*
	* called when the resource is no longer
	* required to be used in the game
	*
	* @returns void
	*/
	virtual void releaseResource() = 0;

};