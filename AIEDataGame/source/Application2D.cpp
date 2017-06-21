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

	m_pool = new Pool();

	//create singular pools for all necessary types
	BasePool* tPool = new SinglePool<TransformComponent>();
	BasePool* cPool = new SinglePool<ColliderComponent>();
	BasePool* rPool = new SinglePool<RendererComponent>();
	BasePool* gPool = new SinglePool<GameObject>();

	tPool->setDecay(0.99f);

	m_pool->addPool("transform", tPool);
	m_pool->addPool("collider", cPool);
	m_pool->addPool("renderer", rPool);
	m_pool->addPool("gameObject", gPool);

	//create director and some builders
	director = new Director();
	playerBuilder = new PlayerBuilder();
	wallBuilder = new WallBuilder();
	levelBuilder = new LevelBuilder();

	director->builder = playerBuilder;

	MenuState* splash = new MenuState();
	MenuState* mainMenu = new MenuState();
	PlayState* game = new PlayState();
	MenuState* options = new MenuState();
	MenuState* pause = new MenuState();

	game->poolPtr = m_pool;

	//main menu items
	{
		//pop actions
		PopAction* singlePopAct = new PopAction();
		singlePopAct->layers = 1;

		PopAction* doublePopAct = new PopAction();
		doublePopAct->layers = 2;

		//push actions
		PushAction* mmPushAct = new PushAction();
		mmPushAct->pushed = mainMenu;

		PushAction* gaPushAct = new PushAction();
		gaPushAct->pushed = game;

		PushAction* opPushAct = new PushAction();
		opPushAct->pushed = options;

		PushAction* paPushAct = new PushAction();
		paPushAct->pushed = pause;

		//push buttons
		Button* gaPush = new Button();
		gaPush->action = gaPushAct;
		gaPush->hitbox.min_ = Vector2(0.4f, 0.4f);
		gaPush->hitbox.max_ = Vector2(0.6f, 0.6f);
		gaPush->boxTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "red_square.png");

		Button* opPush = new Button();
		opPush->action = opPushAct;
		opPush->hitbox.min_ = Vector2(0.4f, 0.4f);
		opPush->hitbox.max_ = Vector2(0.6f, 0.6f);
		opPush->boxTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "red_square.png");

		Button* opPush2 = new Button();
		opPush2->action = opPushAct;
		opPush2->hitbox.min_ = Vector2(0.7f, 0.4f);
		opPush2->hitbox.max_ = Vector2(0.9f, 0.6f);
		opPush2->boxTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "red_square.png");

		Button* paPush = new Button();
		paPush->action = paPushAct;
		paPush->hitbox.min_ = Vector2(0.4f, 0.4f);
		paPush->hitbox.max_ = Vector2(0.6f, 0.6f);
		paPush->boxTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "red_square.png");

		//pop buttons
		Button* singlePop = new Button();
		singlePop->action = singlePopAct;
		singlePop->hitbox.min_ = Vector2(0.4f, 0.7f);
		singlePop->hitbox.max_ = Vector2(0.6f, 0.9f);
		singlePop->boxTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "blue_square.png");

		Button* doublePop = new Button();
		doublePop->action = doublePopAct;
		doublePop->hitbox.min_ = Vector2(0.7f, 0.7f);
		doublePop->hitbox.max_ = Vector2(0.9f, 0.9f);
		doublePop->boxTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "blue_square.png");

		//timer
		Timer* splashTimer = new Timer();
		splashTimer->maxTime = 1.0f;
		splashTimer->currentTime = splashTimer->maxTime;
		splashTimer->reactions.pushBack(singlePopAct);
		splashTimer->reactions.pushBack(mmPushAct);

		//text
		Text* mainMenuText = new Text();
		strcpy_s(mainMenuText->message, "Main Menu");
		mainMenuText->font = (FontResource*)RESOURCE_MAN->requestResource(ResourceType::FONT, "font/consolas.ttf");
		mainMenuText->origin = Vector2(0.05f, 0.8f);
		mainMenuText->scale = Vector2(1.0f, 1.0f);

		Text* gameText = new Text();
		strcpy_s(gameText->message, "Game");
		gameText->font = (FontResource*)RESOURCE_MAN->requestResource(ResourceType::FONT, "font/consolas.ttf");
		gameText->origin = Vector2(0.05f, 0.8f);
		gameText->scale = Vector2(1.0f, 1.0f);

		Text* optionsText = new Text();
		strcpy_s(optionsText->message, "Options");
		optionsText->font = (FontResource*)RESOURCE_MAN->requestResource(ResourceType::FONT, "font/consolas.ttf");
		optionsText->origin = Vector2(0.05f, 0.8f);
		optionsText->scale = Vector2(1.0f, 1.0f);

		Text* pauseText = new Text();
		strcpy_s(pauseText->message, "Pause");
		pauseText->font = (FontResource*)RESOURCE_MAN->requestResource(ResourceType::FONT, "font/consolas.ttf");
		pauseText->origin = Vector2(0.05f, 0.6f);
		pauseText->scale = Vector2(1.0f, 1.0f);

		Text* splashText = new Text();
		strcpy_s(splashText->message, "Splash");
		splashText->font = (FontResource*)RESOURCE_MAN->requestResource(ResourceType::FONT, "font/consolas.ttf");
		splashText->origin = Vector2(0.05f, 0.8f);
		splashText->scale = Vector2(1.0f, 1.0f);

		TickBox* tickbox = new TickBox();
		tickbox->hitbox.min_ = Vector2(0.47f, 0.53f);
		tickbox->hitbox.max_ = Vector2(0.53f, 0.59f);
		tickbox->falseTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "tick.png");
		tickbox->trueTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "tickOn.png");

		Sprite* sprite = new Sprite();
		sprite->hitbox.min_ = Vector2(0.37f, 0.43f);
		sprite->hitbox.max_ = Vector2(0.43f, 0.59f);
		sprite->boxTexture = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "green_square.png");

		splash->items.pushBack(splashTimer);
		splash->items.pushBack(splashText);

		mainMenu->items.pushBack(gaPush);
		mainMenu->items.pushBack(singlePop);
		mainMenu->items.pushBack(mainMenuText);
		mainMenu->items.pushBack(opPush2);

		game->pauseAct = paPushAct;

		pause->items.pushBack(singlePop);
		pause->items.pushBack(doublePop);
		pause->items.pushBack(opPush);
		pause->items.pushBack(pauseText);

		pause->isFinalDraw = false;

		options->items.pushBack(singlePop);
		options->items.pushBack(optionsText);
		options->items.pushBack(tickbox);
		options->items.pushBack(sprite);
	}

	gameStateStack.pushBack(splash);

	return true;
}

//releases memory used by the application
void Application2D::shutdown()
{
	delete m_renderer2D;

	delete m_pool;

	delete director;
	delete playerBuilder;
}

//simulates one frame
void Application2D::update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	m_pool->updateDecay(deltaTime, 60.0f);

	//deltaTime sanitisation
	deltaTime = deltaTime < minFrame ? minFrame : deltaTime; //clamp to above the minimum time for a frame
	deltaTime = deltaTime > maxFrame ? maxFrame : deltaTime; //clamp to below the maximum time for a frame
	
	//check that there is still gamestates left in the stack
	if (gameStateStack.size > 0)
	{
		for (unsigned int i = 0; i < gameStateStack.size; i++)
		{
			//check if the game state was just created
			if (gameStateStack[i]->firstFrame)
			{
				//reset the firstFrame flag
				gameStateStack[i]->firstFrame = false;
			}
			else
			{
				unsigned int prevSize = gameStateStack.size;

				//update the gamestate
				gameStateStack[i]->update(this, deltaTime);

				if (gameStateStack.size > 0)
				{
					//update the new gamestate
					if (gameStateStack.size > prevSize)
					{
						i++;
					}
					else if (gameStateStack.size < prevSize)
					{
						i--;
					}
				}
				else
				{
					break;
				}
			}

			//don't continue updating
			if (gameStateStack[i]->isFinalUpdate)
			{
				break;
			}
		}

	}
	else
	{
		//there are no gamestates left, quit the application
		quit();
	}

	//get the screen dimensions
	m_screen = Vector2((float)getWindowWidth(), (float)getWindowHeight());

	PREV_MOUSE_0_STATE = input->isMouseButtonDown(0);
	PREV_MOUSE_1_STATE = input->isMouseButtonDown(1);

}

//renders the game
void Application2D::draw()
{
	clearScreen();
	
	m_renderer2D->setRenderColour(1, 1, 1);
	m_renderer2D->setCameraPos(0.0f, 0.0f);
	m_renderer2D->begin();

	//check that there is still gamestates left in the stack
	if (gameStateStack.size > 0)
	{
		for (unsigned int i = 0; i < gameStateStack.size; i++)
		{
		
			//don't continue rendering
			if (gameStateStack[i]->isFinalDraw)
			{
				for (int j = (int)i; j >= 0; j--)
				{
					//draw the gamestate
					gameStateStack[j]->draw(this);
				}

				break;
			}
		}

	}

	m_renderer2D->end();
}


