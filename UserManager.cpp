#include "UserManager.h"

UserManager::UserManager() {}

void UserManager::Load_DataBase() {
    UserName_UserObject.clear();
    vector< string > Database = Read_Database("Users_Database.txt");

    for(const auto & data : Database){
        User user(data);
        UserName_UserObject[user.getUserName()] = user;
    }
}

void UserManager::AccessSystem() {
    int choice = Show_Menu( {"Login", "SignUp"});

    if(choice == 1)
        Login();
    else
        SignUp();
}

void UserManager::Login() {
    Load_DataBase();

    cin.clear();
    cin.sync();

    string name, password;
    cout << "Enter Username:\n";
    getline(cin, name);
    current_user.setUserName(name);

    cout << "Enter Password:\n";
    getline(cin, password);
    current_user.setPassword(password);

    if(UserName_UserObject.count(current_user.getUserName()) == 0){
        cout << "\nInvalid user name or password. Try again\n\n";
        AccessSystem();
    }
    const User& user = UserName_UserObject[current_user.getUserName()];

    if(current_user.getPassword() != user.getPassword()){
        cout << "\nInvalid user name or password. Try again\n\n";
        AccessSystem();
    }
    current_user = user;

}

void UserManager::SignUp() {
    Load_DataBase();

    cin.clear();
    cin.sync();

    string user_name;
    cout << "Enter Username:\n";
    getline(cin, user_name);

    if(UserName_UserObject.count(user_name)){
        cout << "Already used. Try again\n";
        SignUp();
    }

    current_user.Read_User(user_name);
    UserName_UserObject[current_user.getUserName()] = current_user;

    Update_Database(current_user);

}

void UserManager::Update_Database(const User& user) {
    vector< string > Data = { user.encrypt_user() };
    Write_To_Database("Users_Database.txt", Data, false);
}

const User &UserManager::getCurrentUser() const{
    return current_user;
}