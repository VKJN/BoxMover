#pragma once
#include <SFML/Graphics.hpp>

class Player {
private:
	sf::RectangleShape player;
public:
	Player(sf::Vector2f startPosition);
	void move(int direction);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
};