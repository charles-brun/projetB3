#include "SystemManager.h"
#include "EntityManager.h"
#include "InputManager.h"
#include "UIManager.h"

void SystemManager::Update(const float& deltaTime, sf::RenderWindow* mainWindow)
{
    SInputManager::Get()->HandleInput(mainWindow);
    SEntityManager::Get()->Update(deltaTime);
    SUIManager::Get()->Update(deltaTime);
}
