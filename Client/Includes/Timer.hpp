// # 
// # Copyright All (C) 
// # This project was licensed under MIT
// # @author: Estenio Garcia
// # 

#pragma once

class Timer
{
    private:
        float* DeltaTime;
        float TargetTime = 0.f;
        float CurrentCounter = 0;

    public:
        // # @param DeltaTime = Game Delta Time
        // # @param TargetTime= Max limit time
        Timer(float* DeltaTime, float TargetTime):
             DeltaTime(DeltaTime), TargetTime(TargetTime){}

        void ResetTimer()
        {
            this->CurrentCounter = 0;
        }

        bool ExecuteTimer()
        {
            if(this->CurrentCounter < this->TargetTime)
            {
                this->CurrentCounter += *this->DeltaTime;
            }
            else
            {
                return true;
            }

            return false;
        }
};