#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>

//base class for deriving subclasses from
class GenericShape {
protected:
	//vars
	sf::VertexArray verticies;
	sf::Vector2f shapeCentre;
	sf::Vector2f transformation;
	std::vector<float> verticiesDistanceFromCentre;
	std::vector<float> verticiesAngleFromCentre;

	//setup function for rotation
	void CalculateDataFromCentre();
	//setup function for regular shapes
	void CreateRegularShape(int vertexCount, sf::Vector2f centre, int size, int angle);
	//constructor
	GenericShape(int vertexCount);

public:

	//for drawing the shape
	void Draw(sf::RenderWindow* window);
	//all shapes can rotate
	void Rotate(float angle);
	void Move(sf::Vector2f distance);



};