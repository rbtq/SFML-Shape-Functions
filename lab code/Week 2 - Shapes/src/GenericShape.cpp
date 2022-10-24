#include "GenericShape.h"



//constructor
GenericShape::GenericShape(int vertexCount) {

	//size array correctly
	int arraySize = vertexCount + 1;
	verticies.resize(arraySize);

	//now use the correct primative type
	switch (vertexCount) {
		//dots
		case 1: {
			verticies.setPrimitiveType(sf::Points);
			break;
		}
		//lines
		case 2: {
			verticies.setPrimitiveType(sf::Lines);
			break;
		}
		//shapes
		default: {
			verticies.setPrimitiveType(sf::LinesStrip);
			break;
		}
	}
}


//protected function for setup for rotation
void GenericShape::CalculateDataFromCentre() {
	//vars
	float distanceFromCentre = 0.0f;
	float distanceFromCentreX = 0.0f;
	float distanceFromCentreY = 0.0f;
	float angleFromCentre = 0.0f;

	//calculate for every point, required for irregular shapes where this varies
	for (int i = 0; i < verticies.getVertexCount(); i++) {
		distanceFromCentreX = shapeCentre.x - verticies[i].position.x;
		distanceFromCentreY = shapeCentre.y - verticies[i].position.y;


		distanceFromCentre = sqrt(distanceFromCentreX * distanceFromCentreX
							    + distanceFromCentreY * distanceFromCentreY);
		//no distance from centre = no angle
		if (distanceFromCentre != 0) {
			angleFromCentre = acos(distanceFromCentreY / distanceFromCentre);
		}
		else {
			angleFromCentre = 0;
		}

		//if x is negative, the angle is counter clockwise
		if (distanceFromCentreX < 0) angleFromCentre *= -1;

		/*
		if (distanceFromCentreX == -1 && distanceFromCentreY != -1 || 
			distanceFromCentreX != -1 && distanceFromCentreY == -1) {
			angleFromCentre *= -1;
		}*/
		verticiesAngleFromCentre.push_back(angleFromCentre);

		//std::cout << "[NOTICE] Angle from centre to point: " << angleFromCentre * 180.0f/3.14159265f << std::endl;

		//then push to the vector
		verticiesDistanceFromCentre.push_back(distanceFromCentre);
	}

	//first point needs to be in the same place as the last one
	//verticiesDistanceFromCentre.push_back(verticiesDistanceFromCentre[0]);
	//verticiesAngleFromCentre.push_back(verticiesAngleFromCentre[0]);

}



//function for rotation
void GenericShape::Rotate(float angle) {



	//now calculate the new outer edge locations using cos and sin and the distance between
	//the centre and point
	for (int i = 0; i < verticies.getVertexCount(); i++) {
		verticies[i].position = sf::Vector2f(shapeCentre.x + verticiesDistanceFromCentre[i] * sin(verticiesAngleFromCentre[i] + angle),
											 shapeCentre.y + verticiesDistanceFromCentre[i] * cos(verticiesAngleFromCentre[i] + angle));
		//debug
		//std::cout << shapeCentre.x << shapeCentre.y << std::endl;

	}
	//set the last point to the position of the first to complete the series of verticies
	//verticies[verticies.getVertexCount() - 1].position = verticies[0].position;


}

//function for creating a regular shape
void GenericShape::CreateRegularShape(int vertexCount, sf::Vector2f centre, int size, int angle) {

	//perform a check first
	if (vertexCount >= 3) {

		//setup vars
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


//function for moving it
void GenericShape::Move(sf::Vector2f distance) {

	for (int i = 0; i < verticies.getVertexCount(); i++) {
		verticies[i].position += distance;
	}
	//update the centre point
	shapeCentre += distance;

}

//display
void GenericShape::Draw(sf::RenderWindow* window) {
	window->draw(verticies);
}