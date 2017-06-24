#include "GridRendererComponent.h"
#include "Application2D.h"
#include "Log.h"
#include "assert.h"

//destructor
GridRendererComponent::~GridRendererComponent()
{
	release();
}

//initialises the grid
void GridRendererComponent::initialise()
{

}

//populates the 2D array with loaded text-file data
void GridRendererComponent::load()
{
	int casts = 0; //how many times has the c-string been converted into a int?

	int i = 0; //iterating through the full c-string
	int j = 0; //remembering the lettter that last contained a new line
	char s = textRes->stream[i]; //current character of the full c-string

	char builder[MAX_FILE];

	//search through the text file c-string
	while (s != '\0')
	{
		s = textRes->stream[i];

		if (s == ',' || s == '\n')
		{
			//copy the sub-string at j to the builder
			strcpy_s(builder, textRes->stream + j);

			builder[i - j] = '\0';

			if (casts < 2) //the number is one of the first length definers for the 2D array
			{
				int num = charArrayToInt(builder);

				//X and then Y
				if (casts == 0) //the x size
				{
					sizeX = num;
				}
				else if (casts == 1) //the y size
				{
					sizeY = num;

					//both of the size variables have been defined, reserve memory for the array
					data = new TileType*[sizeY];

					//create all of the rows
					for (int k = 0; k < sizeY; k++)
					{
						data[k] = new TileType[sizeX];
					}
				}
			}
			else //the number is the data for the grid
			{
				//i - j is where the builder c-string ends
				for (int k = 0; k < i - j; k++)
				{
					int charNum = (int)builder[k]; //get the ascii number of the char at 'k'

					//ascii number must be between 48 and 57 if it is a numeral
					ASSERT(charNum >= 48, "converting char to int applied to non-numeral");
					ASSERT(charNum <= 57, "converting char to int applied to non-numeral");

					int realNum = charNum - 48; //convert ascii number to real number

					//casts represents the amount of commas and newlines found, in
					//the file format the first two represent the size of the upcoming
					//array data, so subtract 2 to get the first index in the 2D array
					data[casts - 2][k] = (TileType)realNum;
				}

			}

			j = i + 1;

			casts++;

		}

		i++;
	}
}

//turns a char array into its interger representation
int GridRendererComponent::charArrayToInt(char * cArr)
{
	int i = 0; //iterator
	int b = 0; //the number that will get built up

	//repeat until a null terminator is encountered
	while (cArr[i] != '\0')
	{
		int charNum = (int)cArr[i]; //cast the character to the ascii number

		//ascii number must be between 48 and 57 if it is a numeral
		ASSERT(charNum >= 48, "converting char to int applied to non-numeral");
		ASSERT(charNum <= 57, "converting char to int applied to non-numeral");

		int realNum = charNum - 48; //convert ascii number to real number

		b += realNum; //add the digit
		b *= 10; //shift the digit to the left

		i++; //increment the iterator

	}

	b /= 10; //erase the placeholder zero

	return b;
}

//renders the entire grid
void GridRendererComponent::render(Application2D* appPtr, Vector2 cameraOffset)
{
	
	Vector2 length = singularRegion.max_ - singularRegion.min_;
	Vector2 renderLength = renderRegion.max_ - renderRegion.min_;
	Vector2 full = Vector2((float)atlasRes->texture->getWidth(), (float)atlasRes->texture->getHeight());

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			int x = (int)data[i][j];

			//don't draw the tile if it is invisible
			if (x == TileType::SKIP)
			{
				continue;
			}

			x--;

			//the ratio between the full width and height of the texture and the specified region of one block
			float ratioX = full.x / length.x;
			float ratioY = full.y / length.y;

			//turning a single number into UV coordinates
			float U = (x % (int)(ratioX)) / ratioX;
			float V = ((int)floorf(x / ratioX)) / ratioY;

			AABB trueRegion = AABB();

			trueRegion.min_ = parent->transform->position + Vector2(renderLength.x * j, renderLength.y * (sizeY - i - 1)) - cameraOffset;
			trueRegion.max_ = parent->transform->position + Vector2(renderLength.x * j, renderLength.y * (sizeY - i - 1)) + renderLength - cameraOffset;

			//set the rect to the correct coordinates to render the block
			appPtr->m_renderer2D->setUVRect(U + uvEpsilon, V + uvEpsilon, 1 / ratioX - uvEpsilon * 2.0f, 1 / ratioY - uvEpsilon * 2.0f);

			appPtr->m_renderer2D->drawSprite(atlasRes->texture, trueRegion.min_.x * appPtr->m_screen.x, trueRegion.min_.y * appPtr->m_screen.y, renderLength.x * appPtr->m_screen.x, renderLength.y * appPtr->m_screen.y, 0.0f, 1.0f, 0, 0);
		}
	}

	//reset the UV rect
	appPtr->m_renderer2D->setUVRect(0, 0, 1, 1);
}

//releases all data held by the component
void GridRendererComponent::release()
{
	//release the resources used by the renderer
	if (textRes != nullptr)
	{
		RESOURCE_MAN->releaseResource(textRes->resourceName);
	}

	if (atlasRes != nullptr)
	{
		RESOURCE_MAN->releaseResource(atlasRes->resourceName);
	}

	textRes = nullptr;
	atlasRes = nullptr;


	//delete the rows of the 2D array
	for (int i = 0; i < sizeY; i++)
	{
		delete[] data[i];
	}

	delete[] data;
}
