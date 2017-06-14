#include "PlayState.h"
#include "Application2D.h"
#include "CollisionSolver.h"

//simulates one frame of the play state
void PlayState::update(Application2D* appPtr, float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

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

	//instantiating the game object
	GameObject* player = (GameObject*)poolPtr->requestObject("gameObject");

	//instantiating individual components
	TransformComponent* transform = (TransformComponent*)poolPtr->requestObject("transform");
	ColliderComponent* collider = (ColliderComponent*)poolPtr->requestObject("collider");
	RendererComponent* renderer = (RendererComponent*)poolPtr->requestObject("renderer");

	renderer->textureRes = (TextureResource*)RESOURCE_MAN->requestResource(ResourceType::TEXTURE, "blue_box.png");
	renderer->region = AABB(Vector2(-0.2, -0.2), Vector2(0.2, 0.2));

	transform->position = Vector2(0.5, 0.5);

	//linking the components
	player->components.pushBack(transform);
	player->components.pushBack(collider);
	player->components.pushBack(renderer);

	//setting up
	player->initialise(appPtr);

	//linking the components to the play state
	gameObjects.pushBack(player);
	transforms.pushBack(transform);
	colliders.pushBack(collider);
	renderers.pushBack(renderer);

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
	}

}

//renders all game objects
void PlayState::updateRenderers(Application2D* appPtr)
{
	LinkedList<RendererComponent*>::Iterator iter = renderers.begin();

	//iterate through all renderers
	for (; iter != renderers.end(); iter++)
	{
		iter.m_node->value->render(appPtr);
	}

}

//give the objects back to the pool
void PlayState::cleanUp()
{
	LinkedList<GameObject*>::Iterator iter = gameObjects.begin();

	//iterate through all gameobjects
	for (; iter != gameObjects.end(); iter++)
	{
		poolPtr->removeObject("gameObject", iter.m_node->value);
	}


	LinkedList<TransformComponent*>::Iterator iter2 = transforms.begin();

	//iterate through all transforms
	for (; iter2 != transforms.end(); iter2++)
	{
		poolPtr->removeObject("transform", iter2.m_node->value);
	}


	LinkedList<ScriptComponent*>::Iterator iter3 = scripts.begin();

	//iterate through all scripts
	for (; iter3 != scripts.end(); iter3++)
	{
		poolPtr->removeObject("script", iter3.m_node->value);
	}


	LinkedList<ColliderComponent*>::Iterator iter4 = colliders.begin();

	//iterate through all colliders
	for (; iter4 != colliders.end(); iter4++)
	{
		poolPtr->removeObject("collider", iter4.m_node->value);
	}


	LinkedList<RendererComponent*>::Iterator iter5 = renderers.begin();

	//iterate through all renderers
	for (; iter5 != renderers.end(); iter5++)
	{
		poolPtr->removeObject("renderer", iter5.m_node->value);
	}
}
