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
CMAKE_SOURCE_DIR = /Users/ray/Desktop/NTU/計算機程式/preview/function_preview

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ray/Desktop/NTU/計算機程式/preview/function_preview/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/p25.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p25.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p25.dir/flags.make

CMakeFiles/p25.dir/p25.cpp.o: CMakeFiles/p25.dir/flags.make
CMakeFiles/p25.dir/p25.cpp.o: ../p25.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ray/Desktop/NTU/計算機程式/preview/function_preview/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p25.dir/p25.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p25.dir/p25.cpp.o -c /Users/ray/Desktop/NTU/計算機程式/preview/function_preview/p25.cpp

CMakeFiles/p25.dir/p25.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p25.dir/p25.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ray/Desktop/NTU/計算機程式/preview/function_preview/p25.cpp > CMakeFiles/p25.dir/p25.cpp.i

CMakeFiles/p25.dir/p25.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p25.dir/p25.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ray/Desktop/NTU/計算機程式/preview/function_preview/p25.cpp -o CMakeFiles/p25.dir/p25.cpp.s

# Object files for target p25
p25_OBJECTS = \
"CMakeFiles/p25.dir/p25.cpp.o"

# External object files for target p25
p25_EXTERNAL_OBJECTS =

p25: CMakeFiles/p25.dir/p25.cpp.o
p25: CMakeFiles/p25.dir/build.make
p25: CMakeFiles/p25.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ray/Desktop/NTU/計算機程式/preview/function_preview/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p25"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p25.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p25.dir/build: p25

.PHONY : CMakeFiles/p25.dir/build

CMakeFiles/p25.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p25.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p25.dir/clean

CMakeFiles/p25.dir/depend:
	cd /Users/ray/Desktop/NTU/計算機程式/preview/function_preview/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ray/Desktop/NTU/計算機程式/preview/function_preview /Users/ray/Desktop/NTU/計算機程式/preview/function_preview /Users/ray/Desktop/NTU/計算機程式/preview/function_preview/cmake-build-debug /Users/ray/Desktop/NTU/計算機程式/preview/function_preview/cmake-build-debug /Users/ray/Desktop/NTU/計算機程式/preview/function_preview/cmake-build-debug/CMakeFiles/p25.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p25.dir/depend

