#include "Sprite.h"
#include "Application2D.h"

//destructor, releases resources
Sprite::~Sprite()
{
	RESOURCE_MAN->releaseResource(boxTexture->resourceName);
}

//draws the sprite
void Sprite::draw(Application2D * appPtr)
{
	Vector2 length = hitbox.max_ - hitbox.min_;

	appPtr->m_renderer2D->drawSprite(boxTexture->texture, hitbox.min_.x * appPtr->m_screen.x, hitbox.min_.y * appPtr->m_screen.y, length.x * appPtr->m_screen.x, length.y * appPtr->m_screen.y, 0.0f, 1.0f, 0, 0);
}
