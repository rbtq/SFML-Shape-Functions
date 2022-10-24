#pragma once
#include "GenericShape.h"

//class for drawing squares
class Square : public GenericShape {
public:
	//constructor
	Square(sf::Vector2f centre, float size, float angle);

};