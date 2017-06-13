#include "GameObject.h"
#include "Application2D.h"

//initialises all of the components
void GameObject::initialise(Application2D * appPtr)
{
	LinkedList<BaseComponent*>::Iterator iter = components.begin();

	//iterate through all of the components
	for (; iter != components.end(); iter++)
	{
		iter.m_node->value->initialise();
	}
}

//simulates one frame of the game object
void GameObject::update(Application2D* appPtr, float deltaTime)
{
	LinkedList<BaseComponent*>::Iterator iter = components.begin();

	//iterate through all of the components
	for (; iter != components.end(); iter++)
	{
		iter.m_node->value->update();
	}
}