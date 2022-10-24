#include "Octagon.h"

//constructor
Octagon::Octagon(sf::Vector2f centre, float size, float angle) : GenericShape(8) {
	//number of verticies in a hexagon
	static const int VERTICIES_COUNT = 8;

	//create the octagon
	CreateRegularShape(VERTICIES_COUNT, centre, size, angle);

	//calculate distances from centre
	CalculateDataFromCentre();


}