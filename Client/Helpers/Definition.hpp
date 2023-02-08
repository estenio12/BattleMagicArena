// # 
// # Copyright All (C) 
// # This project was licensed under MIT
// # @author: Estenio Garcia
// # 

#pragma once

#include <string>
#include <cstdint>

namespace StatusAction
{
    static const char NONE      = '0';
    static const char Shield    = '1';
    static const char DamageUP  = '2';
    static const char Poison    = '3';
    static const char Burnning  = '4';
    static const char HPRecover = '5';
    static const char Freezing  = '6';
}

namespace DefaultValue
{
    static const float MAX_SHIELD  = 100;
    static const float MAX_HP      = 100;
    static const float POISON_FACTOR = 1.2f;
    static const float BURN_FACTOR   = 2.3f;
    static const float HP_FACTOR     = 3.0f;
    static const float DAMAGE_FACTOR = 2.3f;
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

namespace Cards
{
    
}