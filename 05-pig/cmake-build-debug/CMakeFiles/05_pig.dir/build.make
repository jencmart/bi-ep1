# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jencmart/development/ClionProjects/ep1/05-pig

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jencmart/development/ClionProjects/ep1/05-pig/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/05_pig.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/05_pig.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/05_pig.dir/flags.make

CMakeFiles/05_pig.dir/main.cpp.o: CMakeFiles/05_pig.dir/flags.make
CMakeFiles/05_pig.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jencmart/development/ClionProjects/ep1/05-pig/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/05_pig.dir/main.cpp.o"
	/usr/sbin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/05_pig.dir/main.cpp.o -c /home/jencmart/development/ClionProjects/ep1/05-pig/main.cpp

CMakeFiles/05_pig.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/05_pig.dir/main.cpp.i"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jencmart/development/ClionProjects/ep1/05-pig/main.cpp > CMakeFiles/05_pig.dir/main.cpp.i

CMakeFiles/05_pig.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/05_pig.dir/main.cpp.s"
	/usr/sbin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jencmart/development/ClionProjects/ep1/05-pig/main.cpp -o CMakeFiles/05_pig.dir/main.cpp.s

CMakeFiles/05_pig.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/05_pig.dir/main.cpp.o.requires

CMakeFiles/05_pig.dir/main.cpp.o.provides: CMakeFiles/05_pig.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/05_pig.dir/build.make CMakeFiles/05_pig.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/05_pig.dir/main.cpp.o.provides

CMakeFiles/05_pig.dir/main.cpp.o.provides.build: CMakeFiles/05_pig.dir/main.cpp.o


# Object files for target 05_pig
05_pig_OBJECTS = \
"CMakeFiles/05_pig.dir/main.cpp.o"

# External object files for target 05_pig
05_pig_EXTERNAL_OBJECTS =

05_pig: CMakeFiles/05_pig.dir/main.cpp.o
05_pig: CMakeFiles/05_pig.dir/build.make
05_pig: CMakeFiles/05_pig.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jencmart/development/ClionProjects/ep1/05-pig/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 05_pig"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/05_pig.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/05_pig.dir/build: 05_pig

.PHONY : CMakeFiles/05_pig.dir/build

CMakeFiles/05_pig.dir/requires: CMakeFiles/05_pig.dir/main.cpp.o.requires

.PHONY : CMakeFiles/05_pig.dir/requires

CMakeFiles/05_pig.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/05_pig.dir/cmake_clean.cmake
.PHONY : CMakeFiles/05_pig.dir/clean

CMakeFiles/05_pig.dir/depend:
	cd /home/jencmart/development/ClionProjects/ep1/05-pig/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jencmart/development/ClionProjects/ep1/05-pig /home/jencmart/development/ClionProjects/ep1/05-pig /home/jencmart/development/ClionProjects/ep1/05-pig/cmake-build-debug /home/jencmart/development/ClionProjects/ep1/05-pig/cmake-build-debug /home/jencmart/development/ClionProjects/ep1/05-pig/cmake-build-debug/CMakeFiles/05_pig.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/05_pig.dir/depend

