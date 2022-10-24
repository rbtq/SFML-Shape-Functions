#include "Square.h"
//constructor
Square::Square(sf::Vector2f centre, float size, float angle) : GenericShape(4) {
	
	//number of verticies in a square
	static const int VERTICIES_COUNT = 4;

	//create the square
	CreateRegularShape(VERTICIES_COUNT, centre, size, angle);

	//calculate distances from centre
	CalculateDataFromCentre();


}
