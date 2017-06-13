#include "TransformComponent.h"
#include "GameObject.h"

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
