#include "DataBase.h"

vector< string > Read_Database(const string& path){ // read from the file
    vector< string > Database;
    fstream Data(path.c_str());
    if(Data.fail()){
        cout << "Error Can't Access the Database\n";
        return Database;
    }
    string current_data;
    while (getline(Data, current_data)){
        if(current_data.empty()) {
            continue;
        }
        Database.emplace_back(current_data);
    }
    return Database;
}

void Write_To_Database(const string & path, const vector< string > & Database, const bool & overwrite){ // write to the file
    auto status = ios::in | ios::out | ios::app;
    if(overwrite == true){
        status = ios::in | ios::out | ios::trunc;
    }
    fstream Data(path.c_str(), status);
    if(Data.fail()){
        cout << "Error Can't Access the Database\n";
        return;
    }
    for(auto & current_data : Database){
        Data << current_data << '\n';
    }
    Data.close();
}

vector< string > Decrypt_Data(const string & Data, const char & delimiter){
    vector< string > Decrypted_data;
    string current_data;
    for(auto current_char : Data){
        if(current_char == delimiter){
            Decrypted_data.emplace_back(current_data);
            current_data.clear();
        }
        else {
            current_data += current_char;
        }
    }
    return Decrypted_data;
}