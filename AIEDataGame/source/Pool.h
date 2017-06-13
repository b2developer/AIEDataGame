#pragma once
#include "SinglePool.h"
#include "KeyList.h"

/*
* class Pool
*
* holds a binary tree of SinglePool objects
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Pool
{
public:

	LinkedList<BasePool*> rawPoolList; //linear list of the pools, used for applying actions to all pools
	KeyList<BasePool*> m_pools; //binary search tree of SinglePools with multiple types

	/*
	* Pool()
	* default constructor
	*/
	Pool() {};

	/*
	* ~Pool() 
	* destructor, removes all of the pools
	*/
	~Pool();

	/*
	* updateDecay
	*
	* updates the decay of all pools
	*
	* @param float deltaTime - the amount of time passed since the last frame
	* @param float targetFrameRate - the frame rate desired by the application
	* @returns void
	*/
	void updateDecay(float deltaTime, float targetFrameRate);

	/*
	* addPool
	*
	* adds the pool to the binary search tree
	* and the linear list of pools
	*
	* @param key[MAX_KEY] - key to associate the pool with
	* @param BasePool* pool - pointer to the pool to add
	* @returns void
	*/
	void addPool(char key[MAX_KEY], BasePool* pool);

	/*
	* requestObject
	*
	* searches for a pool associated with the key
	* and then calls upon the pool to return an instance pointer
	* throws an error if the pool wasn't found
	*
	* @param char key[MAX_KEY] - key to search the binary search tree with
	* @returns void* - pointer to the instance returned
	*/
	void* requestObject(char key[MAX_KEY]);

	/*
	* removeObject
	*
	* stores an object in the pool associated with the key
	*
	* @param char key[MAX_KEY] - key to search the binary search tree with
	* @param void* instancePtr - pointer to the instance to store in the pool
	* @returns void
	*/
	void removeObject(char key[MAX_KEY], void* instancePtr);
};