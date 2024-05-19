#include "InputManager.h"

void SInputManager::Bind(const std::string& pName, const sf::Keyboard::Key& pKey)
{
    if (!inputActions.contains(pName))
    {
        return;
    }
    if (!keyBinds.contains(pKey))
    {
        keyBinds.insert(std::pair(pKey, new KeyBind(pKey)));
    }
    keyBinds.find(pKey)->second->inputActions.push_back(inputActions.find(pName)->second);
}

void SInputManager::AddInputAction(const std::string& pName, const sf::Keyboard::Key& pKey)
{
    if (inputActions.contains(pName))
    {
        return;
    }
    inputActions.insert(std::pair(pName, new InputAction(pName)));
    if (pKey != sf::Keyboard::Unknown)
    {
        Bind(pName, pKey);
    }
}

void SInputManager::HandleInput(sf::RenderWindow* mainWindow) const
{
    sf::Event event;
    while(mainWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            mainWindow->close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (keyBinds.contains(event.key.code))
            {
                for (auto inputAction: keyBinds.find(event.key.code)->second->inputActions)
                {
                    inputAction->Emit(KeyState::Pressed);
                }
            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if (keyBinds.contains(event.key.code))
            {
                for (auto inputAction: keyBinds.find(event.key.code)->second->inputActions)
                {
                    inputAction->Emit(KeyState::Released);
                }
            }
        }
    }
}
