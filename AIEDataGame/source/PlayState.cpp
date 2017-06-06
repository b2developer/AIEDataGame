#include "PlayState.h"
#include "Application2D.h"

//simulates one frame of the play state
void PlayState::update(Application2D* appPtr, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		pauseAct->execute(appPtr);
	}
}

//renders the play state
void PlayState::draw(Application2D* appPtr)
{
	
}

//called when the gamestate becomes the uppermost gamestate in the stack
void PlayState::onEnter(Application2D* appPtr)
{
	firstFrame = true;
}

//called when the gamestate is no longer the uppermost gamestate in the stack
void PlayState::onExit(Application2D* appPtr)
{

}
