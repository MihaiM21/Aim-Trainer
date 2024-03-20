#ifndef MENU_H
#define MENU_H

#define targetSize "target_size"
#define windowWidth "windowWidth"
#define windowHeight "windowHeight"
#define spawnTimeDelay "spawn_time_delay"
#define cursorSize "cursor_size"

#define buttonWidth 250
#define buttonHeight 60

#include "iostream"
#include <SFML/Graphics.hpp>
#include "iniReader.h"

using namespace sf;

class menu
{
	
public:
	reader iniReader;
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
	menu::startButton.setPosition(iniReader.iniParseInt(windowWidth)/2 - buttonWidth/2, iniReader.iniParseInt(windowHeight)/2);
	// Init text for start button
	menu::textFont.loadFromFile("cour.ttf");
	menu::startText.setFont(menu::textFont);
	// 43 half of text width
	menu::startText.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 43, iniReader.iniParseInt(windowHeight) / 2 + 7);
	menu::startText.setFillColor(Color::Red);
	menu::startText.setString("START");

	// Init exit button
	menu::exitButton.setSize(Vector2f(buttonWidth, buttonHeight));
	menu::exitButton.setFillColor(Color::White);
	menu::exitButton.setPosition(iniReader.iniParseInt(windowWidth) / 2 - buttonWidth / 2, iniReader.iniParseInt(windowHeight) / 2 + 100);
	// Init text for exit button
	menu::exitText.setFont(menu::textFont);
	menu::exitText.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 36, iniReader.iniParseInt(windowHeight) / 2 + 100 + 7);
	menu::exitText.setFillColor(Color::Red);
	menu::exitText.setString("EXIT");
}


#endif