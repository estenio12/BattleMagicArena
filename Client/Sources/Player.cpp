#include "../Includes/Player.hpp"

Player::Player(float* DeltaTime):DeltaTime(DeltaTime)
{
    this->LoadTimers();
}

Player::~Player(){}

void Player::ApplyDamage(float Damage)
{
    float GetRestDamage = this->ApplyDamageToShieldIfActivated(Damage);
    this->HP -= GetRestDamage;

    if(this->HP <= 0)
    {
        this->IsDead = true;
        this->HP     = 0;
    }
}

float Player::ApplyDamageToShieldIfActivated(float Damage)
{
    if(this->Shield > 0)
    {
        float GetRest = this->Shield - Damage;

        if(GetRest < 0) this->Shield = 0;

        return abs(GetRest);
    }

    return Damage;
}

void Player::SetHP(float NewHPValue)
{
    this->HP = NewHPValue;
}

void Player::SetStatus(char NewStatus)
{
    this->Status = NewStatus;

    this->ResetTimers();
}

void Player::Bleeding()
{
    if(this->Status == Status::Bleeding)
    {
        // # Apply damage per frame
        this->ApplyDamage(DefaultMaxValue::BLEEDING_FACTOR);

        if(this->BleedingTimer->ExecuteTimer())
        {
            this->SetStatus(Status::NONE);
            this->BleedingTimer->ResetTimer();
        }
    }
}

void Player::Poisoning()
{
    if(this->Status == Status::Poisoning)
    {
        // # Apply damage per frame
        this->ApplyDamage(DefaultMaxValue::POISON_FACTOR);

        if(this->PoisoningTimer->ExecuteTimer())
        {
            this->SetStatus(Status::NONE);
            this->PoisoningTimer->ResetTimer();
        }
    }
}

void Player::Burning()
{
    if(this->Status == Status::Burning)
    {
        // # Apply damage per frame
        this->ApplyDamage(DefaultMaxValue::BURNING_FACTOR);

        if(this->BurningTimer->ExecuteTimer())
        {
            this->SetStatus(Status::NONE);
            this->BurningTimer->ResetTimer();
        }
    }
}

void Player::Blind()
{
    if(this->Status == Status::Blind)
    {
        if(this->BlindedTimer->ExecuteTimer())
        {
            this->SetStatus(Status::NONE);
            this->BlindedTimer->ResetTimer();
        }
    }
}

void Player::HPRecovering()
{
    if(this->Status == Status::HPRecovering)
    {
        this->HP += DefaultMaxValue::HP_FACTOR;

        if(this->HPRecoverTimer->ExecuteTimer())
        {
            this->SetStatus(Status::NONE);
            this->HPRecoverTimer->ResetTimer();
        }
    }
}

void Player::Freezing()
{
    if(this->Status == Status::Freezing)
    {
        if(this->FreezingTimer->ExecuteTimer())
        {
            this->SetStatus(Status::NONE);
            this->FreezingTimer->ResetTimer();
        }
    }
}

void Player::LoadTimers()
{
    this->BleedingTimer  = new Timer(this->DeltaTime, DefaultMaxValue::BLEEDING_DURATION);
    this->PoisoningTimer = new Timer(this->DeltaTime, DefaultMaxValue::POISONING_DURATION);
    this->BurningTimer   = new Timer(this->DeltaTime, DefaultMaxValue::BURNING_DURATION);
    this->BlindedTimer   = new Timer(this->DeltaTime, DefaultMaxValue::BLIND_DURATION);
    this->HPRecoverTimer = new Timer(this->DeltaTime, DefaultMaxValue::HP_DURATION);
    this->FreezingTimer  = new Timer(this->DeltaTime, DefaultMaxValue::FREEZING_DURATION);
}

void Player::Update()
{

    // # Status Action
    this->Bleeding();
    this->Poisoning();
    this->Burning();
    this->Blind();
    this->HPRecovering();
    this->Freezing();
}

void Player::ResetTimers()
{
    this->BleedingTimer->ResetTimer();
    this->PoisoningTimer->ResetTimer();
    this->BurningTimer->ResetTimer();
    this->BlindedTimer->ResetTimer();
    this->HPRecoverTimer->ResetTimer();
    this->FreezingTimer->ResetTimer();
}
