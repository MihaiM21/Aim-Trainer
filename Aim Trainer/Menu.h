#ifndef MENU_H
#define MENU_H

#define targetSize 20
#define width 1280
#define height 720
#define spawnTimeDelay 0.1
#define cursorSize 8

#include "iostream"
#include <SFML/Graphics.hpp>

using namespace sf;

class menu
{
	
public:
	RectangleShape startButton;
	Font textFont;
	Text startText;
	void _init();

private:

};

void menu::_init() {
	// Init Button image
	menu::startButton.setSize(Vector2f(250, 80));
	menu::startButton.setFillColor(Color::White);
	menu::startButton.setPosition(100, 100);
	// Init text for start button
	menu::textFont.loadFromFile("cour.ttf");
	menu::startText.setFont(menu::textFont);
	menu::startText.setPosition(100, 100);
	menu::startText.setFillColor(Color::Red);
	menu::startText.setString("Start");
}


#endif