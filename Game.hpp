#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "Window.hpp"

class Game
{
private:
    Window window;

public:
    Game(unsigned int windowWidth, unsigned int windowLength);
    Game(const sf::Vector2u& dimensions);
    Game(const Game& game);
    Game& operator =(const Game& game);
    ~Game();
    void play();
    friend std::ostream& operator <<(std::ostream& os, const Game& game);
};

#endif /* GAME_HPP */
