#include "Triangle.h"

//constructor
Triangle::Triangle(sf::Vector2f position, int baseLength, int height) : GenericShape(3) {
	//setup triangle

	verticies[0].position = position;
	verticies[1].position = sf::Vector2f(position.x + baseLength, position.y);
	verticies[2].position = sf::Vector2f(position.x + baseLength / 2, position.y + height);
	verticies[3].position = position;
	//find the centre
	shapeCentre = sf::Vector2f(position.x + baseLength / 2, position.y + height / 2);

	CalculateDataFromCentre();

}