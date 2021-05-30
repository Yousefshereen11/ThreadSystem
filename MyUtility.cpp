#include "MyUtility.h"
#include "DataBase.h"

void Show_Text(const string & text, const int & thread_depth){ // function to print the thread according to the depth of the thread
    vector< string > decrypted_text = Decrypt_Data(text, ' ');
    int current_lenth = thread_depth;

    cout << string(thread_depth, ' ');

    for(const auto & current_text : decrypted_text){

        if(current_lenth + current_text.size() >= 100) {
            cout << "\n" << string(thread_depth, ' ');
            current_lenth = thread_depth;
        }

        cout << current_text << " ";
        current_lenth += current_text.size() + 1;
    }
    cout << '\n';
}

int ReadInt(int low, int high) {
    cout << "\nEnter number in range " << low << " - " << high << ": ";
    int value;

    cin >> value;
    cout << "\n";
    if (low <= value && value <= high)
        return value;

    cout << "ERROR: invalid number...Try again\n";
    return ReadInt(low, high);
}


int Show_Menu(const vector < string > & menu) {
    cout << "\nMenu:\n";

    for (int choice = 0; choice < (int) menu.size(); ++choice) {
        cout << "\t" << choice + 1 << ": " << menu[choice] << "\n";
    }

    return ReadInt(1, menu.size());
}
