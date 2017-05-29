#pragma once
#include "AABB.h"

#define COLL_SOLVER CollisionSolver::getInstance()

#define ABS(x) ((x < 0) ? -x : x)

/*
* struct Collision
*
* contains useful information about a collision test
* such as the movement required to solve it
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
struct Collision
{
	/*
	* Collision()
	* default constructor
	*/
	Collision() {};

	/*
	* Collision(bool _colliding, Vector2 _MTV)
	*
	* constructor, assigns the internal values for the collision
	*
	* @param bool _colliding - the colliding flag
	* @param Vector2 _MTV - the Minumum Translation Vector
	*/
	Collision(bool _colliding, Vector2 _MTV) : colliding(_colliding), MTV(_MTV) {};

	bool colliding = false; //flag indicating if a collision occurred
	Vector2 MTV = Vector2(0,0); //minimum movement required to sepearate the objects
};



/*
* class CollisionSolver
*
* a singleton class that contains methods for checking collisions
* between AABBs and points
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class CollisionSolver
{

public:

	/*
	* getInstance
	*
	* gets the pointer to the CollisionSolver singleton, creates
	* the singleton if it doesn't exist already
	*
	* @returns static CollisionSolver* - the singleton pointer
	*/
	static CollisionSolver* getInstance();

	/*
	* testCollision
	*
	* tests if an AABB and a point are colliding
	*
	* @param AABB aabb - the AABB to test with
	* @param Vector2 point - the point to test with
	* @returns Collision - information about the collision
	*/
	Collision testCollision(AABB aabb, Vector2 point);

	/*
	* testCollision
	*
	* tests if an AABB and a point are colliding
	* relays to the correctly ordered function
	*
	* testCollision(AABB aabb, Vector2 point)
	*
	* @param Vector2 point - the point to test with
	* @param AABB aabb - the AABB to test with
	* @returns Collision - information about the collision
	*/
	Collision testCollision(Vector2 point, AABB aabb);

	/*
	* testCollision
	*
	* tests if two AABBs are colliding
	*
	* @param AABB aabb1 - the first AABB to test with
	* @param AABB aabb2 - the second AABB to test with
	* @returns Collision - information about the collision
	*/
	Collision testCollision(AABB aabb1, AABB aabb2);

private:

	//hide the constructor and destructor

	/*
	* CollisionSolver
	* default constructor
	*/
	CollisionSolver() {};

	/*
	* ~CollisionSolver
	* default destructor
	*/
	~CollisionSolver() {}

};