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

    int razaCerc = 20;
    int scor = 0;

    RenderWindow window(VideoMode(1280, 720), "Aim trainer game <-> Made by Mihai");
    window.setMouseCursorVisible(false);

    CircleShape aim(10);
    aim.setFillColor(Color::Red);

    //Bottom margin
    RectangleShape border(Vector2f(1300, 50));
    border.setPosition(0, 720);
    border.setFillColor(Color::White);

    Font font;
    font.loadFromFile("cour.ttf");
    Text text;
    text.setFont(font);
    text.setPosition(640, 0);
    text.setString("Scor");
    text.setFillColor(Color::White);

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
        if (clock0.getElapsedTime().asSeconds() > 1) {
            int randomX = rand() % 1280;
            int randomY = rand() % 720;
            targets.push_back(CircleShape());
            targets.back().setRadius(razaCerc);
            targets.back().setPosition(randomX, randomY);
            clock0.restart();
        }

        for (int i = 0; i < targets.size(); i++) {
            if (targets[i].getGlobalBounds().intersects(aim.getGlobalBounds())
                && Mouse::isButtonPressed(Mouse::Left)) {
                targets.erase(targets.begin() + i);
                scor++;
                text.setString(to_string(scor));
            }
            
        }

        window.clear();
        window.draw(aim);
        window.draw(text);
        window.draw(border);
        for (int i = 0; i < targets.size(); i++) {
            window.draw(targets[i]);
            
        }
        window.display();

    }

    return 0;
}