// # 
// # Copyright All (C) 
// # This project was licensed under MIT
// # @author: Estenio Garcia
// # 

#pragma once

#include <string>
#include <cstdint>
#include <vector>
#include <SFML/Graphics.hpp>

#include "../Helpers/CardDefinition.hpp"

namespace TargetType
{
    static char Single = '0';
    static char Global = '1';
    static char Self   = '2';
};

namespace Configuration
{
    static std::string DEFAULT_NICKNAME = "UNDEFINED";
    static std::string DEFAULT_GLOBALID = "00";
    static char DEFAULT_ID = '0'; 
}

namespace CardColor
{
    static const sf::Color Red    = sf::Color(176, 53, 44);
    static const sf::Color Yellow = sf::Color(191, 151, 57);
    static const sf::Color Blue   = sf::Color(27, 105, 148);
    static const sf::Color Green  = sf::Color(49, 145, 56);
    static const sf::Color Black  = sf::Color(41, 41, 41);
}

namespace Action
{
    static const char NONE      = '0';
    static const char Shield    = '1';
    static const char Damage    = '2';
    static const char HPRecover = '6';
    static const char Freezing  = '7';
    static const char TurnTable = '8';
}

namespace Status
{
    static char NONE         = '0';
    static char Burning      = '1';
    static char Bleeding     = '2';
    static char Poisoning    = '3';
    static char HPRecovering = '5';
    static char Freezing     = '6';
}

namespace DefaultMaxValue
{
    static const float MAX_SHIELD      = 30;
    static const float MAX_HP          = 100;
    static const float POISON_FACTOR   = 1.2f;
    static const float BURNING_FACTOR  = 2.3f;
    static const float BLEEDING_FACTOR = 3.0f;
    static const float HP_FACTOR       = 3.0f;

    static const float POISONING_DURATION = 3.5f;
    static const float BURNING_DURATION   = 1.3f;
    static const float BLEEDING_DURATION  = 1.0f;
    static const float HP_DURATION        = 1.4f;
    static const float FREEZING_DURATION  = 1.4f;
}

namespace NetInput
{
    static const char PlayCard       = '0';
    static const char SelectColor    = '1';
    static const char ColorSelected  = '2';
    static const char BuyCard        = '3';
    static const char Surrender      = '4';
    static const char SelectOpponent = '5';
    static const char OpponentSelect = '6';
}

namespace CardDef
{
    static const std::vector<CardData*> CardInfoList
    {
        new CardData(L"Guerreiro Escravo", sf::IntRect(522, 0, 125, 118), 10, Action::Damage, TargetType::Single, Status::NONE),
        new CardData(L"Ogro do Vale", sf::IntRect(647, 0, 125, 118), 10, Action::Damage, TargetType::Single, Status::NONE),
        new CardData(L"Bruxa de Hundra", sf::IntRect(773, 0, 125, 118), 13, Action::Damage, TargetType::Single, Status::Poisoning),
        new CardData(L"Troll da Montanha", sf::IntRect(899, 0, 125, 118), 10, Action::Damage, TargetType::Single, Status::Bleeding),
        new CardData(L"Deban. dos Javalis", sf::IntRect(899, 118, 125, 118), 15, Action::Damage, TargetType::Single, Status::NONE),
        new CardData(L"Chicote de Fogo", sf::IntRect(774, 118, 124, 118), 10, Action::Damage, TargetType::Single, Status::NONE),
        new CardData(L"Bola de Fogo", sf::IntRect(648, 118, 126, 118), 10, Action::Damage, TargetType::Global, Status::Burning),
        new CardData(L"Inferno de Lava", sf::IntRect(521, 118, 126, 118), 15, Action::Damage, TargetType::Single, Status::Burning),
        new CardData(L"Poção", sf::IntRect(899, 237, 125, 118), 10, Action::HPRecover, TargetType::Self, Status::HPRecovering),
        new CardData(L"Congelar", sf::IntRect(773, 236, 125, 118), 0, Action::Freezing, TargetType::Single, Status::Freezing),
        new CardData(L"Meow", sf::IntRect(648, 236, 125, 118), 0, Action::NONE, TargetType::Self, Status::NONE),
        new CardData(L"Tornado de Chamas", sf::IntRect(522, 237, 125, 118), 0, Action::TurnTable, TargetType::Global, Status::NONE),
        new CardData(L"Escudo Mágico", sf::IntRect(898, 354, 126, 118), 0, Action::Shield, TargetType::Single, Status::NONE)
    };
}