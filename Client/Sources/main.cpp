#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Helpers/Definition.hpp"
#include "../Includes/Cards.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "Battle Magic Arena", sf::Style::Default);
    sf::Event event;

    // # Setting 
    window.setFramerateLimit(60.f);

    sf::Texture tex;
    sf::Font font;

    float DeltaTime = 10.f;

    tex.loadFromFile("./Resources/Sprites/SpriteSheet.png");
    font.loadFromFile("./Resources/Fonts/UbuntuRegular.ttf");

    auto test = new Cards(CardDef::CardInfoList[12], CardColor::Green, font, &DeltaTime, tex, sf::Vector2f(50, 50));

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

        test->Render(&window);

        window.display();
    }
    
    return EXIT_SUCCESS;
}