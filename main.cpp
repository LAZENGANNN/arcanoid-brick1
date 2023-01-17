#include "SFML/Graphics.hpp"
#include "settings.h"
#include "functions.h"
#include "bat.h"
#include "ball.h"
#include "brick.h"
#include "textobj.h"

using namespace sf;

int main()
{
	int score = 0;

	Bat bat;
	initbat(bat);

	Ball ball;
	initBall(ball);

	Brick brick;
	initBrick(brick);

	TextObj scoreText;
	textInit(scoreText, score);



	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		checkEvents(window);

		updateGame(bat, ball, window, scoreText, score);

		checkCollisions(ball, bat);

		drawGame(window, bat, ball, brick, scoreText);
	}

	return 0;
}