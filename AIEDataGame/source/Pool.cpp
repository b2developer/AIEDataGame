#include "Pool.h"

//destructor, removes all pools
Pool::~Pool()
{
	LinkedList<BasePool*>::Iterator iter = rawPoolList.begin();

	//iterate through all of the pools
	for (; iter != rawPoolList.end(); iter++)
	{
		delete iter.m_node->value;
	}
}

//updates the decay of all pools
void Pool::updateDecay(float deltaTime, float targetFrameRate)
{
	LinkedList<BasePool*>::Iterator iter = rawPoolList.begin();

	//iterate through all of the pools
	for (; iter != rawPoolList.end(); iter++)
	{
		iter.m_node->value->updateDecay(deltaTime, targetFrameRate);
	}
}

//adds the pool to the linear list and tree of pools
void Pool::addPool(char key[MAX_KEY], BasePool * pool)
{
	rawPoolList.pushBack(pool); //linear list
	m_pools.insert(key, pool); //tree
}

//searches for a single pool associated with the key, then requests an object from the pool
void * Pool::requestObject(char key[MAX_KEY])
{
	BasePool* singlePool = *m_pools.searchFor(key);
	return singlePool->requestObject();
}

//searches for a single pool associate with the key, then stores the instance in it
void Pool::removeObject(char key[MAX_KEY], void * instancePtr)
{
	BasePool* singlePool = *m_pools.searchFor(key);
	singlePool->removeObject(instancePtr);
}
