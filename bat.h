#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Bat
{
private:
    const int LENGTH = 50;
    const int HEIGHT = 5;
    VideoMode m_vm;
    Vector2f m_Position;
    RectangleShape m_Shape;
    float m_Speed = 1000.0f;
    bool m_MovingRight = false;
    bool m_MovingLeft = false;

public:
    Bat(float startX, float startY, VideoMode vm);
    FloatRect getPosition();
    RectangleShape getShape();
    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void update(Time dt);
};