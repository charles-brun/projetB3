#pragma once
#include "../../Utils/Singleton.h"
#include <SFML/Graphics.hpp>

class SystemManager
{
public:
    inline DECLARE_SINGLETON(SystemManager)
    void Update(const float& deltaTime, sf::RenderWindow* mainWindow);
};
