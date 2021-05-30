#pragma once

#include "UserManager.h"
#include "ThreadManager.h"

class ThreadSystem {
private:
    UserManager User_Manager;
    ThreadManager Thread_Manager;

    void Load_Database() {
        User_Manager.Load_DataBase();
        Thread_Manager.Load_Database();
    }

public:
    void Run();

};


