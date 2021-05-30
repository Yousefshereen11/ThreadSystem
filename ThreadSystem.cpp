#include "ThreadSystem.h"

void ThreadSystem::Run() {
    Load_Database();
    User_Manager.AccessSystem();

    vector<string> menu;
    menu.emplace_back("Feed");
    menu.emplace_back("Show Thread");
    menu.emplace_back("Creat or Answer Thread");
    menu.emplace_back("Delete Thread");
    menu.emplace_back("Logout");

    while(true) {
        int choice = Show_Menu(menu);
        Load_Database();

        if(choice == 1) {
            Thread_Manager.Show_feed();
        }

        else if(choice == 2){
            Thread_Manager.Show_Thread();
        }

        else if(choice == 3){
            const User& user = User_Manager.getCurrentUser();
            Thread_Manager.Create_Thread(user);
        }

        else if(choice == 4){
            const User& user = User_Manager.getCurrentUser();
            Thread_Manager.Delete_Thread(user);
        }

        else {
            break;
        }

    }
    Run();

}
