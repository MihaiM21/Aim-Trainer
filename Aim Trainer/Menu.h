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

class endScreen
{
public:
	void _init();
	void changeScore(int score);
	reader iniReader;
	RectangleShape panel, menuButton;
	Font textFont;
	Text title, score, menuText;
private:

};

void endScreen::_init() {
	iniReader._init_reader();
	// Init panel
	endScreen::panel.setSize(Vector2f(500, 500));
	endScreen::panel.setFillColor(Color::Cyan);
	endScreen::panel.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 250, iniReader.iniParseInt(windowHeight) / 2 - 250);

	// Init Text
	endScreen::textFont.loadFromFile("cour.ttf");
	endScreen::title.setFont(textFont);
	endScreen::title.setString("GAME OVER");
	endScreen::title.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 75, iniReader.iniParseInt(windowHeight) / 2 - 200);
	endScreen::title.setFillColor(Color::Black);

	endScreen::score.setFont(textFont);
	endScreen::score.setCharacterSize(20);
	endScreen::score.setPosition(iniReader.iniParseInt(windowWidth) / 2, iniReader.iniParseInt(windowHeight) / 2 - 160);
	endScreen::score.setFillColor(Color::Black);

	// Init the menu button
	endScreen::menuButton.setSize(Vector2f(buttonWidth, buttonHeight));
	endScreen::menuButton.setFillColor(Color::White);
	endScreen::menuButton.setPosition(iniReader.iniParseInt(windowWidth) / 2 - buttonWidth / 2, iniReader.iniParseInt(windowHeight) / 2 + 100);
	// Init text for short plat button
	endScreen::menuText.setFont(textFont);
	endScreen::menuText.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 36, iniReader.iniParseInt(windowHeight) / 2 + 100 + 7);
	endScreen::menuText.setFillColor(Color::Red);
	endScreen::menuText.setString("MENU");
}

void endScreen::changeScore(int score) {
	endScreen::score.setString(to_string(score));
}


class menu
{
	
public:
	reader iniReader;
	RectangleShape startButton, exitButton, shortButton;
	Font textFont;
	Text startText, exitText, shortText;
	void _init();

private:

};

void menu::_init() {
	iniReader._init_reader();
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

	// Init the short play button
	menu::shortButton.setSize(Vector2f(buttonWidth, buttonHeight));
	menu::shortButton.setFillColor(Color::White);
	menu::shortButton.setPosition(iniReader.iniParseInt(windowWidth) / 2 - buttonWidth / 2, iniReader.iniParseInt(windowHeight) / 2 + 100);
	// Init text for short plat button
	menu::shortText.setFont(textFont);
	menu::shortText.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 90, iniReader.iniParseInt(windowHeight) / 2 + 100 + 7);
	menu::shortText.setFillColor(Color::Red);
	menu::shortText.setString("SHORT GAME");


	// Init exit button
	menu::exitButton.setSize(Vector2f(buttonWidth, buttonHeight));
	menu::exitButton.setFillColor(Color::White);
	menu::exitButton.setPosition(iniReader.iniParseInt(windowWidth) / 2 - buttonWidth / 2, iniReader.iniParseInt(windowHeight) / 2 + 200);
	// Init text for exit button
	menu::exitText.setFont(menu::textFont);
	menu::exitText.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 36, iniReader.iniParseInt(windowHeight) / 2 + 200 + 7);
	menu::exitText.setFillColor(Color::Red);
	menu::exitText.setString("EXIT");
}


#endif