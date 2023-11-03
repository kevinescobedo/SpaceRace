#include "Game.hpp"

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        std::cerr<<"Usage: "<<argv[0]<<" <window-width> <window-length>\n";
        return 1;
    }

    unsigned int width = atoi(argv[1]);
    unsigned int length = atoi(argv[2]);

    Game game(width, length);
    game.play();

    return 0;
}
