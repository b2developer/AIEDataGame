#pragma once

/*
* struct MovementState
*
* defines the physics of the player's movement
* when in a specific state
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
struct MovementState
{
	float accel = 1.0f; //change in velocity per second
	float maxSpeed = 1.0f; //maximum movement speed
	float friction = 1.0f; //friction scalar imposed per second

	/*
	* MovementState()
	* default constructor
	*/
	MovementState() {};

	/*
	* MovementState()
	* constructor, intialises all variables
	*/
	MovementState(float accel_, float maxSpeed_, float friction_) : accel(accel_), maxSpeed(maxSpeed_), friction(friction_) {}

};
