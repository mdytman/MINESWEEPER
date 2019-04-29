#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>

#ifndef INTROVIEW_H__
#define INTROVIEW_H__

class IntroView
{
	sf::Font font1;
	sf::Font font2;
	sf::Text text1;
	sf::Text text2;
	sf::RectangleShape rect[2][3];
	sf::CircleShape start;
public:
	IntroView();
	void startOutline();
	void rectOutline(int posX, int posY, bool tmp);
	void draw(sf::RenderWindow & win);
};

#endif