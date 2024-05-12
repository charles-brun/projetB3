#pragma once
#include "../Game/BaseObject.h"

class Component: BaseObject
{
public:
    DECLARE_CLASS(Component, BaseObject)
    Component() = default;
};