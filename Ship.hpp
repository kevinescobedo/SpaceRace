#ifndef SHIP_HPP
#define SHIP_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <random>

class Ship: public sf::RectangleShape
{
public:
    Ship(float x, float y, float width, float height);
    Ship(const sf::Vector2f& location, const sf::Vector2f& size);
    Ship(const Ship& ship);
    Ship& operator =(const Ship& ship);
    friend std::ostream& operator <<(std::ostream& os, const Ship& ship);

private:
    static sf::Color randomColor();
};

#endif /* SHIP_HPP */
