#include "User.h"

User::User() : user_name(""), password("") {}

User::User(const string& data) {
    vector< string > user_data = Decrypt_Data(data);
    assert(user_data.size() == 3);

    setUserName(user_data[0]);
    setPassword(user_data[1]);
    setEmail(user_data[2]);
}

string User::encrypt_user() const {
    ostringstream oss;
    oss << user_name << "|" << password << "|" << email << "|\n";
    return oss.str();
}

void User::Read_User(const string & name) {
    setUserName(name);

    string Input;

    cout << "Enter Password:\n";
    getline(cin, Input);
    setPassword(Input);

    cout << "Enter E-mail:\n";
    getline(cin, Input);
    setEmail(Input);

}

void User::print_user() const {
    cout << encrypt_user();
}

void User::setUserName(const string &userName) {
    this->user_name = userName;
}

void User::setPassword(const string &password) {
    this->password = password;
}

void User::setEmail(const string &email) {
    this->email = email;
}

const string &User::getUserName() const {
    return user_name;
}

const string &User::getPassword() const {
    return password;
}

const string &User::getEmail() const {
    return email;
}

