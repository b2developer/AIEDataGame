#pragma once
#include "Builder.h"

/*
* class PlayerBuilder
* child class of Builder
*
* responsible for initialising game objects that function as players
* adds a component for handling user input
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class PlayerBuilder : public Builder
{

public:

	/*
	* PlayerBuilder()
	* default constructor
	*/
	PlayerBuilder() {};

	/*
	* ~PlayerBuilder()
	* default destructor
	*/
	~PlayerBuilder() {};

	/*
	* setObject
	* overrides Builder's setObject(Application2D* appPtr, PlayState* playState, GameObject* gameObject)
	*
	* initialises the gameobject core
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
    void setObject(Application2D* appPtr, PlayState* playState, GameObject* gameObject) override;

	/*
	* setTransform
	* overrides Builder's setTransform(Application2D* appPtr, PlayState* playState, GameObject* gameObject)
	*
	* creates and initialises a transfrom component for a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	void setTransform(Application2D* appPtr, PlayState* playState, GameObject* gameObject) override;

	/*
	* setScript
	* overrides Builder's setScript(Application2D* appPtr, PlayState* playState, GameObject* gameObject)
	*
	* creates and initialises script components for a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	void setScript(Application2D* appPtr, PlayState* playState, GameObject* gameObject) override;

	/*
	* setCollider
	* overrides Builder's setCollider(Application2D* appPtr, PlayState* playState, GameObject* gameObject)
	*
	* creates and initialises a collider component for a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	void setCollider(Application2D* appPtr, PlayState* playState, GameObject* gameObject) override;

	/*
	* setRenderer
	* overrides Builder's setRenderer(Application2D* appPtr, PlayState* playState, GameObject* gameObject)
	*
	* creates and initialises a renderer component for a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	void setRenderer(Application2D* appPtr, PlayState* playState, GameObject* gameObject) override;

	/*
	* setExtension
	* overrides Builder's setExtension(Application2D* appPtr, PlayState* playState, GameObject* gameObject)
	*
	* initialises and sets additional properties of a gameobject
	*
	* @param Application2D* appPtr - pointer to the application that called this function
	* @param PlayState* playState - pointer to the playstate that called this function
	* @param GameObject* gameObject - pointer to the gameObject
	* @returns void
	*/
	void setExtension(Application2D* appPtr, PlayState* playState, GameObject* gameObject) override;

};