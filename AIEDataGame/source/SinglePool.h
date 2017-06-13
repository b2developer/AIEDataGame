#pragma once
#include "LinkedList.h"
#include <cmath>

//template macro
#define TEMPLATE template<typename T>

/*
* class BasePool
*
* allows SinglePool to inherit, hiding it's template from Pool
* 
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class BasePool
{
public:

	/*
	* BasePool()
	* default constructor
	*/
	BasePool() {};

	/*
	* ~BasePool()
	* virtual function
	* default destructor
	*/
	virtual ~BasePool() {};

	/*
	* setDecay
	* abstract function
	*
	* exists to provide an interface to SinglePool
	*
	* @param float rate - the new rate
	* @returns void
	*/
	virtual void setDecay(float rate) = 0;

	/*
	* updateDecay
	* abstract function
	*
	* exists to provide an interface to SinglePool
	*
	* @param float deltaTime - the amount of time passed since the last frame
	* @param float targetFrameRate - the desired frame rate of the application
	* @returns void
	*/
	virtual void updateDecay(float deltaTime, float targetFrameRate) = 0;

	/*
	* requestObject
	* abstract function
	*
	* exists to provide an interface to SinglePool
	*
	* @returns void* - pointer to the instance requested
	*/
	virtual void* requestObject() = 0;

	/*
	* requestObject
	* abstract function
	*
	* exists to provide an interface to SinglePool
	*
	* @param void* instancePtr - pointer to the instance to remove
	* @returns void
	*/
	virtual void removeObject(void* instancePtr) = 0;
};

struct Object
{
	int fie = 0;
};

struct Object2
{
	int foe = 0;
};

struct Object3
{
	int fum = 0;
};

/*
* class SinglePool
* child class of SinglePool
* template
*
* instead of deleting objects, the pool holds them for later use,
* reassigning stored objects rather than creating new ones
* also deletes instances if there are too many
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
TEMPLATE
class SinglePool : public BasePool
{
public:

	float decimalSize = 0.0f; //the size of the list as a decimal, used to apply decay rates to
	float decayRate = 1.0f; //controls the size of the list over time

	LinkedList<T*> available = LinkedList<T*>(0); //list of instance available for use

	/*
	* SinglePool()
	* default constructor
	*/
	SinglePool() {};

	/*
	* ~SinglePool()
	* destructor, removes all instances
	*/
	~SinglePool() 
	{
		LinkedList<T*>::Iterator iter = available.begin();

		//iterate through all of the items in the pool
		for (; iter != available.end(); iter++)
		{
			//delete the value
			delete iter.m_node->value;
		}
	
	};

	/*
	* setDecay
	* overrides BasePool's setDecay(float rate)
	*
	* sets the new decay rate
	*
	* @param float rate - the new decay rate
	* @returns void
	*/
	void setDecay(float rate) override
	{
		decayRate = rate;
	}

	/*
	* updateDecay
	* overrides BasePool's updateDecay(float deltaTime, float targetFrameRate)
	*
	* subtracts a portion of the pool's size through exponential decay
	* 
	* @param float deltaTime - amount of time passed since the last frame
	* @param float targetFrameRate - the frame rate desired by the application
	*/
	void updateDecay(float deltaTime, float targetFrameRate) override
	{
		//amount of time passed in an ideal frame
		float invTarget = 1 / targetFrameRate;

		//ratio of the time passed to the ideal time passed
		float multiplier = deltaTime / invTarget;

		int prevSize = (int)decimalSize;

		//take the decayRate to the power
		decimalSize *= powf(decayRate, multiplier);

		int currSize = (int)decimalSize;

		//did the decay cause a decrease in size 
		if (currSize < prevSize)
		{
			T* instancePtr = available[0];

			//remove the instance from the pool
			available.popBack();

			//delete the instance
			delete instancePtr;
		}
	}

	/*
	* requestObject
	* overrides BasePool's requestObject()
	*
	* grabs an object from the available list, if none are
	* available one is created
	*
	* @returns void* - pointer to the instance
	*/
	void* requestObject() override
	{
		
		//test if there is already an object in the list
		if (available.size > 0) //re-use a stored instance
		{
			T* instancePtr = available[0];

			//remove the instance from the pool as it is about to be in use
			available.popFront();

			decimalSize = float(available.size);

			return instancePtr;
		}
		else //create a new instance
		{
			T* instancePtr = new T();

			return instancePtr;
		}

	}

	/*
	* removeObject
	* overrides BasePool's removeObject(void* instancePtr)
	*
	* rather than deleting an object, this function can be
	* called to keep the instance for use later
	*
	* @param void* - pointer to the object
	* @returns void
	*/
	void removeObject(void* instancePtr) override
	{
		available.pushBack((T*)instancePtr);
		decimalSize = float(available.size);
	}

};