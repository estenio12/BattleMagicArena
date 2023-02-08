#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{   
    sf::RenderWindow window(sf::VideoMode(900, 600), "Battle Magic Arena", sf::Style::Default);
    sf::Event event;

    // # Setting 
    window.setFramerateLimit(60.f);

    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                break;
            }
        }

        window.clear();

        window.display();
    }
    
    return EXIT_SUCCESS;
}