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
	if (aabb.max.x > point.x && aabb.min.x < point.x)
	{
		if (aabb.max.y > point.y && aabb.min.y < point.y)
		{
			Vector2 seperation = Vector2();

			//get the movement required to bring to point to the four edges of the AABB
			float leftSep = aabb.min.x - point.x;
			float rightSep = aabb.max.x - point.x;

			float upSep = aabb.max.y - point.y;
			float downSep = aabb.min.y - point.y;

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

			return Collision(true, seperation);
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
	float leftSep = aabb1.max.x - aabb2.min.x;
	float rightSep = aabb1.min.x - aabb2.max.x;
	float upSep = aabb1.max.y - aabb2.min.y;
	float downSep = aabb1.min.y - aabb2.max.y;


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

			return Collision(true, seperation);
		}
	}


	return Collision();
}

