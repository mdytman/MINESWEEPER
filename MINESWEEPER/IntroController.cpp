#include "pch.h"
#include "IntroController.h"

IntroController::IntroController(IntroView & v, MinesweeperBoard & b) : view(v), board(b)
{}

void IntroController::handleEvent(sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if ((event.mouseButton.y > 400) && (event.mouseButton.y < 440))
			{
				if ((event.mouseButton.x > 40) && (event.mouseButton.x < 190))
				{
					view.rectOutline(0, 0, true);
					view.rectOutline(0, 1, false);
					view.rectOutline(0, 2, false);
					bx = 10;
					by = 10;
				}
				if ((event.mouseButton.x > (40 + 200)) && (event.mouseButton.x < (190 + 200)))
				{
					view.rectOutline(0, 1, true);
					view.rectOutline(0, 0, false);
					view.rectOutline(0, 2, false);
					bx = 20;
					by = 15;
				}
				if ((event.mouseButton.x > (40 + 2 * 200)) && (event.mouseButton.x < (190 + 2 * 200)))
				{
					view.rectOutline(0, 2, true);
					view.rectOutline(0, 1, false);
					view.rectOutline(0, 0, false);
					bx = 30;
					by = 20;
				}
			}

			if ((event.mouseButton.y > 400 + 100) && (event.mouseButton.y < 440 + 100))
			{
				if ((event.mouseButton.x > 40) && (event.mouseButton.x < 190))
				{
					view.rectOutline(1, 0, true);
					view.rectOutline(1, 1, false);
					view.rectOutline(1, 2, false);
					bMode = EASY;

				}
				else if ((event.mouseButton.x > (40 + 200)) && (event.mouseButton.x < (190 + 200)))
				{
					view.rectOutline(1, 1, true);
					view.rectOutline(1, 0, false);
					view.rectOutline(1, 2, false);
					bMode = NORMAL;
				}
				else if ((event.mouseButton.x > (40 + 2 * 200)) && (event.mouseButton.x < (190 + 2 * 200)))
				{
					view.rectOutline(1, 2, true);
					view.rectOutline(1, 1, false);
					view.rectOutline(1, 0, false);
					bMode = HARD;
				}
			}
		}

	}

	if ((event.mouseButton.x > 700) && (event.mouseButton.x < (700 + 2 * 170)) && (event.mouseButton.y > 400) && (event.mouseButton.y < (400 + 2 * 170)))
	{
		view.startOutline();
		board.resetBoard(getBx(), getBy(), getBMode());
		finished = true;
	}

}

int IntroController::getBx() const
{
	return bx;
}

int IntroController::getBy() const
{
	return by;
}

GameMode IntroController::getBMode() const
{
	return bMode;
}

