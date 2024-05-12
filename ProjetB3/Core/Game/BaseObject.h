#pragma once
#include "../../Utils/ClassManager.h"

#define DECLARE_CLASS(Class, Parent)\
virtual ClassType* GetClass(){\
return ClassManager::Get()->GetClass(#Class, Parent::StaticClass());\
};\
static ClassType* StaticClass(){\
return ClassManager::Get()->GetClass(#Class, Parent::StaticClass());\
}

class BaseObject
{
public:
    virtual ClassType* GetClass();
    static ClassType* StaticClass();
    virtual ~BaseObject() = default;
};
