#include "Button.h"

Button::Button(sf::Vector2f startPosition) {
	button.setSize(sf::Vector2f(30.f, 30.f));
	button.setFillColor(sf::Color::White);
	button.setPosition(startPosition);
	button.setOutlineColor(sf::Color::Black);
	button.setOutlineThickness(2);
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(button);
}

void Button::movement(int direction) {
	// 1 - up; 2 - right; 3 - down; 4 - left
	switch (direction) {
	case 1:
		button.move(sf::Vector2f(0, -32));
		break;
	case 2:
		button.move(sf::Vector2f(32, 0));
		break;
	case 3:
		button.move(sf::Vector2f(0, 32));
		break;
	case 4:
		button.move(sf::Vector2f(-32, 0));
		break;
	}
}

sf::Vector2f Button::getPosition() {
	return button.getPosition();
}
