#include "Application2D.h"

Application2D::Application2D()
{

}

Application2D::~Application2D()
{

}


//reserves memory to be used by the application
bool Application2D::startup()
{

	m_renderer2D = new aie::Renderer2D();

	TextureResource* redSquare = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "red_square.png");
	TextureResource* blueSquare = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "blue_square.png");
	TextureResource* greenSquare = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "green_square.png");
	TextureResource* redSquare2 = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "red_square.png");

	RESOURCE_MAN->releaseResource("red_square.png");
	RESOURCE_MAN->releaseResource("blue_square.png");
	RESOURCE_MAN->releaseResource("green_square.png");
	RESOURCE_MAN->releaseResource("red_square.png");

	return true;
}

//releases memory used by the application
void Application2D::shutdown()
{
	delete m_renderer2D;
}

//simulates one frame
void Application2D::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}

	TextureResource* redSquare = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "red_square.png");
	TextureResource* blueSquare = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "blue_square.png");
	TextureResource* greenSquare = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "green_square.png");
	TextureResource* redSquare2 = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "red_square.png");

	RESOURCE_MAN->releaseResource("red_square.png");
	RESOURCE_MAN->releaseResource("blue_square.png");
	RESOURCE_MAN->releaseResource("green_square.png");
	RESOURCE_MAN->releaseResource("red_square.png");

	//check that there is still gamestates left in the stack
	if (gameStateStack.size > 0)
	{
		//update the uppermost gamestate
		gameStateStack[0]->update(this, deltaTime);
	}
	else
	{
		//there are no gamestates left, quit the application
		//quit();
	}
}

//renders the game
void Application2D::draw()
{
	m_renderer2D->setCameraPos(m_camera.x, m_camera.y);
	m_renderer2D->begin();

	//check that there is still gamestates left in the stack
	if (gameStateStack.size > 0)
	{
		//draw the uppermost gamestate
		gameStateStack[0]->draw(this);
	}

	m_renderer2D->end();
}