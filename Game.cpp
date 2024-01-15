#include "Game.hpp"

Game::Game(unsigned int windowWidth, unsigned int windowLength)
:window("Space Race", windowWidth, windowLength), player1(windowWidth / 4.f, 8.5 * windowLength / 10.f, windowWidth / 25.f, windowLength / 10.f), player2(3 * windowWidth / 4.f, 8.5 * windowLength / 10.f, windowWidth / 25.f, windowLength / 10.f)
{

}

Game::Game(const sf::Vector2u& dimensions)
:Game(dimensions.x, dimensions.y)
{

}

Game::Game(const Game& game)
:window(game.window), player1(game.player1), player2(game.player2)
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

        window.draw(player1);
        window.draw(player2);

        window.display();
    }
}

std::ostream& operator <<(std::ostream& os, const Game& game)
{
    os<<"Window Information:\n";
    os<<game.window;

    return os;
}
