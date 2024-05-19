#include "Game.h"
#include "../../Utils/Factory.h"
#include "../Scenes/GameScene.h"
#include "../Systems/InputManager.h"
#include "../Systems/SceneManager.h"
#include "../Systems/SystemManager.h"

void Game::Initialize()
{
    GameScene* gameScene = dynamic_cast<GameScene*>(SSceneManager::Get()->LoadScene(GameScene::StaticClass()->GetId()));
    Level* level = Factory::Get()->CreateLevel(Level::StaticClass()->GetId());
    level->Initialize();
    gameScene->SetLevel(level);
    gameScene->Load();
    SInputManager::Get()->AddInputAction("moveLeft", sf::Keyboard::Key::Q);
    SInputManager::Get()->Connect("moveLeft", gameScene->GetPlayer(), &EPlayer::OnMoveLeft);
    SInputManager::Get()->AddInputAction("moveRight", sf::Keyboard::Key::D);
    SInputManager::Get()->Connect("moveRight", gameScene->GetPlayer(), &EPlayer::OnMoveRight);
    SInputManager::Get()->AddInputAction("jump", sf::Keyboard::Key::Space);
    SInputManager::Get()->Connect("jump", gameScene->GetPlayer(), &EPlayer::OnJump);
}

void Game::Run(sf::RenderWindow* mainWindow)
{
    while (mainWindow->isOpen())
    {
        sf::Clock dtClock;
        float deltaTime = dtClock.restart().asSeconds();
        SystemManager::Get()->Update(deltaTime, mainWindow);
    }
}
