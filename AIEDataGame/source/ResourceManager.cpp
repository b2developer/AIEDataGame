#include "ResourceManager.h"

//gets and or creates the singleton pointer
ResourceManager* ResourceManager::getInstance()
{
	static ResourceManager* singleton = nullptr;

	//check if the singleton has been created
	if (singleton == nullptr)
	{
		//create resource manager instance
		singleton = new ResourceManager();
	}

	return singleton;
}

//gets the path of the resource folder
void ResourceManager::initialise()
{
	//get the file name
	char buffer[MAX_PATH];
	ZeroMemory(buffer, sizeof(buffer));

	GetModuleFileName(NULL, buffer, MAX_PATH);

	//find the first backslash
	char* slash = strrchr(buffer, '\\');

	//set it to a null terminator, this tricks the program into thinking that the string ends here
	*slash = '\0';

	char extension[MAX_PATH] = "\\resource\\";

	//add the extension to the buffer
	strcat_s(buffer, extension);

	//copy the buffer to the resourcePath
	strcpy_s(resourcePath, buffer);
}

//loads the resource if it hasn't been loaded already
Resource * ResourceManager::requestResource(ResourceType resourceType, char fileName[MAX_PATH])
{
	ResourceReference ** resourcePtr = loadedContainer.searchFor(fileName);

	//check if the resource has been loaded yet
	if (resourcePtr == nullptr)
	{
		ResourceReference* resourceRef = new ResourceReference();

		//load the correct resource type
		switch (resourceType)
		{
		case ResourceType::TEXTURE: resourceRef->resource = new TextureResource(); break;
		case ResourceType::AUDIO: resourceRef->resource = new SoundResource(); break;
		case ResourceType::TEXT: ; break;
		}

		char resourcePathCopy[MAX_PATH];

		strcpy_s(resourcePathCopy, resourcePath); //copy the path accross to a new variable
		strcat_s(resourcePathCopy, fileName); //add the filename requested to the path

		//tell the resource to load itself
		resourceRef->resource->loadResource(resourcePathCopy);

		//place it in the list
		loadedContainer.insert(fileName, resourceRef);

		//since the resource gets copied into the list, get the true item again
		resourcePtr = loadedContainer.searchFor(fileName);
	}

	(*resourcePtr)->resourceCount++;
	
	return (*resourcePtr)->resource;
}

//frees the resource if there are no longer any users of it
void ResourceManager::releaseResource(char fileName[MAX_PATH])
{
	ResourceReference * resourcePtr = *loadedContainer.searchFor(fileName);

	//check if the resource has been loaded yet
	if (resourcePtr == nullptr)
	{
		return;
	}
	else
	{
		resourcePtr->resourceCount--;

		//release the resource if the resource count falls to 0
		if (resourcePtr->resourceCount == 0)
		{
			delete resourcePtr;
			loadedContainer.remove(fileName);
		}
		
	}

}
