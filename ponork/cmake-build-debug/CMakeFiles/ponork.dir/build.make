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
CMAKE_SOURCE_DIR = /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ponork.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ponork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ponork.dir/flags.make

CMakeFiles/ponork.dir/main.cpp.o: CMakeFiles/ponork.dir/flags.make
CMakeFiles/ponork.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ponork.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ponork.dir/main.cpp.o -c /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/main.cpp

CMakeFiles/ponork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ponork.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/main.cpp > CMakeFiles/ponork.dir/main.cpp.i

CMakeFiles/ponork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ponork.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/main.cpp -o CMakeFiles/ponork.dir/main.cpp.s

CMakeFiles/ponork.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ponork.dir/main.cpp.o.requires

CMakeFiles/ponork.dir/main.cpp.o.provides: CMakeFiles/ponork.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ponork.dir/build.make CMakeFiles/ponork.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ponork.dir/main.cpp.o.provides

CMakeFiles/ponork.dir/main.cpp.o.provides.build: CMakeFiles/ponork.dir/main.cpp.o


# Object files for target ponork
ponork_OBJECTS = \
"CMakeFiles/ponork.dir/main.cpp.o"

# External object files for target ponork
ponork_EXTERNAL_OBJECTS =

ponork: CMakeFiles/ponork.dir/main.cpp.o
ponork: CMakeFiles/ponork.dir/build.make
ponork: CMakeFiles/ponork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ponork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ponork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ponork.dir/build: ponork

.PHONY : CMakeFiles/ponork.dir/build

CMakeFiles/ponork.dir/requires: CMakeFiles/ponork.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ponork.dir/requires

CMakeFiles/ponork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ponork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ponork.dir/clean

CMakeFiles/ponork.dir/depend:
	cd /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/cmake-build-debug /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/cmake-build-debug /home/jencmart/Dropbox/development/ClionProjects/ep1/ponork/cmake-build-debug/CMakeFiles/ponork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ponork.dir/depend

