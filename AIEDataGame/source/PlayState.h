#pragma once
#include "GameState.h"
#include "PushAction.h"

#include "Pool.h"

#include "GameObject.h"

#include "BaseComponent.h"
#include "TransformComponent.h"
#include "ScriptComponent.h"
#include "ColliderComponent.h"
#include "RendererComponent.h"
#include "GridColliderComponent.h"
#include "GridRendererComponent.h"

//type for objects that the playstate stores pointers to
enum class ObjectType
{
	GAMEOBJECT,
	TRANSFORM,
	SCRIPT,
	COLLIDER,
	RENDERER,
};

/*
* class PlayState
* child class of GameState
*
* abstract class for a snapshot of gameplay that can be
* used to actually play the game, pause it and resume it
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class PlayState : public GameState
{
public:

	PushAction* pauseAct; //defined action that pauses the game
	PushAction* winAct; //defined action that displays the win state

	Pool* poolPtr = nullptr; //pointer to the pool, used to grab and save objects from/to

	LinkedList<GameObject*> gameObjects = LinkedList<GameObject*>(0);
	LinkedList<TransformComponent*> transforms = LinkedList<TransformComponent*>(0);
	LinkedList<ScriptComponent*> scripts = LinkedList<ScriptComponent*>(0);
	LinkedList<ColliderComponent*> colliders = LinkedList<ColliderComponent*>(0);
	LinkedList<RendererComponent*> renderers = LinkedList<RendererComponent*>(0);
	LinkedList<GridColliderComponent*> gridColliders = LinkedList<GridColliderComponent*>(0);
	LinkedList<GridRendererComponent*> gridRenderers = LinkedList<GridRendererComponent*>(0);

	bool isFinished = false;

	/*
	* PlayState()
	* default constructor
	*/
	PlayState() {};

	/*
	* ~PlayState()
	* default destructor
	*/
	~PlayState() {};

	/*
	* update
	* overrides GameState's update(float deltaTime)
	*
	* simulates one frame of the gamestate
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void update(Application2D* appPtr, float deltaTime) override;

	/*
	* draw
	* overrides GameState's draw()
	*
	* renders the gamestate
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @returns void
	*/
	void draw(Application2D* appPtr) override;

	/*
	* onEnter
	* overrides GameState's onEnter()
	*
	* called when the gamestate becomes the uppermost gamestate in the stack
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @returns void
	*/
	void onEnter(Application2D* appPtr) override;

	/*
	* onExit
	* overrides GameState's onExit()
	*
	* called when the gamestate is no longer the uppermost gamestate in the stack
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @returns void
	*/
	void onExit(Application2D* appPtr) override;

	/*
	* updateScripts
	*
	* all script component logic gets run within this function
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void updateScripts(Application2D* appPtr, float deltaTime);

	/*
	* updateColliders
	*
	* all collider component logic gets run within this function
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void updateColliders(Application2D* appPtr, float deltaTime);

	/*
	* updateRenderers
	*
	* all renderer logic gets run within this function
	*
	* @param Application2D* appPtr - pointer to the application that this was called from
	* @returns void
	*/
	void updateRenderers(Application2D* appPtr);

	/*
	* cleanUp
	*
	* gives back all instances used by this play state
	* to the pool, completely wipes all lists of game related objects
	*
	* @returns void
	*/
	void cleanUp();

	/*
	* destroy
	*
	* removes a gameobject from the game state
	* deletes all unnecessary components, stores
	* important components back into the pool that
	* they came from
	*
	* @param GameObject* gameObject - pointer to the gameObject to remove
	* @returns void
	*/
	void destroy(GameObject* gameObject);
	
	/*
	* win
	*
	* resets the game
	* displays the win state
	*
	* @param Application2D* appPtr - pointer to the application
	* @returns void
	*/
	void win(Application2D* appPtr);
	
};