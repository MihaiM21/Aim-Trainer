#ifndef MENU_H
#define MENU_H

#define targetSize 20
#define windowWidth 1280
#define windowHeight 720
#define spawnTimeDelay 0.1
#define cursorSize 8

#define buttonWidth 250
#define buttonHeight 60

#include "iostream"
#include <SFML/Graphics.hpp>

using namespace sf;

class menu
{
	
public:
	RectangleShape startButton, exitButton;
	Font textFont;
	Text startText, exitText;
	void _init();

private:

};

void menu::_init() {
	// Init start button
	menu::startButton.setSize(Vector2f(buttonWidth, buttonHeight));
	menu::startButton.setFillColor(Color::White);
	menu::startButton.setPosition(windowWidth/2 - buttonWidth/2, windowHeight/2);
	// Init text for start button
	menu::textFont.loadFromFile("cour.ttf");
	menu::startText.setFont(menu::textFont);
	// 43 half of text width
	menu::startText.setPosition(windowWidth/2 - 43, windowHeight / 2 + 7);
	menu::startText.setFillColor(Color::Red);
	menu::startText.setString("START");

	// Init exit button
	menu::exitButton.setSize(Vector2f(buttonWidth, buttonHeight));
	menu::exitButton.setFillColor(Color::White);
	menu::exitButton.setPosition(windowWidth / 2 - buttonWidth / 2, windowHeight / 2 + 100);
	// Init text for exit button
	menu::exitText.setFont(menu::textFont);
	menu::exitText.setPosition(windowWidth / 2 - 36, windowHeight / 2 + 100 + 7);
	menu::exitText.setFillColor(Color::Red);
	menu::exitText.setString("EXIT");
}


#endif