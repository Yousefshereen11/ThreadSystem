#pragma once

#include "map"
#include "User.h"
#include "MyUtility.h"
using namespace std;

class UserManager {
private:
    map < string, User > UserName_UserObject;
    User current_user;
public:
    UserManager();

    void Load_DataBase();

    void AccessSystem();

    void Login();

    void SignUp();

    void Update_Database(const User& user);

    const User &getCurrentUser() const;


};


