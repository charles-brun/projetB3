#pragma once

#define DECLARE_SINGLETON(Class)\
static Class* Instance = nullptr;\
static Class* Get(){\
if (Instance == nullptr){\
Instance = new Class();\
};\
return Instance;\
};\
static void Reset(){\
delete Instance;\
}