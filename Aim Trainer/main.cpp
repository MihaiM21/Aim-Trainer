#include <SFML/Graphics.hpp>
#include <time.h>
#include <Windows.h>
#include <iostream>
using namespace sf;
using namespace std;


int main()
{
    //Random number stuff
    srand((unsigned)time(NULL));

    //Raza for spawner
    int razaCerc = 20;
    int scor = 0;

    RenderWindow window(VideoMode(1280, 720), "Aim trainer game <-> Made by Mihai");
    window.setMouseCursorVisible(false);
    window.setVerticalSyncEnabled(true);
 

    CircleShape aim(10);
    aim.setFillColor(Color::Red);

    //Bottom margin
    RectangleShape border(Vector2f(1300, 50));
    border.setPosition(0, 720);
    border.setFillColor(Color::White);

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


    bool canSpawn = true;
    Clock clock0;
    
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

        //Spawning objects at random positions
        if (clock0.getElapsedTime().asSeconds() > 0.75) {
            int randomX = rand() % 1280;
            int randomY = rand() % 720;
            targets.push_back(CircleShape());
            targets.back().setRadius(razaCerc);
            targets.back().setPosition(randomX, randomY);
            canSpawn = false;
            clock0.restart();
        }

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
        window.draw(border);
        for (int i = 0; i < targets.size(); i++) {
            window.draw(targets[i]);
        }
        window.display();

    }

    return 0;
}