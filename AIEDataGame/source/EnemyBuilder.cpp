#include "EnemyBuilder.h"
#include "Factory.h"
#include "PlayState.h"
#include "Application2D.h"
#include "EnemyScript.h"

//sets gameObject related variables
void EnemyBuilder::setObject(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	playState->gameObjects.pushBack(gameObject);
	gameObject->thisNode = playState->gameObjects.endNode(); //set the linked node
	gameObject->playState = playState;
}

//sets transform component variables
void EnemyBuilder::setTransform(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	TransformComponent* transform = (TransformComponent*)appPtr->m_pool->requestObject("transform");
	gameObject->components.pushBack(transform); //add the transform component to the gameobject
	playState->transforms.pushBack(transform);
	transform->thisNode = playState->transforms.endNode();

	gameObject->transform = transform;
}

//sets script component variables
void EnemyBuilder::setScript(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	ScriptComponent* entity = FACT->createObject<EnemyScript> ();

    //give the enemy the statistics of maximum speed, acceleration, jump power and seeking range
	((EnemyScript*)entity)->run = MovementState(3.0f, 0.0f, 0.01f); //give the enemy run statistics
	((EnemyScript*)entity)->air = MovementState(1.5f, 0.0f, 0.05f); //give the enemy air statistics
	((EnemyScript*)entity)->jumpPower = 0.9f; //give the enemy the jump power
	((EnemyScript*)entity)->seekingRange = 0.9f; //give the enemy the seeking range


	gameObject->components.pushBack(entity); //add the polymoprhic script component to the gameobject
	playState->scripts.pushBack(entity);
	entity->thisNode = playState->scripts.endNode();
}

//sets collider component variables
void EnemyBuilder::setCollider(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	ColliderComponent* collider = (ColliderComponent*)appPtr->m_pool->requestObject("collider");
	gameObject->components.pushBack(collider); //add the collider component to the gameobject
	playState->colliders.pushBack(collider);
	collider->thisNode = playState->colliders.endNode();
}

//sets renderer component variables
void EnemyBuilder::setRenderer(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	RendererComponent* renderer = (RendererComponent*)appPtr->m_pool->requestObject("renderer");
	gameObject->components.pushBack(renderer); //add the renderer component to the gameobject
	playState->renderers.pushBack(renderer);
	renderer->thisNode = playState->renderers.endNode();
}

//sets additional component variables
void EnemyBuilder::setExtension(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	gameObject->initialise(appPtr);
}
