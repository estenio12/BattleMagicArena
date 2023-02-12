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
        std::string ID = "00";
        std::string Title;
        std::string Description;

    public:
        float Damage      = 0.f;
        char Action       = '0';
        char TargetType   = '0';
        char Status       = '0';
        sf::Color CardColor = sf::Color::White;

    private:
        sf::Sprite CardImage;
        sf::Sprite Background;
        sf::Sprite TitleBar;
        sf::Sprite ImageBar;
        sf::Text txt_Title;
        sf::Texture Texture;

    public:
        Card(std::string ID,
             sf::Texture& texture, 
             sf::IntRect CardRectCoordenates,
             std::string Title,
             std::string Description,
             float Damage,
             char Action,
             sf::Color CardColor,
             char TargetType = '0',
             char Status = '0')
        {
            this->ID          = ID;
            this->CardImage.setTexture(texture);
            this->CardImage.setTextureRect(CardRectCoordenates);
            this->Title       = Title;
            this->Description = Description;
            this->Damage      = Damage;
            this->Action      = Action;
            this->TargetType  = TargetType;
            this->Status      = Status;
            this->CardColor   = CardColor;
        }

    public:
        void Render(sf::RenderWindow* app)
        {
            app->draw(this->CardImage);
        }
};