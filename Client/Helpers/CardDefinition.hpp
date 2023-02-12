// # 
// # Copyright All (C) 
// # This project was licensed under MIT
// # @author: Estenio Garcia
// # 

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class CardData
{
    public:
        std::wstring Title;
        float Damage      = 0.f;
        char Action       = '0';
        char TargetType   = '0';
        char Status       = '0';
        sf::IntRect ImageRect;

    public:
        CardData
        (
            std::wstring Title,
            sf::IntRect ImageRect,
            float Damage,
            char Action,
            char TargetType = '0',
            char Status = '0')
        {
            this->Title       = Title;
            this->Damage      = Damage;
            this->Action      = Action;
            this->TargetType  = TargetType;
            this->Status      = Status;
            this->ImageRect   = ImageRect;
        }
};