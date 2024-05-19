#include "Factory.h"
#include "../Core/Components/AnimatedSprite.h"
#include "../Core/Components/BoundingBox.h"
#include "../Core/Components/Physics.h"
#include "../Core/Entities/Block.h"
#include "../Core/Entities/Player.h"
#include "../Core/Components/Transform.h"
#include "../Core/Entities/Threat.h"
#include "../Core/Scenes/GameScene.h"
#include "../Core/Scenes/MenuScene.h"

// TODO: Make polymorphic

Component* Factory::CreateComponent(const int& classId)
{
    Component* component = nullptr;
    if (classId == CAnimatedSprite::StaticClass()->GetId())
    {
        component = new CAnimatedSprite();
    }
    else if (classId == CBoundingBox::StaticClass()->GetId())
    {
        component = new CBoundingBox();
    }
    else if (classId == CPhysics::StaticClass()->GetId())
    {
        component = new CPhysics();
    }
    else if (classId == CSprite::StaticClass()->GetId())
    {
        component = new CSprite();
    }
    else if (classId == CTransform::StaticClass()->GetId())
    {
        component = new CTransform();
    }
    allObjects.push_back(component);
    return component;
}

Scene* Factory::CreateScene(const int& classID)
{
    Scene* scene = nullptr;
    if (classID == GameScene::StaticClass()->GetId())
    {
        scene = new GameScene();
    }
    else if (classID == MenuScene::StaticClass()->GetId())
    {
        scene = new MenuScene();
    }
    allObjects.push_back(scene);
    return scene;
}

UIElement* Factory::CreateUIElement(const int& classID)
{
    UIElement* uiElement = nullptr;

    allObjects.push_back(uiElement);
    return uiElement;
}

Level* Factory::CreateLevel(const int& classID)
{
    Level* level = new Level();

    allObjects.push_back(level);
    return level;
}

Entity* Factory::SpawnEntity(const int& classId, Vector2 startingPosition)
{
    Entity* entity = nullptr;
    if (classId == EPlayer::StaticClass()->GetId())
    {
        entity = new EPlayer();
    }
    else if (classId == EBlock::StaticClass()->GetId())
    {
        entity = new EBlock();
    }
    else if (classId == EThreat::StaticClass()->GetId())
    {
        entity = new EThreat();
    }
    allObjects.push_back(entity);
    entity->Initialize();
    if (entity->GetTransform() == nullptr)
    {
        return nullptr;
    }
    entity->GetTransform()->SetPosition(startingPosition);
    return entity;
}

Factory::~Factory()
{
    for (BaseObject* baseObject: allObjects)
    {
        delete baseObject;
    }
}