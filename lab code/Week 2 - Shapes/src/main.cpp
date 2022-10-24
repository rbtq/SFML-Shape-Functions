/*! \mainpage Lab 2 - Shapes
*
* This program gives you a basic SFML winow in which to draw your shapes.
*
* The classes and files you use are up to you.  
*
* This software froms the basis of your submission for lab book 1
*/

/*! \file main.cpp
* \brief Main file for the application
*
* Contains the entry point of the application 
*/

#include "SFML/Graphics.hpp"
#include "Dot.h"
#include "Line.h"
#include "Square.h"
#include "Triangle.h"
#include "Hexagon.h"
#include "Circle.h"
#include "Arc.h"
#include "Octagon.h"


//#include "RegularShape.h"
//#include "Polygon.h"


int main() //!< Entry point for the application
{
	//SFML vars
	sf::RenderWindow window(sf::VideoMode(1024, 800), "Lab Book 1 - Shapes");
	sf::RenderWindow* pointerToWindow = &window;
	sf::Vector2f direction(1.0f, 0.0f);
	sf::Clock timer;
	window.setFramerateLimit(60);

	float angle = 0.0f;
	float baseRotateSpeed = 0.1f;
	static const float PI = 3.145926f;

	//classes
	//non-regular shapes
	//         //pos
	Dot myDot({ 500,500 });
	//          //centre, points relative to centre
	Line myLine({ 150,150 }, { 300,300 });
	//                  //pos,     base, height
	Triangle myTriangle({ 200,400 }, 100, 300);
	//        //centre, start, stop, resolution
	Arc myArc({ 800,200 }, 0, 190, 30);

	//regular shapes    //     pos,    size,angle
	Hexagon myRegularHexagon({ 500,500 }, 60, 50);
	Square myRegularSquare({ 500,500 }, 100, 50);
	Octagon myRegularOctagon({ 500,500 }, 150, 20);
	Circle myCircle({ 500,500 }, 190, 50);

	//custom shapes   //centre,    
	//Polygon myPolygon({ 200,200 },
		//points relative to centre
		//{ {-15,-20}, {15,-5}, {100,-150}, {30 ,-20},{75,5}, { 40,10 }, {25,20}, {-30, -20} });


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			//handle events
			switch (event.type) {
				case sf::Event::Closed: {
					window.close();
					break;
				}
				//handle key events
				case sf::Event::KeyPressed: {
					switch (event.key.code) {
						case sf::Keyboard::Add: {
							baseRotateSpeed += 0.01f;
							break;
						}					
						case sf::Keyboard::Subtract: {
							baseRotateSpeed -= 0.01f;
							break;
						}
					}

					break;
				}
			}

		}

		//rotate shapes
		angle += baseRotateSpeed;
		if (angle >= PI * 60) angle -= PI * 60;


		//randomly change direction in either x or y after some time

		if (timer.getElapsedTime().asSeconds() > 3.0f) {

			//change direction
			if (direction.x == 1) {
				direction.x = 0;
				direction.y = 1;
			}
			else if (direction.y == 1) {
				direction.y = 0;
				direction.x = -1;
			}
			else if (direction.x == -1) {
				direction.y = -1;
				direction.x = 0;
			}
			else if (direction.y == -1) {
				direction.y = 0;
				direction.x = 1;
			}

			//reset timer
			timer.restart();

		}





		//rotate the shapes
		myRegularHexagon.Rotate(-angle/3);
		myTriangle.Rotate(angle/2);
		myLine.Rotate(-angle);
		myRegularOctagon.Rotate(angle/3);
		myRegularSquare.Rotate(angle / 5);
		myArc.Rotate(-angle / 10);
		//myPolygon.Rotate(angle);

		//move them also
		myLine.Move(direction);
		myTriangle.Move(direction);
		myArc.Move(direction);
		myCircle.Move(direction);
		//myPolygon.Move(direction);

		//clear the display
		window.clear();

		// Do your drawing here
		//draw the shapes
		myRegularSquare.Draw(pointerToWindow);
		myDot.Draw(pointerToWindow);
		myLine.Draw(pointerToWindow);
		myTriangle.Draw(pointerToWindow);
		myRegularHexagon.Draw(pointerToWindow);
		myArc.Draw(pointerToWindow);
		//myPolygon.Draw(pointerToWindow);

		//draw regular shapes
		myRegularHexagon.Draw(pointerToWindow);
		myRegularSquare.Draw(pointerToWindow);
		myRegularOctagon.Draw(pointerToWindow);
		myCircle.Draw(pointerToWindow);

		//update display
		window.display();
	}
}
