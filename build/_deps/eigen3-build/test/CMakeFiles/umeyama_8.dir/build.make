# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/software/nuisance

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/software/nuisance/build

# Include any dependencies generated for this target.
include _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/flags.make

_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/umeyama.cpp.o: _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/flags.make
_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/umeyama.cpp.o: _deps/eigen3-src/test/umeyama.cpp
_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/umeyama.cpp.o: _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/umeyama.cpp.o"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/umeyama.cpp.o -MF CMakeFiles/umeyama_8.dir/umeyama.cpp.o.d -o CMakeFiles/umeyama_8.dir/umeyama.cpp.o -c /root/software/nuisance/build/_deps/eigen3-src/test/umeyama.cpp

_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/umeyama.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/umeyama_8.dir/umeyama.cpp.i"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/software/nuisance/build/_deps/eigen3-src/test/umeyama.cpp > CMakeFiles/umeyama_8.dir/umeyama.cpp.i

_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/umeyama.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/umeyama_8.dir/umeyama.cpp.s"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/software/nuisance/build/_deps/eigen3-src/test/umeyama.cpp -o CMakeFiles/umeyama_8.dir/umeyama.cpp.s

# Object files for target umeyama_8
umeyama_8_OBJECTS = \
"CMakeFiles/umeyama_8.dir/umeyama.cpp.o"

# External object files for target umeyama_8
umeyama_8_EXTERNAL_OBJECTS =

_deps/eigen3-build/test/umeyama_8: _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/umeyama.cpp.o
_deps/eigen3-build/test/umeyama_8: _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/build.make
_deps/eigen3-build/test/umeyama_8: _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable umeyama_8"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/umeyama_8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/build: _deps/eigen3-build/test/umeyama_8
.PHONY : _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/build

_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/clean:
	cd /root/software/nuisance/build/_deps/eigen3-build/test && $(CMAKE_COMMAND) -P CMakeFiles/umeyama_8.dir/cmake_clean.cmake
.PHONY : _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/clean

_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/depend:
	cd /root/software/nuisance/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/software/nuisance /root/software/nuisance/build/_deps/eigen3-src/test /root/software/nuisance/build /root/software/nuisance/build/_deps/eigen3-build/test /root/software/nuisance/build/_deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/eigen3-build/test/CMakeFiles/umeyama_8.dir/depend

