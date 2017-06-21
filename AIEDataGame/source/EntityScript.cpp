#include "EntityScript.h"
#include "Application2D.h"
#include "ScriptComponent.h"
#include "TransformComponent.h"


//initialises the script, runs once
void EntityScript::initialise()
{
	collider = parent->getComponentsOfType<ColliderComponent>()[0];
}

//called every frame
void EntityScript::update(Application2D * appPtr, float deltaTime)
{

	velocity += gravity * deltaTime; //apply gravity

	//iterate through all collisions
	for (int i = 0; i < (int)collider->collisions.size; i++)
	{
		float nDot = -velocity.dot(collider->collisions[i].normal);

		if (nDot > 0)
		{
			velocity += collider->collisions[i].normal * nDot;
		}
	}

	parent->transform->position += velocity * deltaTime; //move the entity
}
