#include "TextFileResource.h"
#include <iostream>
#include <fstream>

//overload the assignment operator
TextFileResource TextFileResource::operator=(const TextFileResource other)
{
	strcpy_s(stream, other.stream); //copy the c-string
	return *this;
}

//loads the texture
void TextFileResource::loadResource(char filePath[MAX_PATH])
{
	ZeroMemory(stream, MAX_FILE);

	std::ifstream textFile;

	//open textFile for reading
	textFile.open(filePath);

	int len = 0;

	//while there is still data to read
	while (!textFile.eof())
	{
		//stream the contents to the string
		char app[MAX_FILE];

		ZeroMemory(app, MAX_FILE);

		textFile >> app;

		//copy the temp char array onto the permanant one
		strcat_s(stream, app);

		//get the new length of the string by finding the closest null terminator
		while (stream[len] != '\0' || len >= MAX_FILE)
		{
			len++;
		}

		//add a new line (they don't get streamed)
		stream[len] = '\n';

		len++;

		stream[len] = '\0';
	}

	//close the textFile
	textFile.close();
}

//deletes the texture
void TextFileResource::releaseResource()
{
	
}