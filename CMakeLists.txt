cmake_minimum_required(VERSION 3.26)
project(Program_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Program_1 main.cpp
        Account.h
        ATM.h
        Bank.h
        Account.cpp
        Bank.cpp
        ATM.cpp
)
