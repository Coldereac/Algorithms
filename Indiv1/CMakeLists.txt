# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


project(Prakt5)
set(CMAKE_CXX_STANDARD 20)


# Add tasks subprojects
add_executable(Indiv1 main.cpp CountryList/CountryList.h CountryList/CountryList.cpp
        handlers/handlers.cpp
        handlers/handlers.h)