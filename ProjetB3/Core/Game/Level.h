#pragma once
#include <vector>

#include "BaseObject.h"
#include "../../Maths/Vector2.h"

class Level: public BaseObject
{
public:
    DECLARE_CLASS(Level, BaseObject)
    struct ActorData
    {
        int classID;
        Vector2 startingPos;
        ActorData(int pID, Vector2 pPos): classID(pID), startingPos(pPos) {}
    };
    std::vector<ActorData*> actors;
    Level() = default;
    // ADD loading from file
    void Initialize();
    ~Level();
};
