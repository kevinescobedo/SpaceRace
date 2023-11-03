#include "Window.hpp"

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        std::cerr<<"Usage: "<<argv[0]<<" <window-width> <window-length>\n";
        return 1;
    }

    unsigned int width = atoi(argv[1]);
    unsigned int length = atoi(argv[2]);
    Window window("Space Race", width, length);

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

    return 0;
}
