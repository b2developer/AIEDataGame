#pragma once
#include "ColliderComponent.h"
#include "TextFileResource.h"

typedef ColliderType** map;

//forward declaration
class Application2D;

/*
* class GridPair
*
* represents part of a grid, used to get collisions
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
struct GridPair
{
	AABB region; //the region that this part of the grid surrounds
	ColliderType data; //the number written at the grid pair
};



/*
* class GridColliderComponent
* child class of ColliderComponent
*
* a component that holds a 2D data map of regions that can be collided with
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class GridColliderComponent : public ColliderComponent
{
public:

	LinkedNode<GridColliderComponent*>* thisNode = nullptr; //position in the renderers array in playState

	//dimensions of the 2D array
	int sizeY = 0;
	int sizeX = 0;

	map data; //2D array of data

	TextFileResource* textRes; //pointer to the 2D array data from the text file

	/*
	* GridColliderComponent()
	* default constructor
	*/
	GridColliderComponent() {};

	/*
	* ~GridColliderComponent()
	* destructor, removes the 2D array
	*/
	~GridColliderComponent();

	/*
	* initialise
	* overrides ColliderComponent's initialise()
	*
	* initialises the component, only gets called if component is attached to a gameobject
	*
	* @returns void
	*/
	void initialise() override;

	/*
	* load
	* 
	* loads in the array data, setting up the grid
	* collider for use detecting collisions in a game
	*
	* @returns void
	*/
	void load();

	/*
	* charArrayToInt
	*
	* converts an array of chars into an array
	* throws an error if the string was too long
	* or didn't contain only ascii numerals
	*
	* @parar char* cArr - the c-string to create a number from
	* @returns int - the number made from the c-string
	*/
	int charArrayToInt(char* cArr);


	/*
	* getNeighbourColliders
	*
	* gets a list of all colliders that would 
	* be touching the grid, if they exist
	*
	* @param AABB otherRegion - the region to get colliders for
	* @returns LinkedList<GridPair> - a list of AABBs with the number associated with it
	a
	*/
	LinkedList<GridPair> getNeighbourColliders(AABB otherRegion);

};
