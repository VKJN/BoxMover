#include "Player.h"

Player::Player(sf::Vector2f startPosition) {
	player.setSize(sf::Vector2f(30.f, 30.f));
	player.setFillColor(sf::Color(175, 30, 75));
	player.setPosition(startPosition);
	player.setOutlineColor(sf::Color::Black);
	player.setOutlineThickness(2);
}

void Player::move(int direction) {
	// 1 - up; 2 - right; 3 - down; 4 - left
	switch (direction) {
	case 1:
		player.move(sf::Vector2f(0, -32));
		break;
	case 2:
		player.move(sf::Vector2f(32, 0));
		break;
	case 3:
		player.move(sf::Vector2f(0, 32));
		break;
	case 4:
		player.move(sf::Vector2f(-32, 0));
		break;
	}
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}

sf::Vector2f Player::getPosition() {
	return player.getPosition();
}