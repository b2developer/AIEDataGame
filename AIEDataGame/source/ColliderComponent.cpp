#include "ColliderComponent.h"

//adds a vector to the AABB
void ColliderComponent::add(Vector2 position)
{
	region.min_ += position;
	region.max_ += position;
}
