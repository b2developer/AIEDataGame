#include "MenuState.h"
#include "Application2D.h"

//simulates one frame of the menu state
void MenuState::update(Application2D* appPtr, float deltaTime)
{
	LinkedList<Item*>::Iterator iter = items.begin();

	for (; iter != items.end(); iter++)
	{
		iter.m_node->value->update(appPtr, deltaTime);
	}
}

//renders the menu state
void MenuState::draw(Application2D* appPtr)
{
	LinkedList<Item*>::Iterator iter = items.begin();

	for (; iter != items.end(); iter++)
	{
		iter.m_node->value->draw(appPtr);
	}
}

//called when the menu state becomes the uppermost gamestate in the stack
void MenuState::onEnter(Application2D* appPtr)
{
	firstFrame = true;
}

//called when the gamestate is no longer the uppermost gamestate in the stack
void MenuState::onExit(Application2D* appPtr)
{

}
