#pragma once
#include "GenericShape.h"

//class for any shape someone desires to make
class Polygon : public GenericShape {
public:
	//constructor
	//points are drawn relative to centre, shape is automatically connected after the series
	//of points
	Polygon(sf::Vector2f centre, std::vector<sf::Vector2f> points);



};