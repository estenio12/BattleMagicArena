// # 
// # Copyright All (C) 
// # This project was licensed under MIT
// # @author: Estenio Garcia
// # 

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Card
{
    public:
        int ID;
        std::string Title;
        std::string Description;
        sf::Sprite Sprite;

    public:
        int Damage        = 0;
        char StatusAction = '0';

    public:
        Card(int ID,
             sf::Texture& texture, 
             sf::IntRect CardRectCoordenates,
             std::string Title,
             std::string Description,
             int Damage,
             char StatusAction)
        {
            this->ID = ID;
            this->Sprite.setTexture(texture);
            this->Sprite.setTextureRect(CardRectCoordenates);
            this->Title = Title;
            this->Description = Description;
            this->Damage = Damage;
            this->StatusAction = StatusAction;
        }

    public:
        void Render(sf::RenderWindow* app)
        {
            
        }
};