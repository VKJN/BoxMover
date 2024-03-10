#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Box.h"
#include "Map.h"
#include "Button.h"

class Game {
private:
	sf::RenderWindow window;

	Map map;
	Player player;
	std::vector<Box> boxes;
	std::vector<Button> buttons;

	int lastFaced = 0; // 1 - up; 2 - right; 3 - down; 4 - left
	int playerMoveDirection = 0;
	const sf::Time TimePerFrame = sf::seconds(1.f / 10.f);

	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	void setCoordForBoxAndButton(int index, int countBox);
public:
	Game();
	void run();
};