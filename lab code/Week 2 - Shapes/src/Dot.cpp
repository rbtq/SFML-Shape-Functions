#include "Dot.h"

//constructor
Dot::Dot(sf::Vector2f position) : GenericShape(1) {
	//set up the dot
	verticies[0].position = position;
	shapeCentre = position;

	CalculateDataFromCentre();

}