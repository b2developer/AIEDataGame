#pragma once
#include "Resource.h"
#include <Windows.h>
#include "Audio.h"

/*
* class SoundResource
* child class of Resource
*
* manages the memory held by a sound and loads/releases this
* memory when neccessary
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class SoundResource : public Resource
{
public:

	aie::Audio *audio; //audio data

	/*
	* SoundResource()
	* default constructor
	*/
	SoundResource() {};

	/*
	* ~SoundResource
	* default destructor
	*/
	~SoundResource() {};
	
	/*
	* operator=
	*
	* assignment overload
	*
	* @param const SoundResource other - the other object to copy from
	* @returns SoundResource - the new object with copied data
	*/
	SoundResource operator=(const SoundResource other);

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