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
include lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/depend.make

# Include the progress variables for this target.
include lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/flags.make

lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.o: lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/flags.make
lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.o: ../lib/glm/test/gtx/gtx_polar_coordinates.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filip/FlightSimulator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.o"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtx && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.o -c /home/filip/FlightSimulator/lib/glm/test/gtx/gtx_polar_coordinates.cpp

lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.i"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtx && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filip/FlightSimulator/lib/glm/test/gtx/gtx_polar_coordinates.cpp > CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.i

lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.s"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtx && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filip/FlightSimulator/lib/glm/test/gtx/gtx_polar_coordinates.cpp -o CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.s

# Object files for target test-gtx_polar_coordinates
test__gtx_polar_coordinates_OBJECTS = \
"CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.o"

# External object files for target test-gtx_polar_coordinates
test__gtx_polar_coordinates_EXTERNAL_OBJECTS =

lib/glm/test/gtx/test-gtx_polar_coordinates: lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/gtx_polar_coordinates.cpp.o
lib/glm/test/gtx/test-gtx_polar_coordinates: lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/build.make
lib/glm/test/gtx/test-gtx_polar_coordinates: lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filip/FlightSimulator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-gtx_polar_coordinates"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtx && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-gtx_polar_coordinates.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/build: lib/glm/test/gtx/test-gtx_polar_coordinates

.PHONY : lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/build

lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/clean:
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtx && $(CMAKE_COMMAND) -P CMakeFiles/test-gtx_polar_coordinates.dir/cmake_clean.cmake
.PHONY : lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/clean

lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/depend:
	cd /home/filip/FlightSimulator/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filip/FlightSimulator /home/filip/FlightSimulator/lib/glm/test/gtx /home/filip/FlightSimulator/cmake-build-release /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtx /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glm/test/gtx/CMakeFiles/test-gtx_polar_coordinates.dir/depend

