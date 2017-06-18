#include "EntityScript.h"
#include "Application2D.h"
#include "ScriptComponent.h"
#include "TransformComponent.h"


//initialises the script, runs once
void EntityScript::initialise()
{

}

//called every frame
void EntityScript::update(Application2D * appPtr, float deltaTime)
{
	velocity += gravity * deltaTime; //apply gravity

	parent->transform->position += velocity * deltaTime; //move the entity
}
