#include "GridRendererComponent.h"
#include "Application2D.h"

//initialises the grid
void GridRendererComponent::initialise()
{

}

//renders the entire grid
void GridRendererComponent::render(Application2D* appPtr, Vector2 cameraOffset)
{
	
	Vector2 length = singularRegion.max_ - singularRegion.min_;
	Vector2 renderLength = renderRegion.max_ - renderRegion.min_;
	Vector2 full = Vector2((float)atlasRes->texture->getWidth(), (float)atlasRes->texture->getHeight());

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			int x = (int)data[i][j];

			//don't draw the tile if it is invisible
			if (x == TileType::SKIP)
			{
				continue;
			}

			x--;

			//the ratio between the full width and height of the texture and the specified region of one block
			float ratioX = full.x / length.x;
			float ratioY = full.y / length.y;

			//turning a single number into UV coordinates
			float U = (x % (int)(ratioX)) / ratioX;
			float V = ((int)floorf(x / ratioX)) / ratioY;

			AABB trueRegion = AABB();

			trueRegion.min_ = parent->transform->position + Vector2(renderLength.x * j, renderLength.y * (sizeY - i - 1)) - cameraOffset;
			trueRegion.max_ = parent->transform->position + Vector2(renderLength.x * j, renderLength.y * (sizeY - i - 1)) + renderLength - cameraOffset;

			//set the rect to the correct coordinates to render the block
			appPtr->m_renderer2D->setUVRect(U + uvEpsilon, V + uvEpsilon, 1 / ratioX - uvEpsilon * 2.0f, 1 / ratioY - uvEpsilon * 2.0f);

			appPtr->m_renderer2D->drawSprite(atlasRes->texture, trueRegion.min_.x * appPtr->m_screen.x, trueRegion.min_.y * appPtr->m_screen.y, renderLength.x * appPtr->m_screen.x, renderLength.y * appPtr->m_screen.y, 0.0f, 1.0f, 0, 0);
		}
	}

	//reset the UV rect
	appPtr->m_renderer2D->setUVRect(0, 0, 1, 1);
}