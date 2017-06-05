#include "Button.h"
#include "Application2D.h"
#include "CollisionSolver.h"

//simulates one frame of the button
void Button::update(Application2D* appPtr, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	Vector2 mousePos = Vector2((float)input->getMouseX() / appPtr->m_screen.x, (float)input->getMouseY() / appPtr->m_screen.y);

	//detect the mouse click
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT) && (!appPtr->PREV_MOUSE_0_STATE || inputMode == INPUT_MODE::CONSTANT))
	{
		//detect the mouse colliding with the hitbox
		if (COLL_SOLVER->testCollision(hitbox, mousePos).colliding)
		{
			if (action != nullptr)
			{
				action->execute(appPtr);
			}
		}
	}
}

//renders the button
void Button::draw(Application2D* appPtr)
{
	Vector2 length = hitbox.max_ - hitbox.min_;

	appPtr->m_renderer2D->drawSprite(boxTexture->texture, hitbox.min_.x * appPtr->m_screen.x, hitbox.min_.y * appPtr->m_screen.y, length.x * appPtr->m_screen.x, length.y * appPtr->m_screen.y, 0.0f, 1.0f, 0, 0);
}