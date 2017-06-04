#include "Button.h"
#include "Application2D.h"
#include "CollisionSolver.h"

//simulates one frame of the button
void Button::update(Application2D* appPtr, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	Vector2 mousePos = Vector2((float)input->getMouseX(), (float)input->getMouseY());

	//detect the edge of the mouse
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT) && (!appPtr->PREV_MOUSE_0_STATE || inputMode == INPUT_MODE::CONSTANT))
	{
		if (COLL_SOLVER->testCollision(hitbox, mousePos).colliding)
		{
			std::cout << "hi";
		}
	}
}

//renders the button
void Button::draw(Application2D* appPtr)
{
	Vector2 length = hitbox.max_ - hitbox.min_;

	appPtr->m_renderer2D->drawSprite(boxTexture->texture, hitbox.min_.x, hitbox.min_.y, length.x, length.y, 0.0f, 1.0f, 0, 0);
}