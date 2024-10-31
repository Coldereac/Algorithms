# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


project(Indiv1_correct)
set(CMAKE_CXX_STANDARD 20)


# Add tasks subprojects
add_executable(Indiv1_correct main.cpp functions.cpp
        handlers/menu.cpp
        handlers/menu.h
        functions.h)