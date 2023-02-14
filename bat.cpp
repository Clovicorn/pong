#include "bat.h"

Bat::Bat(float startX, float startY, VideoMode vm)
{
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setSize(sf::Vector2f(LENGTH, HEIGHT));
    m_Shape.setPosition(m_Position);
    m_vm = vm;
}

FloatRect Bat::getPosition()
{
    return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
    return m_Shape;
}

void Bat::moveLeft()
{
    m_MovingLeft = true;
}

void Bat::moveRight()
{
    m_MovingRight = true;
}

void Bat::stopLeft()
{

    m_MovingLeft = false;
}

void Bat::stopRight()
{

    m_MovingRight = false;
}

void Bat::update(Time dt)
{
    if (m_MovingLeft)
    {
        m_Position.x -= m_Speed * dt.asSeconds();
        if (m_Position.x <= 0)
        {
            m_Position.x = 0;
        }
    }

    if (m_MovingRight)
    {
        m_Position.x += m_Speed * dt.asSeconds();
        if (m_Position.x + LENGTH >= m_vm.width)
        {
            m_Position.x = m_vm.width - LENGTH;
        }
    }

    m_Shape.setPosition(m_Position);
}