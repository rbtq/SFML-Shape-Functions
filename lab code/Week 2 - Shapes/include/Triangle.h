#pragma once
#include "GenericShape.h"

//class for drawing triangles
class Triangle : public GenericShape {
public:
	//constructor
	Triangle(sf::Vector2f position, int baseLength, int height);

};