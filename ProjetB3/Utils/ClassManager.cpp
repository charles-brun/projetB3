#include "ClassManager.h"

ClassType* ClassManager::GetClass(const std::string& className, ClassType* parentClass)
{
    for (auto existingClass: classTypes)
    {
        if (existingClass.second->GetName() == className)
        {
            return existingClass.second;
        }
    }
    return AddClass(className, parentClass);
}

ClassType* ClassManager::GetClassByID(const int& ID) const
{
    if (!classTypes.contains(ID))
    {
        return nullptr;
    }
    return classTypes.find(ID)->second;
}

ClassType* ClassManager::AddClass(const std::string& className, ClassType* parentClass)
{
    int classID = 0;
    do
    {
        ++classID;
    } while (classTypes.contains(classID));
    ClassType* newClass = new ClassType(className, parentClass, classID);
    classTypes.insert(std::pair(classID, newClass));
    return newClass;
}

