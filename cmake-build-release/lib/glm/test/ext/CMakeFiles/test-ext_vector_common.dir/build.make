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
include lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/depend.make

# Include the progress variables for this target.
include lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/flags.make

lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.o: lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/flags.make
lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.o: ../lib/glm/test/ext/ext_vector_common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filip/FlightSimulator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.o"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/ext && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.o -c /home/filip/FlightSimulator/lib/glm/test/ext/ext_vector_common.cpp

lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.i"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/ext && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filip/FlightSimulator/lib/glm/test/ext/ext_vector_common.cpp > CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.i

lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.s"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/ext && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filip/FlightSimulator/lib/glm/test/ext/ext_vector_common.cpp -o CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.s

# Object files for target test-ext_vector_common
test__ext_vector_common_OBJECTS = \
"CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.o"

# External object files for target test-ext_vector_common
test__ext_vector_common_EXTERNAL_OBJECTS =

lib/glm/test/ext/test-ext_vector_common: lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/ext_vector_common.cpp.o
lib/glm/test/ext/test-ext_vector_common: lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/build.make
lib/glm/test/ext/test-ext_vector_common: lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filip/FlightSimulator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-ext_vector_common"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/ext && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-ext_vector_common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/build: lib/glm/test/ext/test-ext_vector_common

.PHONY : lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/build

lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/clean:
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/ext && $(CMAKE_COMMAND) -P CMakeFiles/test-ext_vector_common.dir/cmake_clean.cmake
.PHONY : lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/clean

lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/depend:
	cd /home/filip/FlightSimulator/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filip/FlightSimulator /home/filip/FlightSimulator/lib/glm/test/ext /home/filip/FlightSimulator/cmake-build-release /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/ext /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glm/test/ext/CMakeFiles/test-ext_vector_common.dir/depend

