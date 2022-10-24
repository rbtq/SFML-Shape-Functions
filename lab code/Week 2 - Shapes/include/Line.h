#pragma once
#include "GenericShape.h"

//class for lines
class Line : public GenericShape {
public:
	//constructors
	Line(sf::Vector2f centre,std::vector<sf::Vector2f> points);
	Line(sf::Vector2f positionOne, sf::Vector2f positionTwo);


};