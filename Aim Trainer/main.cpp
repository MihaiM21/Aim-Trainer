#include <SFML/Graphics.hpp>
#include <time.h>
#include <Windows.h>
#include <iostream>
#include "Menu.h"
#include "iniReader.h"

#define targetSize "target_size"
#define windowWidth "windowWidth"
#define windowHeight "windowHeight"
#define spawnTimeDelay "spawn_time_delay"
#define cursorSize "cursor_size"


using namespace sf;
using namespace std;


int main()
{
    reader iniReader;
    iniReader._init_reader();

    //Random number stuff
    srand((unsigned)time(NULL));
    int scor = 0;
    
    RenderWindow window(VideoMode(iniReader.iniParseInt(windowWidth),iniReader.iniParseInt(windowHeight)),
        "Aim trainer game <-> Made by Mihai");
    window.setMouseCursorVisible(false);
    window.setVerticalSyncEnabled(true);
 
    CircleShape aim(iniReader.iniParseInt(cursorSize));
    aim.setFillColor(Color::Red);

    //Score text
    Font font;
    font.loadFromFile("cour.ttf");
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setPosition(iniReader.iniParseInt(windowWidth)/2, 0);
    scoreText.setString("Score:");
    scoreText.setFillColor(Color::White);

    Text scoreNr;
    scoreNr.setFont(font);
    scoreNr.setPosition(750, 0);
    scoreNr.setFillColor(Color::White);

    Text timeCounter;
    timeCounter.setFont(font);
    timeCounter.setPosition(10, 10);
    timeCounter.setFillColor(Color::White);

    bool isMenuOn = true;
    bool canSpawn = true;
    bool endGame = false;
    Clock clock0;
    Clock clock1;

    vector<CircleShape> targets;

    
    // Starting the menu
    menu menu;
    endScreen end;
    menu._init();
    end._init();
    RectangleShape startButton = menu.startButton;
    RectangleShape exitButton = menu.exitButton;
    
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        // Cursor possition
        aim.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

        

        window.clear();
        if (isMenuOn) {
            // Checking if Start button is pressed
            if (aim.getGlobalBounds().intersects(startButton.getGlobalBounds())) {
                menu.startButton.setOutlineThickness(5);
                menu.startButton.setOutlineColor(Color::Red);
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    isMenuOn = false;
                }
            }
            else {
                menu.startButton.setOutlineThickness(0);
            }

            // Checking if exit button is pressed
            if (aim.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
                menu.exitButton.setOutlineThickness(5);
                menu.exitButton.setOutlineColor(Color::Red);
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    window.close();
                }
            }
            else {
                menu.exitButton.setOutlineThickness(0);
            }

            window.draw(menu.startButton);
            window.draw(menu.startText);
            window.draw(menu.exitButton);
            window.draw(menu.exitText);
            window.draw(aim);
         
        }
        else if (!endGame) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                isMenuOn = true;
                // Reset score
                clock1.restart();
                scor = 0;
                scoreNr.setString(to_string(scor));
            }

            // Spawning objects at random positions
            if (clock0.getElapsedTime().asSeconds() > iniReader.iniParseFloat(spawnTimeDelay)) {
                if (canSpawn) {
                    int randomX = rand() % (iniReader.iniParseInt(windowWidth)-iniReader.iniParseInt(targetSize) * 2);
                    int randomY = rand() % (iniReader.iniParseInt(windowHeight) - iniReader.iniParseInt(targetSize) * 2);
                    targets.push_back(CircleShape());
                    targets.back().setRadius(iniReader.iniParseInt(targetSize));
                    targets.back().setPosition(randomX, randomY);
                    canSpawn = false;
                }
                clock0.restart();
            }

            // Updating time text
            timeCounter.setString(to_string(clock1.getElapsedTime().asSeconds()));

            for (int i = 0; i < targets.size(); i++) {
                if (targets[i].getGlobalBounds().intersects(aim.getGlobalBounds())
                    && Mouse::isButtonPressed(Mouse::Left)) {
                    targets.erase(targets.begin() + i);
                    canSpawn = true;
                    scor++;
                    scoreNr.setString(to_string(scor));
                }

            }

            // Checking if the game has ended
            if (clock1.getElapsedTime().asSeconds() >= 5)
                endGame = true;

            // Cursor color changing when LMB pressed
            if (Mouse::isButtonPressed(Mouse::Left)) {
                aim.setFillColor(Color::Green);
            }
            else {
                aim.setFillColor(Color::Red);
            }

            window.draw(scoreText);
            window.draw(scoreNr);
            window.draw(timeCounter);
            for (int i = 0; i < targets.size(); i++) {
                window.draw(targets[i]);
            }
            window.draw(aim);
        }
        else {

            end.changeScore(scor);
            window.draw(end.panel);
            window.draw(end.score);
            window.draw(end.title);
            window.draw(aim);
        }
        
        window.display();

    }

    return 0;
}