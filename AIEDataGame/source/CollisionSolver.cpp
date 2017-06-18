#include "CollisionSolver.h"

//gets and or creates the singleton pointer
CollisionSolver* CollisionSolver::getInstance()
{
	static CollisionSolver* singleton = nullptr;

	//check if the singleton has been created
	if (singleton == nullptr)
	{
		//create collision solver instance
		singleton = new CollisionSolver();
	}

	return singleton;
}

//collision test between an AABB and a point
Collision CollisionSolver::testCollision(AABB aabb, Vector2 point)
{
	//is the point inside two ranges formed by the min and max points
	if (aabb.max_.x > point.x && aabb.min_.x < point.x)
	{
		if (aabb.max_.y > point.y && aabb.min_.y < point.y)
		{
			Vector2 seperation = Vector2();

			//get the movement required to bring to point to the four edges of the AABB
			float leftSep = aabb.min_.x - point.x;
			float rightSep = aabb.max_.x - point.x;

			float upSep = aabb.max_.y - point.y;
			float downSep = aabb.min_.y - point.y;

			//which x direction has the smallest seperation
			if (ABS(leftSep) < ABS(rightSep))
			{
				seperation.x = leftSep;
			}
			else
			{
				seperation.x = rightSep;
			}

			//which y direction has the smallest seperation
			if (ABS(downSep) < ABS(upSep))
			{
				seperation.y = downSep;
			}
			else
			{
				seperation.y = upSep;
			}

			//only consider the smallest seperation
			if (ABS(seperation.x) > ABS(seperation.y))
			{
				seperation.x = 0.0f;
			}
			else
			{
				seperation.y = 0.0f;
			}

			return Collision(true, seperation * -1.0f);
		}
	}

	return Collision(false, Vector2(0,0));
}

//relays to the correctly ordered collision test above
Collision CollisionSolver::testCollision(Vector2 point, AABB aabb)
{
	return testCollision(aabb, point);
}

//collision test between two AABBs
Collision CollisionSolver::testCollision(AABB aabb1, AABB aabb2)
{
	//test if the ranges formed by the min and max points of both aabbs overlap
	float leftSep = aabb1.max_.x - aabb2.min_.x;
	float rightSep = aabb1.min_.x - aabb2.max_.x;
	float upSep = aabb1.max_.y - aabb2.min_.y;
	float downSep = aabb1.min_.y - aabb2.max_.y;


	if (leftSep > 0 && rightSep < 0)
	{
		if (upSep > 0 && downSep < 0)
		{
			Vector2 seperation = Vector2();

			//which x direction has the smallest seperation
			if (ABS(leftSep) < ABS(rightSep))
			{
				seperation.x = leftSep;
			}
			else
			{
				seperation.x = rightSep;
			}

			//which y direction has the smallest seperation
			if (ABS(downSep) < ABS(upSep))
			{
				seperation.y = downSep;
			}
			else
			{
				seperation.y = upSep;
			}

			//only consider the smallest seperation
			if (ABS(seperation.x) > ABS(seperation.y))
			{
				seperation.x = 0.0f;
			}
			else
			{
				seperation.y = 0.0f;
			}

			return Collision(true, seperation * -1.0f);
		}
	}


	return Collision();
}

