#include "PopAction.h"
#include "Application2D.h"

//removes a specific amount of gamestates from the stack
void PopAction::execute(Application2D * appPtr)
{
	//loop because a check needs to be made during every removal
	for (unsigned int i = 0; i < layers; i++)
	{
		if (appPtr->gameStateStack.size > 0)
		{
			//call onExit on the removed gamestate
			appPtr->gameStateStack[0]->onExit(appPtr);
			appPtr->gameStateStack.popFront();
		}
		else
		{
			break;
		}
	}

	//call onEnter() on the gamestate that was just promoted to the front of the stack, if one was promoted
	if (appPtr->gameStateStack.size > 0)
	{
		appPtr->gameStateStack[0]->onEnter(appPtr);
	}
}
