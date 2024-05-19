#pragma
#include "GameState.h"

GameState::State* GameState::currentState = nullptr;

void GameState::ChangeState(State* newState)
{
    currentState = newState;
    OnStateChanged.BroadCast(newState);
}

bool GameState::IsPlaying()
{
    return *currentState == PLAYING;
}
