#pragma once

#include "string"
#include "vector"
#include "fstream"
#include "iostream"
using namespace std;
vector< string > Read_Database(const string& path);

void Write_To_Database(const string & path, const vector< string > & Database, const bool & overwrite);

vector< string > Decrypt_Data(const string & Data, const char & delimiter = '|');

