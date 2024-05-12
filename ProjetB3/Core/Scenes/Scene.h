#pragma once
#include "../Game/BaseObject.h"

class Scene: BaseObject
{
public:
    DECLARE_CLASS(Scene, BaseObject)
    virtual void Load();
    ~Scene() = default;
};
