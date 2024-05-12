#include "BaseObject.h"

ClassType* BaseObject::GetClass()
{
    return ClassManager::Get()->GetClass("BaseObject", nullptr);
}

ClassType* BaseObject::StaticClass()
{
    return ClassManager::Get()->GetClass("BaseObject", nullptr);
}