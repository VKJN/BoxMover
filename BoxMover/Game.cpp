#include "Game.h"
#include <Windows.h>
#include <ctime>
#include <set>

#define random(a,b) (a+rand()%(b+1-a))

void Game::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		sf::Vector2f pPos = player.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) == 2) {
				for (auto& box : boxes) {
					if (box.getPosition().x == pPos.x && box.getPosition().y == pPos.y - 32 && box.getPosition().y > 0 
						&& map.getElementByPosition(box.getPosition().x / 32, (box.getPosition().y - 32) / 32) < 2) 
					{
						map.changeMask(box.getPosition().x / 32, box.getPosition().y / 32, 0);
						box.setPosition(sf::Vector2f(box.getPosition().x, box.getPosition().y - 32));
						map.changeMask(box.getPosition().x / 32, box.getPosition().y / 32, 2);
						break;
					}
				}
			}
			playerMoveDirection = 1;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) == 2) {
				for (auto& box : boxes) {
					if (box.getPosition().x == pPos.x + 32 && box.getPosition().y == pPos.y && box.getPosition().x < 960 - 32
						&& map.getElementByPosition((box.getPosition().x + 32) / 32, box.getPosition().y / 32) < 2) 
					{
						map.changeMask(box.getPosition().x / 32, box.getPosition().y / 32, 0);
						box.setPosition(sf::Vector2f(box.getPosition().x + 32, box.getPosition().y));
						map.changeMask(box.getPosition().x / 32, box.getPosition().y / 32, 2);
						break;
					}
				}
			}
			playerMoveDirection = 2;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) == 2) {
				for (auto& box : boxes) {
					if (box.getPosition().x == pPos.x && box.getPosition().y == pPos.y + 32 && box.getPosition().y < 640 - 32
						&& map.getElementByPosition(box.getPosition().x / 32, (box.getPosition().y + 32) / 32) < 2) 
					{
						map.changeMask(box.getPosition().x / 32, box.getPosition().y / 32, 0);
						box.setPosition(sf::Vector2f(box.getPosition().x, box.getPosition().y + 32));
						map.changeMask(box.getPosition().x / 32, box.getPosition().y / 32, 2);
						break;
					}
				}
			}
			playerMoveDirection = 3;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) == 2) {
				for (auto& box : boxes) {
					if (box.getPosition().x == pPos.x - 32 && box.getPosition().y == pPos.y && box.getPosition().x > 0
						&& map.getElementByPosition((box.getPosition().x - 32) / 32, box.getPosition().y / 32) < 2) 
					{
						map.changeMask(box.getPosition().x / 32, box.getPosition().y / 32, 0);
						box.setPosition(sf::Vector2f(box.getPosition().x - 32, box.getPosition().y));
						map.changeMask(box.getPosition().x / 32, box.getPosition().y / 32, 2);
						break;
					}
				}
			}
			playerMoveDirection = 4;
		}

		else {
			playerMoveDirection = 0;
		}

		for (int i = 0; i < boxes.size(); i++) {
			for (int j = 0; j < buttons.size(); j++) {
				if (boxes[i].getPosition() == buttons[j].getPosition()) {
					map.changeMask(boxes[i].getPosition().x / 32, boxes[i].getPosition().y / 32, 10);
				}
			}
		}

		if (map.getCount(10) == buttons.size()) {
			window.close();
			std::cout << "You win";
		}
	}
}

void Game::update(sf::Time deltaTime) {
	sf::Vector2f pPos = player.getPosition();

	switch (playerMoveDirection) {
	case 1:
		if (pPos.y > 0 && map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) == 0) player.move(1);
		break;
	case 2:
		if (pPos.x < 960 - 32 && map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) == 0) player.move(2);
		break;
	case 3:
		if (pPos.y < 640 - 32 && map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) == 0)player.move(3);
		break;
	case 4:
		if (pPos.x > 0 && map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) == 0) player.move(4);
		break;
	}

	if (playerMoveDirection != 0) {
		lastFaced = playerMoveDirection;
	}

	Sleep(deltaTime.asSeconds());
}

void Game::render() {
	window.clear();

	map.draw(window);

	player.draw(window);

	for (auto button : buttons) {
		button.draw(window);
	}
	for (auto box : boxes) {
		box.draw(window);
	}


	window.display();
}

void Game::setCoordForBoxAndButton(int index, int countBox) {
	if (index == 1) {
		for (int i = 0; i < countBox; i++) {

			int maxX = window.getSize().x - 64;
			int maxY = window.getSize().y - 64;

			int boxX, boxY;

			do {
				boxX = random(32, maxX);
				boxY = random(32, maxY);

			} while (boxX % 32 != 0 || boxY % 32 != 0 || player.getPosition() == sf::Vector2f(boxX, boxY) || map.getElementByPosition(boxX / 32, boxY / 32) != 0);

			Box box(sf::Vector2f(boxX, boxY));
			boxes.push_back(box);
			map.changeMask(boxX / 32, boxY / 32, 2);
		}
	}

	else {
		for (int i = 0; i < countBox; i++) {

			int maxX = window.getSize().x - 64;
			int maxY = window.getSize().y - 64;

			int buttonX, buttonY;

			do {
				buttonX = random(0, maxX - 32);
				buttonY = random(0, maxY - 32);

			} while (buttonX % 32 != 0 || buttonY % 32 != 0 || player.getPosition() == sf::Vector2f(buttonX, buttonY) || map.getElementByPosition(buttonX / 32, buttonY / 32) != 0);

			Button button(sf::Vector2f(buttonX, buttonY));
			buttons.push_back(button);
			map.changeMask(buttonX / 32, buttonY / 32, 1);
		}
	}
}

Game::Game() :
	window(sf::VideoMode(960, 640), "Box mover"),
	player(sf::Vector2f(9 * 32, 6 * 32)),
	map(960, 640)
{
	int countBox = random(1, 15);
	setCoordForBoxAndButton(1, countBox);
	setCoordForBoxAndButton(2, countBox);
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}