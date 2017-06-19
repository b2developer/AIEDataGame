#include "GridColliderComponent.h"

void GridColliderComponent::initialise()
{
}

//gets a list of colliders that could be colliding with the given region
LinkedList<GridPair> GridColliderComponent::getNeighbourColliders(AABB otherRegion)
{
	Vector2 offset = region.min_; //get the offset from the origin of the entire grid
	Vector2 size = region.max_ - region.min_; //get the size of one of the squares in the grid

	AABB relRegion = AABB();

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
	iterRegion.max_.x = iterRegion.max_.x >= sizeX ? sizeX- 1 : iterRegion.max_.x;
	iterRegion.max_.y = iterRegion.max_.y >= sizeY ? sizeY - 1 : iterRegion.max_.y;

	LinkedList<GridPair> gridList = LinkedList<GridPair>(0);

	//2D array iterator
	for (int y = (int)floorf(iterRegion.min_.y); y < (int)ceilf(iterRegion.max_.y); y++)
	{
		for (int x = (int)floorf(iterRegion.min_.x); x < (int)ceilf(iterRegion.max_.x); x++)
		{
			//get the actual region contained by the sub-region
			GridPair gridPair = GridPair();

			AABB subRegion = AABB();

			subRegion.min_ = offset + Vector2(size.x * x, size.y * y);
			subRegion.max_ = offset + Vector2(size.x * x, size.y * y) + size;

			gridPair.region = subRegion;
			gridPair.data = data[y][x];

			gridList.pushBack(gridPair);
		}
	}

	return gridList;

}
