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
CMAKE_COMMAND = /snap/clion/70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/70/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/filip/FlightSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filip/FlightSimulator/cmake-build-release

# Include any dependencies generated for this target.
include lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/depend.make

# Include the progress variables for this target.
include lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/flags.make

lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o: lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/flags.make
lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o: ../lib/glm/test/gtc/gtc_reciprocal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filip/FlightSimulator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o -c /home/filip/FlightSimulator/lib/glm/test/gtc/gtc_reciprocal.cpp

lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.i"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filip/FlightSimulator/lib/glm/test/gtc/gtc_reciprocal.cpp > CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.i

lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.s"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtc && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filip/FlightSimulator/lib/glm/test/gtc/gtc_reciprocal.cpp -o CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.s

# Object files for target test-gtc_reciprocal
test__gtc_reciprocal_OBJECTS = \
"CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o"

# External object files for target test-gtc_reciprocal
test__gtc_reciprocal_EXTERNAL_OBJECTS =

lib/glm/test/gtc/test-gtc_reciprocal: lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/gtc_reciprocal.cpp.o
lib/glm/test/gtc/test-gtc_reciprocal: lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/build.make
lib/glm/test/gtc/test-gtc_reciprocal: lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filip/FlightSimulator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtc_reciprocal"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtc_reciprocal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/build: lib/glm/test/gtc/test-gtc_reciprocal

.PHONY : lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/build

lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/clean:
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtc && $(CMAKE_COMMAND) -P CMakeFiles/test-gtc_reciprocal.dir/cmake_clean.cmake
.PHONY : lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/clean

lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/depend:
	cd /home/filip/FlightSimulator/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filip/FlightSimulator /home/filip/FlightSimulator/lib/glm/test/gtc /home/filip/FlightSimulator/cmake-build-release /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtc /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glm/test/gtc/CMakeFiles/test-gtc_reciprocal.dir/depend

