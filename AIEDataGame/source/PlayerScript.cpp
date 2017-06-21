#include "PlayerScript.h"
#include "Application2D.h"
#include "ScriptComponent.h"
#include "TransformComponent.h"


//initialises the script, runs once
void PlayerScript::initialise()
{
	collider = parent->getComponentsOfType<ColliderComponent>()[0];
}

//called every frame
void PlayerScript::update(Application2D * appPtr, float deltaTime)
{
	bool grounded = false;

	//iterate through all collisions
	for (int i = 0; i < collider->collisions.size; i++)
	{
		//if the normal from the collision is almost a down vector, the player hit the floor
		if ((collider->collisions[i].normal - Vector2(0, 1)).sqrMagnitude() < 0.0001f)
		{
			grounded = true;
		}

		float nDot = -velocity.dot(collider->collisions[i].normal);

		//only reflect the velocity if the collision is not going to be solved on it's own
		if (nDot > 0)
		{
			//negate all velocity that is causing the penetration along the normal
			velocity += collider->collisions[i].normal * nDot;
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
		velocity.x -= currentState.accel * deltaTime;
	}

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		velocity.x += currentState.accel * deltaTime;
	}

	//apply friction (this is a shit way to do this) fhasijhasifiuqweohiuqwhfiqwheiqwefhqweifhqwiouehfiqwouhioqwuehfioqwuehiuqwehfiouqwhiowqehfiowqnkjdsalbjsakdfsajfhasufhwqyeoifg
	velocity.x *= currentState.friction;


	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		if (grounded)
		{
			velocity.y = jumpPower;
		}
	}

	//move the player
	parent->transform->position += velocity * deltaTime; //move the entity

	//set the camera's position to the player
	*camera = parent->transform->position - Vector2(0.5f, 0.5f);

	//clamp the camera
	camera->x = camera->x > 0.0f ? camera->x : 0.0f;
	camera->y = camera->y > 0.0f ? camera->y : 0.0f;
}