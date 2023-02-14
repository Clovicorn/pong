#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include "bat.h"

using namespace sf;

int main(void)
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Fullscreen);

    int score = 0;
    int lives = 3;

    Bat bat(vm.width / 2.0f, vm.height - 20.0f, vm);
    Text hud;

    Font font;
    font.loadFromFile("assets/game_over.ttf");

    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setString("Score = 0 Lives = 3");
    hud.setFillColor(Color::Green);
    hud.setPosition(20, 20);

    Clock clock;

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyPressed)
            {
                if (Keyboard::isKeyPressed(Keyboard::A)) //  || Keyboard::isKeyPressed(Keyboard::A)
                {
                    bat.moveLeft();
                }
                else if (Keyboard::isKeyPressed(Keyboard::D)) //  || Keyboard::isKeyPressed(Keyboard::D)
                {
                    bat.moveRight();
                }
                else if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    window.close();
                }
            }
            else if (event.type == Event::KeyReleased)
            {
                if ((event.key.code == Keyboard::A)) //  || (event.key.code == Keyboard::A)
                {
                    bat.stopLeft();
                }
                else if ((event.key.code == Keyboard::D)) //  || (event.key.code == Keyboard::D)
                {
                    bat.stopRight();
                }
            }
        }

        Time dt = clock.restart();
        bat.update(dt);
        std::stringstream ss;
        ss << "Score: " << score << "\tLives: " << lives;
        hud.setString(ss.str());
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.display();
    }
    return 0;
}