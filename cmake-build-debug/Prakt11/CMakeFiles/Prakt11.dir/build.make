# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/malinka/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/malinka/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/malinka/CLionProjects/Algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/malinka/CLionProjects/Algorithms/cmake-build-debug

# Include any dependencies generated for this target.
include Prakt11/CMakeFiles/Prakt11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Prakt11/CMakeFiles/Prakt11.dir/compiler_depend.make

# Include the progress variables for this target.
include Prakt11/CMakeFiles/Prakt11.dir/progress.make

# Include the compile flags for this target's objects.
include Prakt11/CMakeFiles/Prakt11.dir/flags.make

Prakt11/CMakeFiles/Prakt11.dir/main.cpp.o: Prakt11/CMakeFiles/Prakt11.dir/flags.make
Prakt11/CMakeFiles/Prakt11.dir/main.cpp.o: /home/malinka/CLionProjects/Algorithms/Prakt11/main.cpp
Prakt11/CMakeFiles/Prakt11.dir/main.cpp.o: Prakt11/CMakeFiles/Prakt11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/malinka/CLionProjects/Algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Prakt11/CMakeFiles/Prakt11.dir/main.cpp.o"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt11 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Prakt11/CMakeFiles/Prakt11.dir/main.cpp.o -MF CMakeFiles/Prakt11.dir/main.cpp.o.d -o CMakeFiles/Prakt11.dir/main.cpp.o -c /home/malinka/CLionProjects/Algorithms/Prakt11/main.cpp

Prakt11/CMakeFiles/Prakt11.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Prakt11.dir/main.cpp.i"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt11 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malinka/CLionProjects/Algorithms/Prakt11/main.cpp > CMakeFiles/Prakt11.dir/main.cpp.i

Prakt11/CMakeFiles/Prakt11.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Prakt11.dir/main.cpp.s"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt11 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malinka/CLionProjects/Algorithms/Prakt11/main.cpp -o CMakeFiles/Prakt11.dir/main.cpp.s

# Object files for target Prakt11
Prakt11_OBJECTS = \
"CMakeFiles/Prakt11.dir/main.cpp.o"

# External object files for target Prakt11
Prakt11_EXTERNAL_OBJECTS =

Prakt11/Prakt11: Prakt11/CMakeFiles/Prakt11.dir/main.cpp.o
Prakt11/Prakt11: Prakt11/CMakeFiles/Prakt11.dir/build.make
Prakt11/Prakt11: Prakt11/CMakeFiles/Prakt11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/malinka/CLionProjects/Algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Prakt11"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt11 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prakt11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Prakt11/CMakeFiles/Prakt11.dir/build: Prakt11/Prakt11
.PHONY : Prakt11/CMakeFiles/Prakt11.dir/build

Prakt11/CMakeFiles/Prakt11.dir/clean:
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt11 && $(CMAKE_COMMAND) -P CMakeFiles/Prakt11.dir/cmake_clean.cmake
.PHONY : Prakt11/CMakeFiles/Prakt11.dir/clean

Prakt11/CMakeFiles/Prakt11.dir/depend:
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malinka/CLionProjects/Algorithms /home/malinka/CLionProjects/Algorithms/Prakt11 /home/malinka/CLionProjects/Algorithms/cmake-build-debug /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt11 /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt11/CMakeFiles/Prakt11.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Prakt11/CMakeFiles/Prakt11.dir/depend

