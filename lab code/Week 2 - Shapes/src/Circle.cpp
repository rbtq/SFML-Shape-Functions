
#include "Circle.h"

//constructor
Circle::Circle(sf::Vector2f centre, float size, float angle) : GenericShape((int)size * 3) {

	//accuracy of the circle
	const int VERTICIES_COUNT = (int)size * 3;

	//construct the circle
	CreateRegularShape(VERTICIES_COUNT, centre, size, 0);

	//calculate distances from centre
	CalculateDataFromCentre();


}