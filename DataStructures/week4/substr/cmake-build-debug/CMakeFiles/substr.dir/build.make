# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/substr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/substr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/substr.dir/flags.make

CMakeFiles/substr.dir/main.cpp.o: CMakeFiles/substr.dir/flags.make
CMakeFiles/substr.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/substr.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/substr.dir/main.cpp.o -c /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/main.cpp

CMakeFiles/substr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/substr.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/main.cpp > CMakeFiles/substr.dir/main.cpp.i

CMakeFiles/substr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/substr.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/main.cpp -o CMakeFiles/substr.dir/main.cpp.s

# Object files for target substr
substr_OBJECTS = \
"CMakeFiles/substr.dir/main.cpp.o"

# External object files for target substr
substr_EXTERNAL_OBJECTS =

substr: CMakeFiles/substr.dir/main.cpp.o
substr: CMakeFiles/substr.dir/build.make
substr: CMakeFiles/substr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable substr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/substr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/substr.dir/build: substr

.PHONY : CMakeFiles/substr.dir/build

CMakeFiles/substr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/substr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/substr.dir/clean

CMakeFiles/substr.dir/depend:
	cd /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/cmake-build-debug /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/cmake-build-debug /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week4/substr/cmake-build-debug/CMakeFiles/substr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/substr.dir/depend

