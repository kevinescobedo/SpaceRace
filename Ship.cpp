#include "Ship.hpp"

Ship::Ship(float x, float y, float width, float height)
:sf::RectangleShape()
{
    sf::Vector2f position(x, y);
    sf::Vector2f size(width, height);

    setPosition(position);
    setSize(size);
    setFillColor(randomColor());
}

Ship::Ship(const sf::Vector2f& location, const sf::Vector2f& size)
:Ship(location.x, location.y, size.x, size.y)
{

}

Ship::Ship(const Ship& ship)
:Ship(ship.getPosition(), ship.getSize())
{
    setFillColor(ship.getFillColor());
}

Ship& Ship::operator =(const Ship& ship)
{
    Ship(ship.getPosition(), ship.getSize());
    setFillColor(ship.getFillColor());
    return *this;
}

std::ostream& operator <<(std::ostream& os, const Ship& ship)
{
    sf::Vector2f position = ship.getPosition();
    sf::Vector2f size = ship.getSize();
    sf::Color color = ship.getFillColor();

    os<<"Position: ("<<position.x<<", "<<position.y<<")\n";
    os<<"Size: ("<<size.x<<" x "<<size.y<<")\n";
    os<<"Color: ("<<color.r<<", "<<color.g<<", "<<color.b<<")";

    return os;
}

sf::Color Ship::randomColor()
{
    std::random_device rd;
    std::uniform_int_distribution<int> range(0, 255);

    int red = range(rd);
    int green = range(rd);
    int blue = range(rd);

    return sf::Color(red, green, blue);
}
