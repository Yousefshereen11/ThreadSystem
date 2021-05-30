#include "ThreadManager.h"

ThreadManager::ThreadManager() : LastThreadID(0) {}

void ThreadManager::Load_Database() {
    LastThreadID = 0;
    ThreadParentIdToThreads.clear();

    vector< string > Database = Read_Database("Threads_Database.txt");
    for(const auto & data : Database) {
        const Thread & thread(data);

        ThreadParentIdToThreads[thread.getThreadParentId()].emplace_back(thread);
        ThreadIdToThread[thread.getThreadId()] = thread;

        LastThreadID = max(LastThreadID, thread.getThreadId());

    }
}

void ThreadManager::Show_feed() {
    for(const auto & thread : ThreadParentIdToThreads[-1]){
        thread.Show_thread();
    }
}

int ThreadManager::ReadThreadId(const bool & CreateThread) const{
    int ThreadId;

    cout << "Enter Thread Id";
    if(CreateThread == true) {
        cout << " or Enter -1 if you want to start a new Thread";
    }
    cout << ":\n";

    cin >> ThreadId;

    if(ThreadId == -1)
        return -1;

    if(ThreadIdToThread.count(ThreadId) == 0){
        cout << "Error this Thread dos not exist, Try Again\n";
        return ReadThreadId();
    }

    return ThreadId;
}

void ThreadManager::Show_Thread() {
    const int & ThreadID = ReadThreadId();

    const auto & thread = ThreadIdToThread[ThreadID];
    thread.Show_thread(0);

    for(const auto & thread_reply : ThreadParentIdToThreads[thread.getThreadId()]) {
        thread_reply.Show_thread(4);
    }
}

map < int, bool > ThreadManager::getUserThreads(const User& user) {
    map < int, bool > userThreads;

    for(const auto & thread : ThreadIdToThread) {

        if(thread.second.getThreadCreator() == user.getUserName()){
            userThreads[thread.second.getThreadId()] = true;
        }
    }
    return userThreads;
}

void ThreadManager::Create_Thread(const User & user) {
    Thread new_thread;
    const int & ThreadId = ReadThreadId(true);
    ++LastThreadID;

    new_thread.setThreadId(LastThreadID);
    new_thread.setThreadParentId(ThreadId);
    new_thread.setThreadCreator(user.getUserName());

    cin.clear();
    cin.sync();

    cout << "Write your Thread now:\n";

    string ThreadText;
    getline(cin, ThreadText);

    new_thread.setThreadText(ThreadText);

    ThreadParentIdToThreads[new_thread.getThreadParentId()].emplace_back(new_thread);
    ThreadIdToThread[new_thread.getThreadId()] = new_thread;

    Update_Database(new_thread);

}

void ThreadManager::Delete_Thread(const User & user) {
    int ThreadId = ReadThreadId();
    const Thread & thread = ThreadIdToThread[ThreadId];
    while(user.getUserName() != thread.getThreadCreator()){
        cout << "Error you do not own this Thread, Try Again\n";
        ThreadId = ReadThreadId();
    }

    ThreadIdToThread.erase(ThreadId);

    auto vector_threads = ThreadParentIdToThreads[thread.getThreadParentId()];
    for(int index = 0; index < vector_threads.size(); ++index){

        if(vector_threads[index].getThreadId() == ThreadId){
            vector_threads.erase(vector_threads.begin() + index);
        }
    }
    Update_Database();
}

void ThreadManager::Update_Database(const Thread& thread) {
    vector< string > Data = { thread.encrypt_thread() };
    Write_To_Database("Threads_Database.txt", Data, false);
}

void ThreadManager::Update_Database(){
    vector< string > Data;

    for(auto thread : ThreadIdToThread){
        Data.emplace_back(thread.second.encrypt_thread());
    }
    Write_To_Database("Threads_Database.txt", Data, true);
}