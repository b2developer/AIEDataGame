#include "LevelBuilder.h"
#include "Factory.h"
#include "PlayState.h"
#include "Application2D.h"
#include "EntityScript.h"

//sets gameObject related variables
void LevelBuilder::setObject(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	playState->gameObjects.pushBack(gameObject);
	gameObject->thisNode = playState->gameObjects.endNode(); //set the linked node
	gameObject->playState = playState;
}

//sets transform component variables
void LevelBuilder::setTransform(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	TransformComponent* transform = (TransformComponent*)appPtr->m_pool->requestObject("transform");
	gameObject->components.pushBack(transform); //add the transform component to the gameobject
	playState->transforms.pushBack(transform);
	transform->thisNode = playState->transforms.endNode();

	gameObject->transform = transform;
}

//sets script component variables
void LevelBuilder::setScript(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{

}

//sets collider component variables
void LevelBuilder::setCollider(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	GridColliderComponent* collider = new GridColliderComponent();
	gameObject->components.pushBack(collider); //add the collider component to the gameobject
	playState->gridColliders.pushBack(collider);
	collider->thisNode = playState->gridColliders.endNode();
}

//sets renderer component variables
void LevelBuilder::setRenderer(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	GridRendererComponent* renderer = new GridRendererComponent();
	gameObject->components.pushBack(renderer); //add the renderer component to the gameobject
	playState->gridRenderers.pushBack(renderer);
	renderer->thisNode = playState->gridRenderers.endNode();
}

//sets additional component variables
void LevelBuilder::setExtension(Application2D * appPtr, PlayState * playState, GameObject * gameObject)
{
	gameObject->initialise(appPtr);
}
