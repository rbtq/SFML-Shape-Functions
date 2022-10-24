#include "RegularShape.h"

//constructor
RegularShape::RegularShape(int vertexCount, sf::Vector2f centre, int size, int angle) {

	//perform a check first
	if (vertexCount >= 3) {

		//setup vars
		verticies.resize(vertexCount + 1);
		verticies.setPrimitiveType(sf::LineStrip);
		shapeCentre = centre;


		float currentInteriorAngle = angle;
		float interiorAngleIncrement;
		//first calculate the interior angle in radians
		interiorAngleIncrement = (360.0f / vertexCount) * 3.1415926535f / 180.0f;

		//now calculate the outer edge locations using cos and sin
		for (int i = 0; i < vertexCount; i++) {
			verticies[i].position = sf::Vector2f(centre.x + size * sin(currentInteriorAngle), centre.y + size * cos(currentInteriorAngle));

			//std::cout << "[NOTICE] Current angle: " << currentInteriorAngle << std::endl;


			currentInteriorAngle += interiorAngleIncrement;
		}

		//connect the shape together
		verticies[vertexCount].position = verticies[0].position;

		//calculate distances from centre
		CalculateDataFromCentre();

	}
	//not allowing anything with less than 3 vertices to be drawn by this function
	else {
		std::cout << "Shape must have more than 3 vertecies" << std::endl;
	}

}


