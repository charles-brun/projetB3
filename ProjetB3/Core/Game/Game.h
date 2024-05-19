#pragma once
#include "../../Utils/Singleton.h"
#include "../Entities/Player.h"

class Game
{
public:
    inline DECLARE_SINGLETON(Game)
    void Initialize();
    void Run(sf::RenderWindow* mainWindow);
};
