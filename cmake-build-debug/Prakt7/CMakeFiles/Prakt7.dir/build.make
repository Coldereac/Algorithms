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
include Prakt7/CMakeFiles/Prakt7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Prakt7/CMakeFiles/Prakt7.dir/compiler_depend.make

# Include the progress variables for this target.
include Prakt7/CMakeFiles/Prakt7.dir/progress.make

# Include the compile flags for this target's objects.
include Prakt7/CMakeFiles/Prakt7.dir/flags.make

Prakt7/CMakeFiles/Prakt7.dir/main.cpp.o: Prakt7/CMakeFiles/Prakt7.dir/flags.make
Prakt7/CMakeFiles/Prakt7.dir/main.cpp.o: /home/malinka/CLionProjects/Algorithms/Prakt7/main.cpp
Prakt7/CMakeFiles/Prakt7.dir/main.cpp.o: Prakt7/CMakeFiles/Prakt7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/malinka/CLionProjects/Algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Prakt7/CMakeFiles/Prakt7.dir/main.cpp.o"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Prakt7/CMakeFiles/Prakt7.dir/main.cpp.o -MF CMakeFiles/Prakt7.dir/main.cpp.o.d -o CMakeFiles/Prakt7.dir/main.cpp.o -c /home/malinka/CLionProjects/Algorithms/Prakt7/main.cpp

Prakt7/CMakeFiles/Prakt7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Prakt7.dir/main.cpp.i"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malinka/CLionProjects/Algorithms/Prakt7/main.cpp > CMakeFiles/Prakt7.dir/main.cpp.i

Prakt7/CMakeFiles/Prakt7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Prakt7.dir/main.cpp.s"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malinka/CLionProjects/Algorithms/Prakt7/main.cpp -o CMakeFiles/Prakt7.dir/main.cpp.s

Prakt7/CMakeFiles/Prakt7.dir/functions.cpp.o: Prakt7/CMakeFiles/Prakt7.dir/flags.make
Prakt7/CMakeFiles/Prakt7.dir/functions.cpp.o: /home/malinka/CLionProjects/Algorithms/Prakt7/functions.cpp
Prakt7/CMakeFiles/Prakt7.dir/functions.cpp.o: Prakt7/CMakeFiles/Prakt7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/malinka/CLionProjects/Algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Prakt7/CMakeFiles/Prakt7.dir/functions.cpp.o"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Prakt7/CMakeFiles/Prakt7.dir/functions.cpp.o -MF CMakeFiles/Prakt7.dir/functions.cpp.o.d -o CMakeFiles/Prakt7.dir/functions.cpp.o -c /home/malinka/CLionProjects/Algorithms/Prakt7/functions.cpp

Prakt7/CMakeFiles/Prakt7.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Prakt7.dir/functions.cpp.i"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/malinka/CLionProjects/Algorithms/Prakt7/functions.cpp > CMakeFiles/Prakt7.dir/functions.cpp.i

Prakt7/CMakeFiles/Prakt7.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Prakt7.dir/functions.cpp.s"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/malinka/CLionProjects/Algorithms/Prakt7/functions.cpp -o CMakeFiles/Prakt7.dir/functions.cpp.s

# Object files for target Prakt7
Prakt7_OBJECTS = \
"CMakeFiles/Prakt7.dir/main.cpp.o" \
"CMakeFiles/Prakt7.dir/functions.cpp.o"

# External object files for target Prakt7
Prakt7_EXTERNAL_OBJECTS =

Prakt7/Prakt7: Prakt7/CMakeFiles/Prakt7.dir/main.cpp.o
Prakt7/Prakt7: Prakt7/CMakeFiles/Prakt7.dir/functions.cpp.o
Prakt7/Prakt7: Prakt7/CMakeFiles/Prakt7.dir/build.make
Prakt7/Prakt7: Prakt7/CMakeFiles/Prakt7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/malinka/CLionProjects/Algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Prakt7"
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prakt7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Prakt7/CMakeFiles/Prakt7.dir/build: Prakt7/Prakt7
.PHONY : Prakt7/CMakeFiles/Prakt7.dir/build

Prakt7/CMakeFiles/Prakt7.dir/clean:
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 && $(CMAKE_COMMAND) -P CMakeFiles/Prakt7.dir/cmake_clean.cmake
.PHONY : Prakt7/CMakeFiles/Prakt7.dir/clean

Prakt7/CMakeFiles/Prakt7.dir/depend:
	cd /home/malinka/CLionProjects/Algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/malinka/CLionProjects/Algorithms /home/malinka/CLionProjects/Algorithms/Prakt7 /home/malinka/CLionProjects/Algorithms/cmake-build-debug /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7 /home/malinka/CLionProjects/Algorithms/cmake-build-debug/Prakt7/CMakeFiles/Prakt7.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Prakt7/CMakeFiles/Prakt7.dir/depend

