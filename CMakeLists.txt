cmake_minimum_required(VERSION 3.19)
project(AskMe)
set(CMAKE_CXX_STANDARD 14)

add_executable(ThreadSystem main.cpp User.cpp User.h DataBase.h DataBase.cpp Thread.cpp Thread.h MyUtility.cpp MyUtility.h UserManager.cpp UserManager.h ThreadManager.cpp ThreadManager.h ThreadSystem.cpp ThreadSystem.h)

