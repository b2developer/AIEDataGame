#include "TextureResource.h"

//loads the texture
void TextureResource::loadResource(char filePath[MAX_PATH])
{
	//delete the texture already held if there is one
	if (texture != nullptr)
	{
		releaseResource();
	}
	
	texture = new aie::Texture(filePath);
}

//deletes the texture
void TextureResource::releaseResource()
{
	delete texture;
	texture = nullptr;
}