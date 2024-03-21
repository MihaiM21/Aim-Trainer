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
	RectangleShape panel;
	Font textFont;
	Text title, score;
private:

};

void endScreen::_init() {
	iniReader._init_reader();
	// Init panel
	endScreen::panel.setSize(Vector2f(500, 500));
	endScreen::panel.setFillColor(Color::White);
	endScreen::panel.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 250, iniReader.iniParseInt(windowHeight) / 2 - 250);

	// Init Text
	endScreen::textFont.loadFromFile("cour.ttf");
	endScreen::title.setFont(textFont);
	endScreen::title.setString("GAME OVER");
	endScreen::title.setPosition(iniReader.iniParseInt(windowWidth) / 2 - 75, iniReader.iniParseInt(windowHeight) / 2 - 200);
	endScreen::title.setFillColor(Color::Black);

	endScreen::score.setFont(textFont);
	endScreen::score.setPosition(iniReader.iniParseInt(windowWidth) / 2, iniReader.iniParseInt(windowHeight) / 2 - 160);
	endScreen::score.setFillColor(Color::Black);
}

void endScreen::changeScore(int score) {
	endScreen::score.setString(to_string(score));
}


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