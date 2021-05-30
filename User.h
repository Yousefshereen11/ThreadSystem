#pragma once

#include "sstream"
#include "cassert"
#include "DataBase.h"
#include "map"
using namespace std;

class User {
private:
    string user_name; // unique/ id
    string password;
    string email;

public:
    User();

    User(const string& data);

    string encrypt_user() const;

    void Read_User(const string & name);

    void print_user() const;

    void Reset_UserThreads(const map< int, bool > & User_Threads);

    void setUserName(const string &userName);

    void setPassword(const string &password);

    void setEmail(const string &email);

    const string &getUserName() const;

    const string &getPassword() const;

    const string &getEmail() const;



};

