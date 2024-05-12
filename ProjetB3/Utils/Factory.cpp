#include "Factory.h"

#include "../Core/Components/AnimatedSprite.h"
#include "../Core/Components/BoundingBox.h"
#include "../Core/Components/Physics.h"
#include "../Core/Entities/Block.h"
#include "../Core/Entities/Player.h"
#include "../Core/Components/Transform.h"
#include "../Core/Scenes/GameScene.h"
#include "../Core/Scenes/MenuScene.h"

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
    return scene;
}

EActor* Factory::SpawnActor(const int& classId, Vector2 startingPosition)
{
    EActor* actor = nullptr;
    if (classId == EPlayer::StaticClass()->GetId())
    {
        actor = new EPlayer();
    }
    else if (classId == EBlock::StaticClass()->GetId())
    {
        actor = new EBlock();
    }
    CTransform* transform = dynamic_cast<CTransform*>(actor->GetComponent(CTransform::StaticClass()->GetId()));
    if (transform == nullptr)
    {
        return nullptr;
    }
    transform->SetPosition(startingPosition);
    return actor;
}
