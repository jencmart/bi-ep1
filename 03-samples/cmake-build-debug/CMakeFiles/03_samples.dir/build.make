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
CMAKE_SOURCE_DIR = /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/03_samples.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/03_samples.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/03_samples.dir/flags.make

CMakeFiles/03_samples.dir/main.cpp.o: CMakeFiles/03_samples.dir/flags.make
CMakeFiles/03_samples.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/03_samples.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/03_samples.dir/main.cpp.o -c /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/main.cpp

CMakeFiles/03_samples.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/03_samples.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/main.cpp > CMakeFiles/03_samples.dir/main.cpp.i

CMakeFiles/03_samples.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/03_samples.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/main.cpp -o CMakeFiles/03_samples.dir/main.cpp.s

CMakeFiles/03_samples.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/03_samples.dir/main.cpp.o.requires

CMakeFiles/03_samples.dir/main.cpp.o.provides: CMakeFiles/03_samples.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/03_samples.dir/build.make CMakeFiles/03_samples.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/03_samples.dir/main.cpp.o.provides

CMakeFiles/03_samples.dir/main.cpp.o.provides.build: CMakeFiles/03_samples.dir/main.cpp.o


# Object files for target 03_samples
03_samples_OBJECTS = \
"CMakeFiles/03_samples.dir/main.cpp.o"

# External object files for target 03_samples
03_samples_EXTERNAL_OBJECTS =

03_samples: CMakeFiles/03_samples.dir/main.cpp.o
03_samples: CMakeFiles/03_samples.dir/build.make
03_samples: CMakeFiles/03_samples.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 03_samples"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/03_samples.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/03_samples.dir/build: 03_samples

.PHONY : CMakeFiles/03_samples.dir/build

CMakeFiles/03_samples.dir/requires: CMakeFiles/03_samples.dir/main.cpp.o.requires

.PHONY : CMakeFiles/03_samples.dir/requires

CMakeFiles/03_samples.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/03_samples.dir/cmake_clean.cmake
.PHONY : CMakeFiles/03_samples.dir/clean

CMakeFiles/03_samples.dir/depend:
	cd /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/cmake-build-debug /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/cmake-build-debug /home/jencmart/Dropbox/development/ClionProjects/ep1/03-samples/cmake-build-debug/CMakeFiles/03_samples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/03_samples.dir/depend

