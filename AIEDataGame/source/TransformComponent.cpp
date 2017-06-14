#include "TransformComponent.h"
#include "GameObject.h"

//initialise the transform component
void TransformComponent::initialise()
{
	parent->transform = this;
}

//sets the origin of the transform component
void TransformComponent::setRelative(TransformComponent other)
{
	position = position - other.position;
}

//sets the origin of the transform component with a vector
void TransformComponent::setRelative(Vector2 other)
{
	position = position - other;
}
