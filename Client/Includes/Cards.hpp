// # 
// # Copyright All (C) 
// # This project was licensed under MIT
// # @author: Estenio Garcia
// # 

#pragma once

#include "../Helpers/CardDefinition.hpp"

class Cards
{
    private:
        CardData* Info;
        float* DeltaTime;

    private:
        sf::Sprite ImageBar;
        sf::Sprite ImageCharacter;
        sf::Sprite ImageTitleBar;
        sf::Sprite ImageBackground;

        sf::Text Title;
        sf::Texture Texture;
    
    public:
        sf::Vector2f Location;
        sf::Vector2f Size;
        sf::FloatRect BoundingBox;

    public:
        Cards(CardData* Info,
              const sf::Color Color, 
              const sf::Font& Font,
              float* DeltaTime,
              sf::Texture& Texture,
              sf::Vector2f Location);
        ~Cards();

    private:
        void LoadCard(sf::Color );
        void UpdatePositionComponents();

    public:
        void Update();
        void Render(sf::RenderWindow* Render);

};