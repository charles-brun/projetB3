#pragma
#include "GameState.h"

GameState* GameState::Instance = nullptr;
GameState::State* GameState::currentState = nullptr;

GameState* GameState::Get()
{
    if (Instance == nullptr)
    {
        Instance = new GameState();
    }
    return Instance;
}

void GameState::Reset()
{
    delete Instance;
}

void GameState::ChangeState(State* newState)
{
    currentState = newState;
    OnStateChanged.BroadCast(newState);
}

bool GameState::IsPlaying()
{
    return *currentState == PLAYING;
}
