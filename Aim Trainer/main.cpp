#include <SFML/Graphics.hpp>
#include <time.h>
#include <Windows.h>
#include <iostream>

#define targetSize 20
#define height 1280
#define width 720
#define spawnTimeDelay 0.75
#define cursorSize 8
using namespace sf;
using namespace std;


int main()
{
    //Random number stuff
    srand((unsigned)time(NULL));

    int scor = 0;

    RenderWindow window(VideoMode(height, width), "Aim trainer game <-> Made by Mihai");
    window.setMouseCursorVisible(false);
    window.setVerticalSyncEnabled(true);
 

    CircleShape aim(cursorSize);
    aim.setFillColor(Color::Red);

    //Score text
    Font font;
    font.loadFromFile("cour.ttf");
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setPosition(640, 0);
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

    bool canSpawn = true;
    Clock clock0;
    Clock clock1;

    vector<CircleShape> targets;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        aim.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);

        // Spawning objects at random positions
        if (clock0.getElapsedTime().asSeconds() > spawnTimeDelay) {
            if(canSpawn) {
                int randomX = rand() % (width - targetSize * 2);
                int randomY = rand() % (height - targetSize * 2);
                targets.push_back(CircleShape());
                targets.back().setRadius(targetSize);
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

        window.clear();
        window.draw(aim);
        window.draw(scoreText);
        window.draw(scoreNr);
        window.draw(timeCounter);
        for (int i = 0; i < targets.size(); i++) {
            window.draw(targets[i]);
        }
        window.display();

    }

    return 0;
}