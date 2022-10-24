#include "Hexagon.h"

//constructor
Hexagon::Hexagon(sf::Vector2f centre, float size, float angle) : GenericShape(6) {

	//number of verticies in a hexagon
	static const int VERTICIES_COUNT = 6;

	//create the hexagon
	CreateRegularShape(VERTICIES_COUNT, centre, size, angle);

	//calculate distances from centre
	CalculateDataFromCentre();


}