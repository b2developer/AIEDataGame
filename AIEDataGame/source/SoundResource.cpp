#include "SoundResource.h"

//overload the assignment operator
SoundResource SoundResource::operator=(const SoundResource other)
{
	audio = other.audio;
	return *this;
}

//loads the audio
void SoundResource::loadResource(char filePath[MAX_PATH])
{
	//delete the audio already held if there is one
	if (audio != nullptr)
	{
		releaseResource();
	}
	
	audio = new aie::Audio(filePath);
}

//deletes the audio
void SoundResource::releaseResource()
{
	delete audio;
	audio = nullptr;
}