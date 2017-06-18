#include "PlayerBuilder.h"
#include "Factory.h"
#include "PlayState.h"
#include "Application2D.h"
#include "EntityScript.h"

//sets gameObject related variables
void PlayerBuilder::setObject(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	playState->gameObjects.pushBack(gameObject);
	gameObject->thisNode = playState->gameObjects.endNode(); //set the linked node
}

//sets transform component variables
void PlayerBuilder::setTransform(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	TransformComponent* transform = (TransformComponent*)appPtr->m_pool->requestObject("transform");
	gameObject->components.pushBack(transform); //add the transform component to the gameobject
	playState->transforms.pushBack(transform); 
	transform->thisNode = playState->transforms.endNode();

	gameObject->transform = transform;
}			

//sets script component variables
void PlayerBuilder::setScript(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	ScriptComponent* entity = FACT->createObject<EntityScript>();
	gameObject->components.pushBack(entity); //add the polymoprhic script component to the gameobject
	playState->scripts.pushBack(entity);
	entity->thisNode = playState->scripts.endNode();
}

//sets collider component variables
void PlayerBuilder::setCollider(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	ColliderComponent* collider = (ColliderComponent*)appPtr->m_pool->requestObject("collider");
	gameObject->components.pushBack(collider); //add the collider component to the gameobject
	playState->colliders.pushBack(collider);
	collider->thisNode = playState->colliders.endNode();
}

//sets renderer component variables
void PlayerBuilder::setRenderer(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	RendererComponent* renderer = (RendererComponent*)appPtr->m_pool->requestObject("renderer");
	gameObject->components.pushBack(renderer); //add the renderer component to the gameobject
	playState->renderers.pushBack(renderer);
	renderer->thisNode = playState->renderers.endNode();
}

//sets additional component variables
void PlayerBuilder::setExtension(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	gameObject->initialise(appPtr);
}
