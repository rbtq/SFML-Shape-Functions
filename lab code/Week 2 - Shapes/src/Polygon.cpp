#include "Polygon.h"

//constructor for polygons (custom)
Polygon::Polygon(sf::Vector2f centre, std::vector<sf::Vector2f> points) {
	//+1 needed for the final point
	verticies.resize(points.size() + 1);
	verticies.setPrimitiveType(sf::LineStrip);
	shapeCentre = centre;

	//set up the vertices position except the final one
	for (int i = 0; i < verticies.getVertexCount() - 1; i++) {
		verticies[i].position = centre + points[i];
	}

	//connect the final and first points together
	verticies[verticies.getVertexCount() - 1].position = verticies[0].position;

	//calculate some data
	CalculateDataFromCentre();

}