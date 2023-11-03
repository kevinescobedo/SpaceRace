#include "Game.hpp"

Game::Game(unsigned int windowWidth, unsigned int windowLength)
:window("Space Race", windowWidth, windowLength)
{

}

Game::Game(const sf::Vector2u& dimensions)
:Game(dimensions.x, dimensions.y)
{

}

Game::Game(const Game& game)
:window(game.window)
{

}

Game& Game::operator =(const Game& game)
{
    window = game.window;

    return *this;
}

Game::~Game()
{
    if(window.isOpen())
    {
        window.close();
    }
}

void Game::play()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }

                default:
                {
                    break;
                }
            }
        }

        window.clear();
        window.display();
    }
}

std::ostream& operator <<(std::ostream& os, const Game& game)
{
    os<<"Window Information:\n";
    os<<game.window;

    return os;
}
