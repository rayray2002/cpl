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
CMAKE_SOURCE_DIR = /Users/ray/Desktop/NTU/計算機程式/0922/page14

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ray/Desktop/NTU/計算機程式/0922/page14/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/page14.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/page14.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/page14.dir/flags.make

CMakeFiles/page14.dir/main.cpp.o: CMakeFiles/page14.dir/flags.make
CMakeFiles/page14.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ray/Desktop/NTU/計算機程式/0922/page14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/page14.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/page14.dir/main.cpp.o -c /Users/ray/Desktop/NTU/計算機程式/0922/page14/main.cpp

CMakeFiles/page14.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/page14.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ray/Desktop/NTU/計算機程式/0922/page14/main.cpp > CMakeFiles/page14.dir/main.cpp.i

CMakeFiles/page14.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/page14.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ray/Desktop/NTU/計算機程式/0922/page14/main.cpp -o CMakeFiles/page14.dir/main.cpp.s

# Object files for target page14
page14_OBJECTS = \
"CMakeFiles/page14.dir/main.cpp.o"

# External object files for target page14
page14_EXTERNAL_OBJECTS =

page14: CMakeFiles/page14.dir/main.cpp.o
page14: CMakeFiles/page14.dir/build.make
page14: CMakeFiles/page14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ray/Desktop/NTU/計算機程式/0922/page14/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable page14"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/page14.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/page14.dir/build: page14

.PHONY : CMakeFiles/page14.dir/build

CMakeFiles/page14.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/page14.dir/cmake_clean.cmake
.PHONY : CMakeFiles/page14.dir/clean

CMakeFiles/page14.dir/depend:
	cd /Users/ray/Desktop/NTU/計算機程式/0922/page14/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ray/Desktop/NTU/計算機程式/0922/page14 /Users/ray/Desktop/NTU/計算機程式/0922/page14 /Users/ray/Desktop/NTU/計算機程式/0922/page14/cmake-build-debug /Users/ray/Desktop/NTU/計算機程式/0922/page14/cmake-build-debug /Users/ray/Desktop/NTU/計算機程式/0922/page14/cmake-build-debug/CMakeFiles/page14.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/page14.dir/depend

