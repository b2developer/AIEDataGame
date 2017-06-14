#include "ColliderComponent.h"
#include "GameObject.h"

//initialise the collider component
void ColliderComponent::initialise()
{

}

//adds a vector to the AABB
void ColliderComponent::add(Vector2 position)
{
	region.min_ += position;
	region.max_ += position;
}

//gets the space occupied by the AABB
AABB ColliderComponent::getGlobalAABB()
{
	return AABB(region.min_ + parent->transform->position, region.max_ + parent->transform->position); //add the transform's position
}
