#pragma once
#include "../../Utils/Delegate.h"

class GameState
{
public:
    enum State
    {
        STOPPED,
        PLAYING,
        PAUSE
    };
    static GameState* Instance; 
    static GameState* Get();
    static void Reset();
    static State* currentState;
    static bool IsPlaying();
    void ChangeState(State* newState);
    DECLARE_DELEGATE(FStateChanged, State*)
    FStateChanged OnStateChanged;
};