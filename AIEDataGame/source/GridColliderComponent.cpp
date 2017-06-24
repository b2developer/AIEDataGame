#include "GridColliderComponent.h"
#include "Application2D.h"
#include "Log.h"
#include "assert.h"

//destructor
GridColliderComponent::~GridColliderComponent()
{
	release();
}

//initialises the grid
void GridColliderComponent::initialise()
{
}

//populates the 2D array with loaded text-file data
void GridColliderComponent::load()
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
					data = new ColliderType*[sizeY];

					//create all of the rows
					for (int k = 0; k < sizeY; k++)
					{
						data[k] = new ColliderType[sizeX];
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
					data[casts - 2][k] = (ColliderType)realNum;
				}

			}

			j = i + 1;

			casts++;

		}

		i++;
	}
}

//turns a char array into its interger representation
int GridColliderComponent::charArrayToInt(char * cArr)
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

//gets a list of colliders that could be colliding with the given region
LinkedList<GridPair> GridColliderComponent::getNeighbourColliders(AABB otherRegion)
{
	Vector2 offset = region.min_; //get the offset from the origin of the entire grid
	Vector2 size = region.max_ - region.min_; //get the size of one of the squares in the grid

	AABB relRegion = otherRegion;

	//get the region relative to the bottom-left corner
	relRegion.min_ += offset * -1.0f;
	relRegion.max_ += offset * -1.0f;

	//scale the region by the size
	relRegion.min_.x /= size.x;
	relRegion.min_.y /= size.y;

	relRegion.max_.x /= size.x;
	relRegion.max_.y /= size.y;

	AABB iterRegion = relRegion;

	//clamp the minumum iterator values to above 0
	iterRegion.min_.x = iterRegion.min_.x < 0 ? 0 : iterRegion.min_.x; 
	iterRegion.min_.y = iterRegion.min_.y < 0 ? 0 : iterRegion.min_.y;
	
	//clamp the maximum iterator values to below the maximum size
	iterRegion.max_.x = iterRegion.max_.x >= sizeX - 1 ? sizeX - 1 : iterRegion.max_.x;
	iterRegion.max_.y = iterRegion.max_.y >= sizeY - 1 ? sizeY - 1 : iterRegion.max_.y;

	LinkedList<GridPair> gridList = LinkedList<GridPair>(0);

	//2D array iterator
	for (int y = (int)floorf(iterRegion.min_.y); y <= (int)ceilf(iterRegion.max_.y); y++)
	{
		for (int x = (int)floorf(iterRegion.min_.x); x <= (int)ceilf(iterRegion.max_.x); x++)
		{
			if (data[sizeY - y - 1][x] == ColliderType::NONE)
			{
				continue;
			}

			//get the actual region contained by the sub-region
			GridPair gridPair = GridPair();

			AABB subRegion = AABB();

			subRegion.min_ = offset + Vector2(size.x * x, size.y * y);
			subRegion.max_ = offset + Vector2(size.x * x, size.y * y) + size;

			gridPair.region = subRegion;
			gridPair.data = data[sizeY - y - 1][x];

			gridList.pushBack(gridPair);
		}
	}

	return gridList;

}

//releases all data held by the component
void GridColliderComponent::release()
{
	//release the resource
	if (textRes != nullptr)
	{
		RESOURCE_MAN->releaseResource(textRes->resourceName);
	}

	textRes = nullptr;

	//delete the rows of the 2D array
	for (int i = 0; i < sizeY; i++)
	{
		delete[] data[i];
	}

	delete[] data;
}
