#include "Button.h"
#include "Application2D.h"
#include "CollisionSolver.h"

//simulates one frame of the button
void Button::update(Application2D* appPtr, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	Vector2 mousePos = Vector2((float)input->getMouseX(), (float)input->getMouseY());

	if (COLL_SOLVER->testCollision(hitbox, mousePos).colliding)
	{

	}
}

//renders the button
void Button::draw(Application2D* appPtr)
{

}