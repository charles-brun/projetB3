#include "Entity.h"
#include "../../Utils/ClassManager.h"
#include "../../Utils/Factory.h"
#include "../Systems/EntityManager.h"
#include "../Components/Transform.h"
#include "../Systems/InputManager.h"

Entity::Entity()
{
    SEntityManager::Get()->NewEntityCreated.Bind(this, &Entity::OnNewEntityCreate);
    
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

void Entity::Update(float deltaTime)
{
}

void Entity::OnNewEntityCreate(int ID)
{
    //called on EntityManager signal
}

Entity::~Entity()
{
    for (const std::pair<const int&, Component*> component: components)
    {
        delete component.second;
    }
}
