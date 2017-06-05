#include "FontResource.h"

//overload the assignment operator
FontResource FontResource::operator=(const FontResource other)
{
	font = other.font;
	return *this;
}

//loads the font
void FontResource::loadResource(char filePath[MAX_PATH])
{
	//delete the font already held if there is one
	if (font != nullptr)
	{
		releaseResource();
	}

	font = new aie::Font(filePath, 64);
}

//deletes the font
void FontResource::releaseResource()
{
	delete font;
	font = nullptr;
}