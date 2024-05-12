#pragma once
#include <vector>

#include "BaseObject.h"
#include "../../Maths/Vector2.h"

class Level: BaseObject
{
public:
    DECLARE_CLASS(Level, BaseObject)
    struct ActorData
    {
        int* classID;
        Vector2 startingPos;
    };
    std::vector<ActorData*> actors;
    Level();
    void Initialize();
};
