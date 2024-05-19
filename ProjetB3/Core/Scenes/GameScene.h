#pragma once
#include "Scene.h"
#include "../Entities/Player.h"
#include "../Game/Level.h"

class GameScene: public Scene
{
public:
    DECLARE_CLASS(GameScene, Scene)
    void Load() override;
    EPlayer* GetPlayer() const;
    void SetLevel(Level* pLevel) { currentLevel = pLevel; }
    Level* GetCurrentLevel() const { return currentLevel; }
    bool IsPlayer(const int& sceneID) const;
    bool IsThreat(const int& sceneID) const;
    bool IsBlock(const int& sceneID) const;
private:
    Level* currentLevel = nullptr;
    int playerID = 0;
    std::vector<int> threats;
    std::vector<int> blocks;
};
