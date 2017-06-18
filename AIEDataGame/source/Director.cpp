#include "Director.h"
#include "Application2D.h"
#include "PlayState.h"

//calls upon the stored builder to create the gameobject
GameObject * Director::buildGameObject(Application2D* appPtr, PlayState* playState)
{
	//request a gameobject from the pool or factory
	GameObject* object = (GameObject*)appPtr->m_pool->requestObject("gameObject");

	//command the builder to build up the gameobject
	builder->setObject(appPtr, playState, object);
	builder->setTransform(appPtr, playState, object);
	builder->setScript(appPtr, playState, object);
	builder->setCollider(appPtr, playState, object);
	builder->setRenderer(appPtr, playState, object);
	builder->setExtension(appPtr, playState, object);

	return object;
}
