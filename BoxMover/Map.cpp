#include "Map.h"
#include <iostream>
using namespace std;

Map::Map(int width, int height)
	: field(sf::Vector2f(width, height))
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			maskTiles[i][j].setSize(sf::Vector2f(32.f, 32.f));
			maskTiles[i][j].setFillColor(sf::Color(120, 100, 90));
			maskTiles[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
			maskTiles[i][j].setOutlineColor(sf::Color::Black);
			maskTiles[i][j].setOutlineThickness(2);
		}
	}
}

int Map::getElementByPosition(int x, int y) {
	return mask[y][x];
}

void Map::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			window.draw(maskTiles[i][j]);
		}
	}
}

void Map::changeMask(int x, int y, int value) {
	mask[y][x] = value;
}

sf::RectangleShape Map::getField() {
	return field;
}

int Map::getCount(int value) {
	int count = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			if (mask[i][j] == 10) {
				count++;
			}
		}
	}
	return count;
}