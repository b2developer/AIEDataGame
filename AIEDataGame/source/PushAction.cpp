#include "PushAction.h"
#include "Application2D.h"

//adds the pushed gamestate pointer to the stack
void PushAction::execute(Application2D* appPtr)
{
	appPtr->gameStateStack.pushFront(pushed);
	pushed->onEnter(appPtr);

}