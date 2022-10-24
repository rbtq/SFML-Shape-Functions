#include "Arc.h"

//constructor
Arc::Arc(sf::Vector2f centre, float startAngle, float endAngle, int resolution) : GenericShape(resolution - 1) {
	//make the arc
	float currentInteriorAngle = startAngle;
	float interiorAngleIncrement;
	//first calculate the interior angle
	interiorAngleIncrement = ((float)(endAngle - startAngle) / resolution) * 3.1415926535f / 180.0f;

	//now calculate the outer edge locations using cos and sin
	for (int i = 0; i < resolution; i++) {
		verticies[i].position = sf::Vector2f(centre.x + 100 * sin(currentInteriorAngle), centre.y + 100 * cos(currentInteriorAngle));
		currentInteriorAngle += interiorAngleIncrement;
	}

	shapeCentre = centre;

	CalculateDataFromCentre();

}