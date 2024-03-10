#include "Box.h"

int Box::Uniqindex = 1;

Box::Box(sf::Vector2f startPosition) {
	box.setSize(sf::Vector2f(30.f, 30.f));
	box.setFillColor(sf::Color(69, 52, 42));
	box.setPosition(startPosition);
	box.setOutlineColor(sf::Color::Black);
	box.setOutlineThickness(2);

	this->index = Uniqindex++;
}

void Box::draw(sf::RenderWindow& window) {
	window.draw(box);
}

void Box::movement(int direction) {
	// 1 - up; 2 - right; 3 - down; 4 - left
	switch (direction) {
	case 1:
		box.move(sf::Vector2f(0, -32));
		break;
	case 2:
		box.move(sf::Vector2f(32, 0));
		break;
	case 3:
		box.move(sf::Vector2f(0, 32));
		break;
	case 4:
		box.move(sf::Vector2f(-32, 0));
		break;
	}
}

int Box::getIndex() {
	return index;
}

void Box::setPosition(sf::Vector2f position) {
	box.setPosition(position);
}

sf::Vector2f Box::getPosition() {
	return box.getPosition();
}
