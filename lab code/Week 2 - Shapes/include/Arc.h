#pragma once
#include "GenericShape.h"
//class for arcs
class Arc : public GenericShape {
public:
	//constructor
	Arc(sf::Vector2f centre, float startAngle, float endAngle, int resolution);



};