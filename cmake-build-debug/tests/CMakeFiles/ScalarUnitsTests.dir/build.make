# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /snap/clion/67/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/67/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/filip/FlightSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/filip/FlightSimulator/cmake-build-debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/ScalarUnitsTests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/ScalarUnitsTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/ScalarUnitsTests.dir/flags.make

tests/CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.o: tests/CMakeFiles/ScalarUnitsTests.dir/flags.make
tests/CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.o: ../tests/ScalarUnitsTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filip/FlightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.o"
	cd /home/filip/FlightSimulator/cmake-build-debug/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.o -c /home/filip/FlightSimulator/tests/ScalarUnitsTests.cpp

tests/CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.i"
	cd /home/filip/FlightSimulator/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filip/FlightSimulator/tests/ScalarUnitsTests.cpp > CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.i

tests/CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.s"
	cd /home/filip/FlightSimulator/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filip/FlightSimulator/tests/ScalarUnitsTests.cpp -o CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.s

# Object files for target ScalarUnitsTests
ScalarUnitsTests_OBJECTS = \
"CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.o"

# External object files for target ScalarUnitsTests
ScalarUnitsTests_EXTERNAL_OBJECTS =

tests/ScalarUnitsTests: tests/CMakeFiles/ScalarUnitsTests.dir/ScalarUnitsTests.cpp.o
tests/ScalarUnitsTests: tests/CMakeFiles/ScalarUnitsTests.dir/build.make
tests/ScalarUnitsTests: lib/libgtestd.a
tests/ScalarUnitsTests: lib/libgtest_maind.a
tests/ScalarUnitsTests: lib/libgmockd.a
tests/ScalarUnitsTests: lib/libgmock_maind.a
tests/ScalarUnitsTests: src/libPhysicalUnit.a
tests/ScalarUnitsTests: lib/libgmockd.a
tests/ScalarUnitsTests: lib/libgtestd.a
tests/ScalarUnitsTests: tests/CMakeFiles/ScalarUnitsTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filip/FlightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ScalarUnitsTests"
	cd /home/filip/FlightSimulator/cmake-build-debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ScalarUnitsTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/ScalarUnitsTests.dir/build: tests/ScalarUnitsTests

.PHONY : tests/CMakeFiles/ScalarUnitsTests.dir/build

tests/CMakeFiles/ScalarUnitsTests.dir/clean:
	cd /home/filip/FlightSimulator/cmake-build-debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/ScalarUnitsTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ScalarUnitsTests.dir/clean

tests/CMakeFiles/ScalarUnitsTests.dir/depend:
	cd /home/filip/FlightSimulator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filip/FlightSimulator /home/filip/FlightSimulator/tests /home/filip/FlightSimulator/cmake-build-debug /home/filip/FlightSimulator/cmake-build-debug/tests /home/filip/FlightSimulator/cmake-build-debug/tests/CMakeFiles/ScalarUnitsTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/ScalarUnitsTests.dir/depend

