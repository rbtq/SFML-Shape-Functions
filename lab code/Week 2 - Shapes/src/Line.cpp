#include "Line.h"

//constructor
Line::Line(sf::Vector2f centre,std::vector<sf::Vector2f> points) : GenericShape(points.size()) {

	//setup centre
	shapeCentre = centre;

	//setup every point's position
	for (int i = 0; i < points.size(); i++) {

		verticies[i].position = centre + points[i];

	}

	//std::cout << "[NOTICE] Centre index: " << centreIndex << std::endl;

	CalculateDataFromCentre();

	//debug
	//for (int i = 0; i < verticiesAngleFromCentre.size(); i++) {
	//	std::cout << "[NOTICE] Angles from centre: " << verticiesAngleFromCentre[i] << std::endl;
	//}

}


//alternate constructor
Line::Line(sf::Vector2f positionOne, sf::Vector2f positionTwo) : GenericShape(2) {
	//setup values
	verticies[0].position = positionOne;
	verticies[1].position = positionTwo;
	//calculate the centre for rotation
	shapeCentre = sf::Vector2f((positionOne.x + positionTwo.x) / 2, (positionOne.y + positionTwo.y) / 2);

	CalculateDataFromCentre();

}