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
	bool grounded = false;

	LinkedList<ColliderComponent*> colls = parent->getComponentsOfType<ColliderComponent>();

	velocity += gravity * deltaTime; //apply gravity

	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		velocity.x -= 1.5f * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		velocity.x += 1.5f * deltaTime;
	}

	velocity.x *= 0.95f;

	//iterate through all collisions
	for (int i = 0; i < colls[0]->collisions.size; i++)
	{
		if ((colls[0]->collisions[i].normal - Vector2(0,1)).sqrMagnitude() < 0.0001f)
		{
			grounded = true;
		}

		velocity += colls[0]->collisions[i].normal * -velocity.dot(colls[0]->collisions[i].normal);
	}

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		if (grounded)
		{
			velocity.y = 0.7f;
		}
	}

	parent->transform->position += velocity * deltaTime; //move the entity
}
