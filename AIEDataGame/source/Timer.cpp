#include "Timer.h"
#include "Application2D.h"

//resets the timer
void Timer::begin()
{
	currentTime = maxTime;
}

//simulates one frame of the timer
void Timer::update(Application2D * appPtr, float deltaTime)
{
	//the timer has counted down already, early exit
	if (currentTime == 0.0f)
	{
		return;
	}

	//tick down time
	currentTime -= deltaTime;

	//if time is below 0, clamp it to 0
	if (currentTime < 0.0f)
	{
		LinkedList<Action*>::Iterator iter = reactions.begin();

		//iterate through the action list
		for (; iter != reactions.end(); iter++)
		{
			//execute the action
			iter.m_node->value->execute(appPtr);
		}

		currentTime = 0.0f;
	}
}
