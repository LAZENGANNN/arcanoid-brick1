#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct Brick{
	sf::RectangleShape shape;
	sf::Vector2f position;
	sf::Color color;
};

void initBrick(Brick& brick, sf::Color color, ) {

	brick.shape.setSize(BRICK_SIZE);
	brick.shape.setPosition(0, 0);
	brick.shape.setFillColor(/*{rand()%(335), (rand()%(335), (rand()%(335) }*/{50, 100, 150});
}


void updateBrick() {

}

void drawBrick(sf::RenderWindow& window, const Brick& brick) {
	window.draw(brick.shape);
}