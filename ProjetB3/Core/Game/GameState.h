#pragma once
#include "../../Utils/Delegate.h"
#include "../../Utils/Singleton.h"

class GameState
{
public:
    inline DECLARE_SINGLETON(GameState)
    enum State
    {
        STOPPED,
        PLAYING,
        PAUSE
    };
    static State* currentState;
    static bool IsPlaying();
    void ChangeState(State* newState);
    DECLARE_DELEGATE(FStateChanged, State*)
    FStateChanged OnStateChanged;
};
