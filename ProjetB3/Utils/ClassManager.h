#pragma once
#include <map>
#include "ClassType.h"

class ClassManager
{
public:
    static ClassManager* Instance; 
    static ClassManager* Get();
    static void Reset();
    ClassType* GetClass(const std::string& className, ClassType* parentClass);
    ClassType* GetClassByID(const int& ID) const;
private:
    std::map<int, ClassType*> classTypes;
    ClassType* AddClass(const std::string& className, ClassType* parentClass);
};