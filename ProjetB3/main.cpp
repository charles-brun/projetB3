#include <SFML/Window.hpp>

#include "Core/Game/Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "ProjetB3");
    Game::Get()->Initialize();
    Game::Get()->Run(&window);
    window.setActive(true);

    return 0;
}
