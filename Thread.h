#pragma once

#include "cassert"
#include "sstream"
#include "DataBase.h"
#include "MyUtility.h"
using namespace std;

class Thread {
private:
    int thread_id;
    int thread_parent_id;
    string thread_creator;
    string thread_text;

public:
    Thread();

    Thread(const string & data);

    string IDsToString() const;

    string encrypt_thread() const;

    void Show_ThreadHead(const int & thread_depth) const;

    void Show_ThreadBody(const int & thread_depth) const;

    void Show_thread(const int & thread_depth = 0) const;

    void setThreadId(const int & threadId);

    void setThreadParentId(const int & threadParentId);

    void setThreadCreator(const string &threadCreator);

    void setThreadText(const string &threadText);

    const int &getThreadId() const;

    const int &getThreadParentId() const;

    const string &getThreadCreator() const;

    const string &getThreadText() const;

};
