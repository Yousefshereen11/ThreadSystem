#pragma once

#include "istream"
#include "Thread.h"
#include "User.h"
#include "map"
#include "set"
using namespace std;

class ThreadManager {
private:
    int LastThreadID;
    map < int, vector< Thread > > ThreadParentIdToThreads;
    map < int, Thread > ThreadIdToThread;
public:
    ThreadManager();

    void Load_Database();

    void Show_feed();

    int ReadThreadId(const bool & CreateThread = false) const;

    void Show_Thread();

    map < int, bool > getUserThreads(const User& user);

    void Create_Thread(const User & user);

    void Delete_Thread(const User & user);

    void Update_Database(const Thread& thread);

    void Update_Database();
};


