cmake_minimum_required(VERSION 3.28)
project(ADS_P1_2_Binaerbaum)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ADS_P1_2_Binaerbaum
        catch.h
        main.cpp
        Tree.cpp
        Tree.h
        TreeNode.cpp
        TreeNode.h
        TreeTest.cpp
        ExportZielanalyse.csv)
