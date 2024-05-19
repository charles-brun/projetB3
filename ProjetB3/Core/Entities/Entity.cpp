#include "Entity.h"
#include "../../Utils/ClassManager.h"
#include "../../Utils/Factory.h"
#include "../Components/Transform.h"
#include "../Systems/InputManager.h"

void Entity::Initialize()
{
    AddComponent(CTransform::StaticClass()->GetId());
}

void Entity::AddComponent(const int& classID)
{
    if (components.contains(classID))
    {
        return;
    }
    Component* component = Factory::Get()->CreateComponent(classID);
    components.insert(std::pair(classID, component));
}

Component* Entity::GetComponent(const int& classID) const
{
    if (!components.contains(classID))
    {
        return nullptr;
    }
    return components.find(classID)->second;
}

CTransform* Entity::GetTransform() const
{
    if (GetComponent(CTransform::StaticClass()->GetId()) == nullptr)
    {
        return nullptr;
    }
    return dynamic_cast<CTransform*>(GetComponent(CTransform::StaticClass()->GetId()));
}

void Entity::Update(const float& deltaTime)
{
    for (auto component: components)
    {
        component.second->Update(deltaTime);
    }
}

Entity::~Entity()
{
    for (const std::pair<const int&, Component*> component: components)
    {
        delete component.second;
    }
}
