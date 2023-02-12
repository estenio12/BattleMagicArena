// # 
// # Copyright All (C) 
// # This project was licensed under MIT
// # @author: Estenio Garcia
// # 

#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

#include "../Helpers/Definition.hpp"
#include "../Includes/Timer.hpp"

class Player
{
    public:
        char ID              = Configuration::DEFAULT_ID;
        std::string NickName = Configuration::DEFAULT_NICKNAME;
        std::string GlobalID = Configuration::DEFAULT_GLOBALID;
    
    public:
        float HP     = DefaultMaxValue::MAX_HP;
        float Shield = 0;
        bool IsDead  = false;

    private:
        char Status = Status::NONE;
        float* DeltaTime;

    private:
        Timer* BleedingTimer;
        Timer* PoisoningTimer;
        Timer* BurningTimer;
        Timer* BlindedTimer;
        Timer* HPRecoverTimer;
        Timer* FreezingTimer;

    public:
        Player(float* DeltaTime);
        ~Player();

    // # Player Interactive
    public:
        void ApplyDamage(float );
        float ApplyDamageToShieldIfActivated(float );
        void SetHP(float );
        void SetStatus(char );

    public:
        void Update();
        void Render(sf::RenderWindow* Render);

    private:
        void LoadTimers();
        void ResetTimers();

    // # Passive Status Activated
    private:
        void Bleeding();
        void Poisoning();
        void Burning();
        void Freezing();
        void HPRecovering();
};