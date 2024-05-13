#include "Entity.h"
#include "../../Utils/ClassManager.h"
#include "../../Utils/Factory.h"
#include "../Components/Transform.h"
#include "../Systems/InputManager.h"

Entity::Entity()
{
    AddComponent(CTransform::StaticClass()->GetId());
}

void Entity::Initialize()
{
}

void Entity::AddComponent(const int& classID)
{
    if (components.contains(classID))
    {
        return;
    }
    Component* component = Factory::CreateComponent(classID);
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

void Entity::Update(const float& deltaTime)
{
}

void Entity::Draw(const float& deltaTime)
{
}

Entity::~Entity()
{
    for (const std::pair<const int&, Component*> component: components)
    {
        delete component.second;
    }
}
