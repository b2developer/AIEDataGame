#include "RendererComponent.h"
#include "Application2D.h"

//initialise the renderer component
void RendererComponent::initialise()
{

}

//draws the texture
void RendererComponent::render(Application2D * appPtr)
{
	Vector2 length = region.max_ - region.min_;

	AABB global = getGlobalAABB();

	appPtr->m_renderer2D->drawSprite(textureRes->texture, global.min_.x * appPtr->m_screen.x, global.min_.y * appPtr->m_screen.y, length.x * appPtr->m_screen.x, length.y * appPtr->m_screen.y, 0.0f, 1.0f, 0, 0);
}

//gets the space occupied by the renderer's region
AABB RendererComponent::getGlobalAABB()
{
	return AABB(region.min_ + parent->transform->position, region.max_ + parent->transform->position); //add the transform's position
}