#pragma once
#include "Application/AppBase.h"
#include "Common/App_State.h"

class AppFactory {
public :
    static AppBase* create(Mode mode);
};