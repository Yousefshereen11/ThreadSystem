#include "Thread.h"

Thread::Thread() : thread_id(-1), thread_parent_id(-1) {}

Thread::Thread(const string & data){
    vector< string > thread_data = Decrypt_Data(data);
    assert(thread_data.size() == 4);

    setThreadId(stoi(thread_data[0]));
    setThreadParentId(stoi(thread_data[1]));
    setThreadCreator(thread_data[2]);
    setThreadText(thread_data[3]);
}

string Thread::IDsToString() const{
    ostringstream oss;
    oss << "@" << thread_creator << ": Thread ID: (" << thread_id << ") \n";
    return oss.str();
}

string Thread::encrypt_thread() const {
    ostringstream oss;
    oss << thread_id << "|" << thread_parent_id << "|" << thread_creator << "|" << thread_text << "|\n";
    return oss.str();
}

void Thread::Show_ThreadHead(const int & thread_depth) const {
    Show_Text(IDsToString(), thread_depth);
}

void Thread::Show_ThreadBody(const int & thread_depth) const {
    Show_Text(thread_text, thread_depth + getThreadCreator().size() + 2);
}

void Thread::Show_thread(const int & thread_depth) const{
    Show_ThreadHead(thread_depth);
    Show_ThreadBody(thread_depth);
    cout << "\n";
}

void Thread::setThreadId(const int & threadId) {
    this->thread_id = threadId;
}

void Thread::setThreadParentId(const int & threadParentId) {
    this->thread_parent_id = threadParentId;
}

void Thread::setThreadCreator(const string &threadCreator) {
    this->thread_creator = threadCreator;
}

void Thread::setThreadText(const string &threadText) {
    this->thread_text = threadText;
}

const int &Thread::getThreadId() const {
    return thread_id;
}

const int &Thread::getThreadParentId() const {
    return thread_parent_id;
}

const string &Thread::getThreadCreator() const {
    return thread_creator;
}

const string &Thread::getThreadText() const {
    return thread_text;
}