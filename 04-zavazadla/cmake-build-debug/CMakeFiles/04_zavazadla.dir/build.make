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
CMAKE_SOURCE_DIR = /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/04_zavazadla.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/04_zavazadla.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/04_zavazadla.dir/flags.make

CMakeFiles/04_zavazadla.dir/main.cpp.o: CMakeFiles/04_zavazadla.dir/flags.make
CMakeFiles/04_zavazadla.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/04_zavazadla.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/04_zavazadla.dir/main.cpp.o -c /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/main.cpp

CMakeFiles/04_zavazadla.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/04_zavazadla.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/main.cpp > CMakeFiles/04_zavazadla.dir/main.cpp.i

CMakeFiles/04_zavazadla.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/04_zavazadla.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/main.cpp -o CMakeFiles/04_zavazadla.dir/main.cpp.s

CMakeFiles/04_zavazadla.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/04_zavazadla.dir/main.cpp.o.requires

CMakeFiles/04_zavazadla.dir/main.cpp.o.provides: CMakeFiles/04_zavazadla.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/04_zavazadla.dir/build.make CMakeFiles/04_zavazadla.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/04_zavazadla.dir/main.cpp.o.provides

CMakeFiles/04_zavazadla.dir/main.cpp.o.provides.build: CMakeFiles/04_zavazadla.dir/main.cpp.o


# Object files for target 04_zavazadla
04_zavazadla_OBJECTS = \
"CMakeFiles/04_zavazadla.dir/main.cpp.o"

# External object files for target 04_zavazadla
04_zavazadla_EXTERNAL_OBJECTS =

04_zavazadla: CMakeFiles/04_zavazadla.dir/main.cpp.o
04_zavazadla: CMakeFiles/04_zavazadla.dir/build.make
04_zavazadla: CMakeFiles/04_zavazadla.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 04_zavazadla"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/04_zavazadla.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/04_zavazadla.dir/build: 04_zavazadla

.PHONY : CMakeFiles/04_zavazadla.dir/build

CMakeFiles/04_zavazadla.dir/requires: CMakeFiles/04_zavazadla.dir/main.cpp.o.requires

.PHONY : CMakeFiles/04_zavazadla.dir/requires

CMakeFiles/04_zavazadla.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/04_zavazadla.dir/cmake_clean.cmake
.PHONY : CMakeFiles/04_zavazadla.dir/clean

CMakeFiles/04_zavazadla.dir/depend:
	cd /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/cmake-build-debug /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/cmake-build-debug /home/jencmart/Dropbox/development/ClionProjects/ep1/04-zavazadla/cmake-build-debug/CMakeFiles/04_zavazadla.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/04_zavazadla.dir/depend

