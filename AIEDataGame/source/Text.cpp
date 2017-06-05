#include "Text.h"
#include "Application2D.h"

//renders the text
void Text::draw(Application2D * appPtr)
{
	appPtr->m_renderer2D->drawText(font->font, message, origin.x * appPtr->m_screen.x, origin.y * appPtr->m_screen.y, scale.x * (appPtr->m_screen.x / 1280), scale.y * (appPtr->m_screen.y / 720), 1);
}
