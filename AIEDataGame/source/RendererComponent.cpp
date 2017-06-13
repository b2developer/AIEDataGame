#include "RendererComponent.h"
#include "Application2D.h"

//draws the texture
void RendererComponent::render(Application2D * appPtr)
{
	Vector2 length = region.max_ - region.min_;

	appPtr->m_renderer2D->drawSprite(textureRes->texture, region.min_.x * appPtr->m_screen.x, region.min_.y * appPtr->m_screen.y, length.x * appPtr->m_screen.x, length.y * appPtr->m_screen.y, 0.0f, 1.0f, 0, 0);
}
