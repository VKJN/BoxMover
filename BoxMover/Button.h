#pragma once
#include <SFML/Graphics.hpp>

class Button {
	sf::RectangleShape button;

	static int Uniqindex;
	int index;
public:
	Button(sf::Vector2f startPosition);
	void draw(sf::RenderWindow& window);
	void movement(int direction);
	int getIndex();
	sf::Vector2f getPosition();
};