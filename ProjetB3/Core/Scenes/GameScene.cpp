#include "GameScene.h"
#include "../../Utils/Factory.h"
#include "../Entities/Block.h"
#include "../Entities/Threat.h"

void GameScene::Load()
{
    Scene::Load();
    for (Level::ActorData* actor: currentLevel->actors)
    {
        int sceneID = AddEntity(Factory::Get()->SpawnEntity(actor->classID, actor->startingPos));
        if (actor->classID == EPlayer::StaticClass()->GetId())
        {
            playerID = sceneID;
        } else if (actor->classID == EThreat::StaticClass()->GetId()) {
            threats.push_back(sceneID);
        } else if (actor->classID == EBlock::StaticClass()->GetId()) {
            blocks.push_back(sceneID);
        }
    }
}

EPlayer* GameScene::GetPlayer() const
{
    if (GetEntity(playerID) == nullptr)
    {
        return nullptr;
    }
    return dynamic_cast<EPlayer*>(GetEntity(playerID));
}

bool GameScene::IsPlayer(const int& sceneID) const
{
    return sceneID == playerID;
}

bool GameScene::IsThreat(const int& sceneID) const
{
    return std::find(threats.begin(), threats.end(), sceneID) != threats.end();
}

bool GameScene::IsBlock(const int& sceneID) const
{
    return std::find(blocks.begin(), blocks.end(), sceneID) != blocks.end();
}
