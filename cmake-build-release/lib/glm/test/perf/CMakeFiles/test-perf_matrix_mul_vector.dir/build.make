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
include lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/depend.make

# Include the progress variables for this target.
include lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/flags.make

lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.o: lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/flags.make
lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.o: ../lib/glm/test/perf/perf_matrix_mul_vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filip/FlightSimulator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.o"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/perf && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.o -c /home/filip/FlightSimulator/lib/glm/test/perf/perf_matrix_mul_vector.cpp

lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.i"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/perf && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filip/FlightSimulator/lib/glm/test/perf/perf_matrix_mul_vector.cpp > CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.i

lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.s"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/perf && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filip/FlightSimulator/lib/glm/test/perf/perf_matrix_mul_vector.cpp -o CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.s

# Object files for target test-perf_matrix_mul_vector
test__perf_matrix_mul_vector_OBJECTS = \
"CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.o"

# External object files for target test-perf_matrix_mul_vector
test__perf_matrix_mul_vector_EXTERNAL_OBJECTS =

lib/glm/test/perf/test-perf_matrix_mul_vector: lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/perf_matrix_mul_vector.cpp.o
lib/glm/test/perf/test-perf_matrix_mul_vector: lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/build.make
lib/glm/test/perf/test-perf_matrix_mul_vector: lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filip/FlightSimulator/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-perf_matrix_mul_vector"
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/perf && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-perf_matrix_mul_vector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/build: lib/glm/test/perf/test-perf_matrix_mul_vector

.PHONY : lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/build

lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/clean:
	cd /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/perf && $(CMAKE_COMMAND) -P CMakeFiles/test-perf_matrix_mul_vector.dir/cmake_clean.cmake
.PHONY : lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/clean

lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/depend:
	cd /home/filip/FlightSimulator/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filip/FlightSimulator /home/filip/FlightSimulator/lib/glm/test/perf /home/filip/FlightSimulator/cmake-build-release /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/perf /home/filip/FlightSimulator/cmake-build-release/lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glm/test/perf/CMakeFiles/test-perf_matrix_mul_vector.dir/depend

