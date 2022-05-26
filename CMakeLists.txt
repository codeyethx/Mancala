cmake_minimum_required(VERSION 3.17)
project(mancala)

set(CMAKE_CXX_STANDARD 14)

add_executable(mancala mancala.cpp MancalaBoard.cpp MancalaBoard.h Player.h Player.cpp Game.cpp Game.h Pocket.h Pocket.cpp NormalPocket.h NormalPocket.cpp MancalaPocket.h MancalaPocket.cpp)
