#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{   
    sf::RenderWindow window(sf::VideoMode(900, 600), "Battle Magic Arena", sf::Style::Default);
    sf::Event event;

    // # Setting 
    window.setFramerateLimit(60.f);

    sf::Sprite spr;
    sf::Texture tex;
    tex.loadFromFile("./Resources/Sprites/SpriteSheet.png");
    spr.setTexture(tex);
    spr.setColor(sf::Color::Blue);

    while (window.isOpen())
    {
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        window.draw(spr);

        window.display();
    }
    
    return EXIT_SUCCESS;
}