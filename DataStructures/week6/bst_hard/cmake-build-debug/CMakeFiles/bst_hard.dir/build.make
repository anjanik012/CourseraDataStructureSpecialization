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
CMAKE_SOURCE_DIR = /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bst_hard.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bst_hard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bst_hard.dir/flags.make

CMakeFiles/bst_hard.dir/main.cpp.o: CMakeFiles/bst_hard.dir/flags.make
CMakeFiles/bst_hard.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bst_hard.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bst_hard.dir/main.cpp.o -c /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/main.cpp

CMakeFiles/bst_hard.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bst_hard.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/main.cpp > CMakeFiles/bst_hard.dir/main.cpp.i

CMakeFiles/bst_hard.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bst_hard.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/main.cpp -o CMakeFiles/bst_hard.dir/main.cpp.s

# Object files for target bst_hard
bst_hard_OBJECTS = \
"CMakeFiles/bst_hard.dir/main.cpp.o"

# External object files for target bst_hard
bst_hard_EXTERNAL_OBJECTS =

bst_hard: CMakeFiles/bst_hard.dir/main.cpp.o
bst_hard: CMakeFiles/bst_hard.dir/build.make
bst_hard: CMakeFiles/bst_hard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bst_hard"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bst_hard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bst_hard.dir/build: bst_hard

.PHONY : CMakeFiles/bst_hard.dir/build

CMakeFiles/bst_hard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bst_hard.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bst_hard.dir/clean

CMakeFiles/bst_hard.dir/depend:
	cd /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/cmake-build-debug /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/cmake-build-debug /home/anjani/Programs/C++/DataStructures_and_Algorithms/DataStructures/week6/bst_hard/cmake-build-debug/CMakeFiles/bst_hard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bst_hard.dir/depend

