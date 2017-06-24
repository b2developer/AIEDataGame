#include "EnemyScript.h"
#include "Application2D.h"
#include "ScriptComponent.h"
#include "TransformComponent.h"


//initialises the script, runs once
void EnemyScript::initialise()
{
	collider = parent->getComponentsOfType<ColliderComponent>()[0];
}

//called every frame
void EnemyScript::update(Application2D * appPtr, float deltaTime)
{
	bool grounded = false;

	//iterate through all collisions
	for (int i = 0; i < (int)collider->collisions.size; i++)
	{
		CollisionTuple coll = collider->collisions[i];

		//if the normal from the collision is almost a down vector, the player hit the floor
		if ((coll.normal - Vector2(0, 1)).sqrMagnitude() < 0.0001f)
		{
			grounded = true;
		}

		float nDot = -velocity.dot(coll.normal);

		//only reflect the velocity if the collision is not going to be solved on it's own
		if (nDot > 0)
		{
			//negate all velocity that is causing the penetration along the normal
			velocity += coll.normal * nDot;
		}
	}

	MovementState currentState;

	//use the running statistics if the player is grounded, use the air statistics if the player isn't
	if (grounded)
	{
		currentState = run;
	}
	else
	{
		currentState = air;
	}

	//apply gravity
	velocity += gravity * deltaTime;

	aie::Input* input = aie::Input::getInstance();

	//accelerate the player horizontally if they press a key
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		//velocity.x -= currentState.accel * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		//velocity.x += currentState.accel * deltaTime;
	}

	float targetFrameRate = 60.0f;

	//amount of time passed in an ideal frame
	float invTarget = 1 / targetFrameRate;

	//ratio of the time passed to the ideal time passed
	float multiplier = deltaTime / invTarget;

	//take the decayRate to the power
	velocity.x *= powf(currentState.friction, multiplier / targetFrameRate);

	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		if (grounded)
		{
			//velocity.y = jumpPower;
		}
	}

	//move the player
	parent->transform->position += velocity * deltaTime; //move the entity

	//reset the player
	if (parent->transform->position.y < 0)
	{
		parent->transform->position = Vector2(0.5f, 0.5f);
		velocity = Vector2(0, 0);
	}

}