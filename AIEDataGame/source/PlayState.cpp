#include "PlayState.h"
#include "Application2D.h"
#include "CollisionSolver.h"

//simulates one frame of the play state
void PlayState::update(Application2D* appPtr, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	updateScripts(appPtr, deltaTime);
	updateColliders(appPtr, deltaTime);

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		pauseAct->execute(appPtr);
	}
}

//renders the play state
void PlayState::draw(Application2D* appPtr)
{
	updateRenderers(appPtr);
}

//called when the gamestate becomes the uppermost gamestate in the stack
void PlayState::onEnter(Application2D* appPtr)
{
	firstFrame = true;

	appPtr->director->builder = appPtr->playerBuilder;

	//instantiate the gameobject
	GameObject* player = appPtr->director->buildGameObject(appPtr, this);

	LinkedList<TransformComponent*> transformList = player->getComponentsOfType<TransformComponent>();
	LinkedList<RendererComponent*> rendererList = player->getComponentsOfType<RendererComponent>();
	LinkedList<ColliderComponent*> colliderList = player->getComponentsOfType<ColliderComponent>();

	transformList[0]->position = Vector2(0.5f, 0.5f);

	rendererList[0]->textureRes = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "blue_box.png");
	rendererList[0]->region = AABB(Vector2(-0.03f, -0.03f), Vector2(0.03f, 0.03f));

	colliderList[0]->region = rendererList[0]->region;
	colliderList[0]->mtvBias = 1.0f;

	appPtr->director->builder = appPtr->wallBuilder;

	//instantiate the gameobject
	/*
	GameObject* wall = appPtr->director->buildGameObject(appPtr, this);
	
	transformList = wall->getComponentsOfType<TransformComponent>();
	rendererList = wall->getComponentsOfType<RendererComponent>();
	colliderList = wall->getComponentsOfType<ColliderComponent>();

	transformList[0]->position = Vector2(0.5f, 0.2f);

	rendererList[0]->textureRes = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "blue_box.png");
	rendererList[0]->region = AABB(Vector2(-0.03f, -0.03f), Vector2(0.03f, 0.03f));

	colliderList[0]->region = rendererList[0]->region;
	colliderList[0]->mtvBias = 0.0f;

	*/

	appPtr->director->builder = appPtr->levelBuilder;

	//instantiate the gameobject
	GameObject* level = appPtr->director->buildGameObject(appPtr, this);

	//----------------- BEGIN SHITTY INITIALISATION -----------------------
	LinkedList<GridColliderComponent*> gcList = level->getComponentsOfType<GridColliderComponent>();

	gcList[0]->sizeX = 10;
	gcList[0]->sizeY = 3;

	gcList[0]->mtvBias = 0.0f;
	gcList[0]->region = AABB(Vector2(0.0f, 0.0f), Vector2(0.1f, 0.1f));

	gcList[0]->data = new ColliderType*[3];

	gcList[0]->data[2] = new ColliderType[10]{ (ColliderType)0,  (ColliderType)0,  (ColliderType)0,  (ColliderType)0,  (ColliderType)0,  (ColliderType)1,  (ColliderType)1,  (ColliderType)0,  (ColliderType)0,  (ColliderType)0 };
	gcList[0]->data[1] = new ColliderType[10]{ (ColliderType)0,  (ColliderType)1,  (ColliderType)1,  (ColliderType)0,  (ColliderType)0,  (ColliderType)0,  (ColliderType)0,  (ColliderType)0,  (ColliderType)0,  (ColliderType)0 };
	gcList[0]->data[0] = new ColliderType[10]{ (ColliderType)1,  (ColliderType)1,  (ColliderType)1,  (ColliderType)1,  (ColliderType)3,  (ColliderType)3,  (ColliderType)2,  (ColliderType)1,  (ColliderType)1,  (ColliderType)1 };

	LinkedList<GridRendererComponent*> grList = level->getComponentsOfType<GridRendererComponent>();

	grList[0]->sizeX = 10;
	grList[0]->sizeY = 3;

	grList[0]->singularRegion = AABB(Vector2(0.0f, 0.0f), Vector2(16.0f, 16.0f));
	grList[0]->renderRegion = AABB(Vector2(0.0f, 0.0f), Vector2(0.1f, 0.1f));

	grList[0]->atlasRes = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "level_atlas.png");

	grList[0]->data = new TileType*[3];

	grList[0]->data[0] = new TileType[10]{ (TileType)0,  (TileType)0,  (TileType)0,  (TileType)0,  (TileType)0,  (TileType)1,  (TileType)1,  (TileType)0,  (TileType)0,  (TileType)0 };
	grList[0]->data[1] = new TileType[10]{ (TileType)0,  (TileType)1,  (TileType)1,  (TileType)0,  (TileType)0,  (TileType)0,  (TileType)0,  (TileType)0,  (TileType)0,  (TileType)0 };
	grList[0]->data[2] = new TileType[10]{ (TileType)1,  (TileType)1,  (TileType)1,  (TileType)1,  (TileType)3,  (TileType)3,  (TileType)2,  (TileType)1,  (TileType)1,  (TileType)1 };
	//----------------- END SHITTY INITIALISATION -----------------------

}

//called when the gamestate is no longer the uppermost gamestate in the stack
void PlayState::onExit(Application2D* appPtr)
{
	cleanUp();
}

//updates all scripts
void PlayState::updateScripts(Application2D* appPtr, float deltaTime)
{
	LinkedList<ScriptComponent*>::Iterator iter = scripts.begin();

	//iterate through all scripts
	for (; iter != scripts.end(); iter++)
	{
		iter.m_node->value->update(appPtr, deltaTime);
	}
}

//tests for collisions
void PlayState::updateColliders(Application2D* appPtr, float deltaTime)
{
	LinkedList<ColliderComponent*>::Iterator iter1 = colliders.begin();

	//remove all prior collisions
	for (; iter1 != colliders.end(); iter1++)
	{
		iter1.m_node->value->collisions.clear();
	}

	LinkedList<GridColliderComponent*>::Iterator iter3 = gridColliders.begin();

	//remove all prior collisions from the grid
	for (; iter3 != gridColliders.end(); iter3++)
	{
		iter3.m_node->value->collisions.clear();
	}

	iter1 = colliders.begin();

	//iterate through all colliders
	for (; iter1 != colliders.end(); iter1++)
	{

		LinkedList<ColliderComponent*>::Iterator iter2 = colliders.begin();
		
		//iterate through all colliders again, O(n^2)
		for (; iter2 != colliders.end(); iter2++)
		{
			//test if the iterators aren't the same
			if (iter1 != iter2)
			{
				AABB global1 = iter1.m_node->value->getGlobalAABB();
				AABB global2 = iter2.m_node->value->getGlobalAABB();

				Collision collTest = COLL_SOLVER->testCollision(global1, global2);

				//did the collision test return positive
				if (collTest.colliding)
				{

					Vector2 nMTV = collTest.MTV.normalised();

					//tell the 1st gameobject about the collision
					CollisionTuple cp1;
					cp1.other = iter2.m_node->value;
					cp1.normal = nMTV;
					cp1.type = iter2.m_node->value->type;

					iter1.m_node->value->collisions.pushBack(cp1);

					//tell the 2nd gameobject about the collision
					CollisionTuple cp2;
					cp2.other = iter1.m_node->value;
					cp2.normal = nMTV * -1.0f;
					cp2.type = iter1.m_node->value->type;

					iter2.m_node->value->collisions.pushBack(cp2);

					//seperate the objects
					float ratio1 = iter1.m_node->value->mtvBias;
					float ratio2 = iter2.m_node->value->mtvBias;

					float ratioSum = ratio1 + ratio2;

					//test if the objects are both static
					if (ratioSum > 0)
					{
						//get the ratio of the movement to distribute accross both colliders
						float mtv1 = ratio1 / ratioSum;
						float mtv2 = ratio2 / ratioSum;

						//move the objects apart
						iter1.m_node->value->parent->transform->position += collTest.MTV * mtv1;
						iter2.m_node->value->parent->transform->position += collTest.MTV * -mtv2;
					}
				} 
			}
		}
		
		iter3 = gridColliders.begin();

		//iterate through all grid colliders, O(n^2)
		for (; iter3 != gridColliders.end(); iter3++)
		{
			AABB global1 = iter1.m_node->value->getGlobalAABB();

			LinkedList<GridPair> pairs = iter3.m_node->value->getNeighbourColliders(global1);

			LinkedList<GridPair>::Iterator pairIter = pairs.begin();

			//iterate through all of the aabbs that are colliding
			for (; pairIter != pairs.end(); pairIter++)
			{
			
				AABB global2 = pairIter.m_node->value.region;

				Collision collTest = COLL_SOLVER->testCollision(global1, global2);

				//did the collision test return positive
				if (collTest.colliding)
				{

					Vector2 nMTV = collTest.MTV.normalised();

					//tell the 1st gameobject about the collision
					CollisionTuple cp1;
					cp1.other = iter3.m_node->value;
					cp1.normal = nMTV;

					iter1.m_node->value->collisions.pushBack(cp1);

					//tell the 2nd gameobject about the collision
					CollisionTuple cp2;
					cp2.other = iter1.m_node->value;
					cp2.normal = nMTV * -1.0f;

					iter3.m_node->value->collisions.pushBack(cp2);

					//seperate the objects
					float ratio1 = iter1.m_node->value->mtvBias;
					float ratio2 = iter3.m_node->value->mtvBias;

					float ratioSum = ratio1 + ratio2;

					//test if the objects are both static
					if (ratioSum > 0)
					{
						//get the ratio of the movement to distribute accross both colliders
						float mtv1 = ratio1 / ratioSum;
						float mtv2 = ratio2 / ratioSum;

						//move the objects apart
						iter1.m_node->value->parent->transform->position += collTest.MTV * mtv1;
						iter3.m_node->value->parent->transform->position += collTest.MTV * -mtv2;
					}
				}
			}
		}


	}

}

//renders all game objects
void PlayState::updateRenderers(Application2D* appPtr)
{
	LinkedList<GridRendererComponent*>::Iterator iter = gridRenderers.begin();

	//iterate through all grid renderers
	for (; iter != gridRenderers.end(); iter++)
	{
		iter.m_node->value->render(appPtr);
	}

	LinkedList<RendererComponent*>::Iterator iter2 = renderers.begin();

	//iterate through all renderers
	for (; iter2 != renderers.end(); iter2++)
	{
		iter2.m_node->value->render(appPtr);
	}

}

//give the objects back to the pool
void PlayState::cleanUp()
{
	LinkedList<GameObject*>::Iterator iter = gameObjects.begin();

	//iterate through all gameobjects
	for (; iter != gameObjects.end(); iter++)
	{
		LinkedList<BaseComponent*>::Iterator compIter = iter.m_node->value->components.begin();

		for (; compIter != iter.m_node->value->components.end(); compIter++)
		{
			ScriptComponent* script = dynamic_cast<ScriptComponent*>(compIter.m_node->value);

			if (script != nullptr)
			{
				delete script;
			}
		}

		iter.m_node->value->components.clear();
		poolPtr->removeObject("gameObject", iter.m_node->value);
	}

	gameObjects.clear();

	LinkedList<TransformComponent*>::Iterator iter2 = transforms.begin();

	//iterate through all transforms
	for (; iter2 != transforms.end(); iter2++)
	{
		poolPtr->removeObject("transform", iter2.m_node->value);
	}

	transforms.clear();

	LinkedList<ColliderComponent*>::Iterator iter3 = colliders.begin();

	//iterate through all colliders
	for (; iter3 != colliders.end(); iter3++)
	{
		poolPtr->removeObject("collider", iter3.m_node->value);
	}

	colliders.clear();

	LinkedList<RendererComponent*>::Iterator iter4 = renderers.begin();

	//iterate through all renderers
	for (; iter4 != renderers.end(); iter4++)
	{
		poolPtr->removeObject("renderer", iter4.m_node->value);
	}

	renderers.clear();

	LinkedList<GridColliderComponent*>::Iterator iter5 = gridColliders.begin();

	//iterate through all grids
	for (; iter5 != gridColliders.end(); iter5++)
	{
		delete iter5.m_node->value;
	}

	gridColliders.clear();

	LinkedList<GridRendererComponent*>::Iterator iter6 = gridRenderers.begin();

	//iterate through all grids
	for (; iter6 != gridRenderers.end(); iter6++)
	{
		delete iter6.m_node->value;
	}

	gridRenderers.clear();

	scripts.clear();
}

