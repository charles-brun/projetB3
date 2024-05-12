#pragma once
#include <map>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../../Utils/Delegate.h"
#include "../../Utils/Singleton.h"

class SInputManager: Singleton
{
public:
    inline DECLARE_SINGLETON(SInputManager)
    enum KeyState
    {
        Pressed,
        Released
    };
    DECLARE_DELEGATE(FKeyEvent, KeyState)        
    struct InputAction
    {
        std::string name;
        FKeyEvent inputEvent;
        InputAction(const std::string& pName): name(pName) {}
        void Emit(KeyState keyState)
        {
            inputEvent.BroadCast(keyState);
        }
    };
    struct KeyBind
    {
        sf::Keyboard::Key key;
        std::vector<InputAction*> inputActions;
        KeyBind(const sf::Keyboard::Key& pKey): key(pKey) {}
    };
    std::map<sf::Keyboard::Key, KeyBind*> keyBinds;
    std::map<std::string, InputAction*> inputActions;
    void Bind(const std::string& pName, const sf::Keyboard::Key& pKey);
    void AddInputAction(const std::string& pName, const sf::Keyboard::Key& pKey = sf::Keyboard::Unknown);

    template<typename T, typename ...Args>
    void Connect(const std::string& IAName, T* instance, void(T::*func)(Args...))
    {
        if (!inputActions.contains(IAName))
        {
            return;
        }
        inputActions.find(IAName)->second->inputEvent.Bind(instance, func);
    }
    void HandleInput(sf::RenderWindow* mainWindow) const;
};
