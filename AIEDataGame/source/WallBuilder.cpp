#include "WallBuilder.h"
#include "Factory.h"
#include "PlayState.h"
#include "Application2D.h"

//sets gameObject related variables
void WallBuilder::setObject(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	playState->gameObjects.pushBack(gameObject);
	gameObject->thisNode = playState->gameObjects.endNode(); //set the linked node
	gameObject->playState = playState;
}

//sets transform component variables
void WallBuilder::setTransform(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	TransformComponent* transform = (TransformComponent*)appPtr->m_pool->requestObject("transform");
	gameObject->components.pushBack(transform); //add the transform component to the gameobject
	playState->transforms.pushBack(transform);
	transform->thisNode = playState->transforms.endNode();

	gameObject->transform = transform;
}

//sets script component variables
void WallBuilder::setScript(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	
}

//sets collider component variables
void WallBuilder::setCollider(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	ColliderComponent* collider = (ColliderComponent*)appPtr->m_pool->requestObject("collider");
	gameObject->components.pushBack(collider); //add the collider component to the gameobject
	playState->colliders.pushBack(collider);
	collider->thisNode = playState->colliders.endNode();
}

//sets renderer component variables
void WallBuilder::setRenderer(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	RendererComponent* renderer = (RendererComponent*)appPtr->m_pool->requestObject("renderer");
	gameObject->components.pushBack(renderer); //add the renderer component to the gameobject
	playState->renderers.pushBack(renderer);
	renderer->thisNode = playState->renderers.endNode();
}

//sets additional component variables
void WallBuilder::setExtension(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	gameObject->initialise(appPtr);
}
