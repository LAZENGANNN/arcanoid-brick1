#pragma once
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "settings.h"
#include "bat.h"
#include "ball.h"
#include "brick.h"
#include "textobj.h"

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

bool pointInRect(const Bat& bat, sf::Vector2f point) {
	return (point.x >= bat.shape.getPosition().x && point.x <= bat.shape.getPosition().x + BAT_WIDTH) &&
		(point.y >= bat.shape.getPosition().y && point.y <= bat.shape.getPosition().y + BAT_HEIGHT);
}

void checkCollisions(Ball& ball, Bat& bat) {
	sf::Vector2f midLeft{
			ball.shape.getPosition().x,
			ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};

	if (pointInRect(bat, midBottom))
		ball.speedy = -ball.speedy;
}


//палка


void updateGame(Bat& bat, Ball& ball, sf::RenderWindow& window, TextObj& textobj, int score) {
	batUpdate(bat);
	ballUpdate(ball, window);
	textUpdate(textobj, score);


}

void drawGame(sf::RenderWindow& window, Bat& bat, Ball& ball, Brick brick, TextObj& textobj) {
	window.clear();
	window.draw(bat.shape);
	window.draw(ball.shape);
	textDraw(window, textobj);
	drawBrick(window, brick);
	window.display();

}

