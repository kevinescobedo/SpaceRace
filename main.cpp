#include "Game.hpp"
#include <ctime>

int main(int argc, char** argv)
{
    srand((unsigned int)time(nullptr));
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
