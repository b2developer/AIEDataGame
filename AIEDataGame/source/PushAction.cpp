#include "PushAction.h"
#include "Application2D.h"

//adds the gamestate to the stack
void PushAction::execute(Application2D * appPtr)
{
	appPtr->gameStateStack.pushFront(pushed);

	//call onEnter on the pushed gamestate
	pushed->onEnter(appPtr);
}
