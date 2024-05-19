#pragma once
#include "../Game/BaseObject.h"

class Entity;

class Component: public BaseObject
{
public:
    DECLARE_CLASS(Component, BaseObject)
    Component() = default;
    virtual void Initialize();
    virtual void Update(const float& deltaTime);
};

