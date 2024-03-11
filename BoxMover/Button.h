#pragma once
#include <SFML/Graphics.hpp>

class Button {
	sf::RectangleShape button;
public:
	Button(sf::Vector2f startPosition);
	void draw(sf::RenderWindow& window);
	void movement(int direction);
	sf::Vector2f getPosition();
};