# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


project(Prakt4)

set(CMAKE_CXX_STANDARD 20)


# Add tasks subprojects
add_executable(Prakt4_3 main.cpp functions.cpp functions.h)