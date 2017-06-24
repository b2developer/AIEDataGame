#include "FlagScript.h"
#include "PlayerScript.h"
#include "Application2D.h"

//initialises the script, runs once
void FlagScript::initialise()
{
	collider = parent->getComponentsOfType<ColliderComponent>()[0];
}

//runs once per frame in the play state
void FlagScript::update(Application2D * appPtr, float deltaTime)
{
	//iterate through all collisions
	for (int i = 0; i < (int)collider->collisions.size; i++)
	{
		CollisionTuple coll = collider->collisions[i];

		LinkedList<PlayerScript*> playerScripts = coll.other->parent->getComponentsOfType<PlayerScript>();

		//does the gameobject contain a player component (ie. is it a player?)
		if (playerScripts.size > 0)
		{
			//win the game by cleaning it up
			playState->win(appPtr);
			return;
		}
	}
}
