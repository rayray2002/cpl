# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ray/Desktop/NTU/計算機程式/hw02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ray/Desktop/NTU/計算機程式/hw02/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/temp2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/temp2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/temp2.dir/flags.make

CMakeFiles/temp2.dir/jimmy_hanoi.c.o: CMakeFiles/temp2.dir/flags.make
CMakeFiles/temp2.dir/jimmy_hanoi.c.o: ../jimmy_hanoi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ray/Desktop/NTU/計算機程式/hw02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/temp2.dir/jimmy_hanoi.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/temp2.dir/jimmy_hanoi.c.o   -c /Users/ray/Desktop/NTU/計算機程式/hw02/jimmy_hanoi.c

CMakeFiles/temp2.dir/jimmy_hanoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/temp2.dir/jimmy_hanoi.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ray/Desktop/NTU/計算機程式/hw02/jimmy_hanoi.c > CMakeFiles/temp2.dir/jimmy_hanoi.c.i

CMakeFiles/temp2.dir/jimmy_hanoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/temp2.dir/jimmy_hanoi.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ray/Desktop/NTU/計算機程式/hw02/jimmy_hanoi.c -o CMakeFiles/temp2.dir/jimmy_hanoi.c.s

# Object files for target temp2
temp2_OBJECTS = \
"CMakeFiles/temp2.dir/jimmy_hanoi.c.o"

# External object files for target temp2
temp2_EXTERNAL_OBJECTS =

temp2: CMakeFiles/temp2.dir/jimmy_hanoi.c.o
temp2: CMakeFiles/temp2.dir/build.make
temp2: CMakeFiles/temp2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ray/Desktop/NTU/計算機程式/hw02/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable temp2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/temp2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/temp2.dir/build: temp2

.PHONY : CMakeFiles/temp2.dir/build

CMakeFiles/temp2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/temp2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/temp2.dir/clean

CMakeFiles/temp2.dir/depend:
	cd /Users/ray/Desktop/NTU/計算機程式/hw02/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ray/Desktop/NTU/計算機程式/hw02 /Users/ray/Desktop/NTU/計算機程式/hw02 /Users/ray/Desktop/NTU/計算機程式/hw02/cmake-build-debug /Users/ray/Desktop/NTU/計算機程式/hw02/cmake-build-debug /Users/ray/Desktop/NTU/計算機程式/hw02/cmake-build-debug/CMakeFiles/temp2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/temp2.dir/depend

