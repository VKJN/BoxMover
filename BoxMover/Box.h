#pragma once
#include <SFML/Graphics.hpp>

class Box {
private:
	sf::RectangleShape box;

	static int Uniqindex;
	int index;
public:
	Box(sf::Vector2f startPosition);
	void draw(sf::RenderWindow& window);
	void movement(int direction);
	int getIndex();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
};