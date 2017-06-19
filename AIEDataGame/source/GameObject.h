#pragma once
#include "LinkedList.h"
#include "BaseComponent.h"

//forward declaration
class Application2D;

/*
* class GameObject
*
* an entity that can be updated during the game, has no 
* function on it's own. Components can be added to it to give
* it some behaviour
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class GameObject
{
public:
	
	LinkedNode<GameObject*>* thisNode = nullptr; //position in the gameObjects array in playState

	TransformComponent* transform = nullptr; //most components need to know about the transform

	LinkedList<BaseComponent*> components;

	/*
	* GameObject()
	* default constructor
	*/
	GameObject() {};

	/*
	* ~GameObject()
	* default destructor
	*/
	~GameObject() {};

	/*
	* initialise
	*
	* initialises all components
	*
	* @param Application2D* appPtr - pointer to the application, required by some components
	* @returns void
	*/
	void initialise(Application2D* appPtr);

	/*
	* update
	* 
	* simulates one frame of the game object
	* calls upon all of it's components to run
	*
	* @param Application2D* appPtr - pointer to the application, required for some components
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	a
	*/
	void update(Application2D* appPtr, float deltaTime);

	TEMPLATE
	/*
	* getComponentsOfType
	* template
	*
	* gets a list of components that
	* match the specified type
	*
	* @returns LinkedList<T*> - list of pointers to components
	*/
	LinkedList<T*> getComponentsOfType()
	{
		LinkedList<T*> list = LinkedList<T*>(0);

		LinkedList<BaseComponent*>::Iterator iter = components.begin();

		//iterate through all of the components
		for (; iter != components.end(); iter++)
		{
			T* pointer = dynamic_cast<T*>(iter.m_node->value);

			//test for a type match between the template and the iterated to component
			if (pointer != nullptr)
			{
				list.pushBack(pointer);
			}
		}

		return list;
	}
};