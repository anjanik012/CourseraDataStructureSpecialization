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
CMAKE_SOURCE_DIR = /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/connected_components.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/connected_components.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/connected_components.dir/flags.make

CMakeFiles/connected_components.dir/main.cpp.o: CMakeFiles/connected_components.dir/flags.make
CMakeFiles/connected_components.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/connected_components.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/connected_components.dir/main.cpp.o -c /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/main.cpp

CMakeFiles/connected_components.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/connected_components.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/main.cpp > CMakeFiles/connected_components.dir/main.cpp.i

CMakeFiles/connected_components.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/connected_components.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/main.cpp -o CMakeFiles/connected_components.dir/main.cpp.s

# Object files for target connected_components
connected_components_OBJECTS = \
"CMakeFiles/connected_components.dir/main.cpp.o"

# External object files for target connected_components
connected_components_EXTERNAL_OBJECTS =

connected_components: CMakeFiles/connected_components.dir/main.cpp.o
connected_components: CMakeFiles/connected_components.dir/build.make
connected_components: CMakeFiles/connected_components.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable connected_components"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/connected_components.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/connected_components.dir/build: connected_components

.PHONY : CMakeFiles/connected_components.dir/build

CMakeFiles/connected_components.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/connected_components.dir/cmake_clean.cmake
.PHONY : CMakeFiles/connected_components.dir/clean

CMakeFiles/connected_components.dir/depend:
	cd /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/cmake-build-debug /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/cmake-build-debug /home/anjani/Programs/C++/DataStructures_and_Algorithms/Algorithms_on_graphs/week1/connected_components/cmake-build-debug/CMakeFiles/connected_components.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/connected_components.dir/depend

