#include "Level.h"
#include "../Entities/Player.h"
#include "../Entities/Block.h"
#include "../Entities/Threat.h"

void Level::Initialize()
{
    actors.push_back(new ActorData(EPlayer::StaticClass()->GetId(), Vector2::ZERO()));
    actors.push_back(new ActorData(EBlock::StaticClass()->GetId(), {0, 200}));
    actors.push_back(new ActorData(EThreat::StaticClass()->GetId(), {200, 200}));
}

Level::~Level()
{
    for (ActorData* actor: actors)
    {
        delete actor;
    }
    actors.clear();
}
