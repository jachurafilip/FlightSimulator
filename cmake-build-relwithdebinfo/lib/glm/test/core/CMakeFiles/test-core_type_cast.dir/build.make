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
CMAKE_BINARY_DIR = /home/filip/FlightSimulator/cmake-build-relwithdebinfo

# Include any dependencies generated for this target.
include lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/depend.make

# Include the progress variables for this target.
include lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/flags.make

lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.o: lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/flags.make
lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.o: ../lib/glm/test/core/core_type_cast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/filip/FlightSimulator/cmake-build-relwithdebinfo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.o"
	cd /home/filip/FlightSimulator/cmake-build-relwithdebinfo/lib/glm/test/core && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.o -c /home/filip/FlightSimulator/lib/glm/test/core/core_type_cast.cpp

lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.i"
	cd /home/filip/FlightSimulator/cmake-build-relwithdebinfo/lib/glm/test/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/filip/FlightSimulator/lib/glm/test/core/core_type_cast.cpp > CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.i

lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.s"
	cd /home/filip/FlightSimulator/cmake-build-relwithdebinfo/lib/glm/test/core && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/filip/FlightSimulator/lib/glm/test/core/core_type_cast.cpp -o CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.s

# Object files for target test-core_type_cast
test__core_type_cast_OBJECTS = \
"CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.o"

# External object files for target test-core_type_cast
test__core_type_cast_EXTERNAL_OBJECTS =

lib/glm/test/core/test-core_type_cast: lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/core_type_cast.cpp.o
lib/glm/test/core/test-core_type_cast: lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/build.make
lib/glm/test/core/test-core_type_cast: lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/filip/FlightSimulator/cmake-build-relwithdebinfo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-core_type_cast"
	cd /home/filip/FlightSimulator/cmake-build-relwithdebinfo/lib/glm/test/core && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-core_type_cast.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/build: lib/glm/test/core/test-core_type_cast

.PHONY : lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/build

lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/clean:
	cd /home/filip/FlightSimulator/cmake-build-relwithdebinfo/lib/glm/test/core && $(CMAKE_COMMAND) -P CMakeFiles/test-core_type_cast.dir/cmake_clean.cmake
.PHONY : lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/clean

lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/depend:
	cd /home/filip/FlightSimulator/cmake-build-relwithdebinfo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/filip/FlightSimulator /home/filip/FlightSimulator/lib/glm/test/core /home/filip/FlightSimulator/cmake-build-relwithdebinfo /home/filip/FlightSimulator/cmake-build-relwithdebinfo/lib/glm/test/core /home/filip/FlightSimulator/cmake-build-relwithdebinfo/lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glm/test/core/CMakeFiles/test-core_type_cast.dir/depend

