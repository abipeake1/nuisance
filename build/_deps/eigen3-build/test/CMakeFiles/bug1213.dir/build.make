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
include _deps/eigen3-build/test/CMakeFiles/bug1213.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/eigen3-build/test/CMakeFiles/bug1213.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/eigen3-build/test/CMakeFiles/bug1213.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/eigen3-build/test/CMakeFiles/bug1213.dir/flags.make

_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213.cpp.o: _deps/eigen3-build/test/CMakeFiles/bug1213.dir/flags.make
_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213.cpp.o: _deps/eigen3-src/test/bug1213.cpp
_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213.cpp.o: _deps/eigen3-build/test/CMakeFiles/bug1213.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213.cpp.o"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213.cpp.o -MF CMakeFiles/bug1213.dir/bug1213.cpp.o.d -o CMakeFiles/bug1213.dir/bug1213.cpp.o -c /root/software/nuisance/build/_deps/eigen3-src/test/bug1213.cpp

_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bug1213.dir/bug1213.cpp.i"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/software/nuisance/build/_deps/eigen3-src/test/bug1213.cpp > CMakeFiles/bug1213.dir/bug1213.cpp.i

_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bug1213.dir/bug1213.cpp.s"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/software/nuisance/build/_deps/eigen3-src/test/bug1213.cpp -o CMakeFiles/bug1213.dir/bug1213.cpp.s

_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213_main.cpp.o: _deps/eigen3-build/test/CMakeFiles/bug1213.dir/flags.make
_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213_main.cpp.o: _deps/eigen3-src/test/bug1213_main.cpp
_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213_main.cpp.o: _deps/eigen3-build/test/CMakeFiles/bug1213.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213_main.cpp.o"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213_main.cpp.o -MF CMakeFiles/bug1213.dir/bug1213_main.cpp.o.d -o CMakeFiles/bug1213.dir/bug1213_main.cpp.o -c /root/software/nuisance/build/_deps/eigen3-src/test/bug1213_main.cpp

_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bug1213.dir/bug1213_main.cpp.i"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/software/nuisance/build/_deps/eigen3-src/test/bug1213_main.cpp > CMakeFiles/bug1213.dir/bug1213_main.cpp.i

_deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bug1213.dir/bug1213_main.cpp.s"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/software/nuisance/build/_deps/eigen3-src/test/bug1213_main.cpp -o CMakeFiles/bug1213.dir/bug1213_main.cpp.s

# Object files for target bug1213
bug1213_OBJECTS = \
"CMakeFiles/bug1213.dir/bug1213.cpp.o" \
"CMakeFiles/bug1213.dir/bug1213_main.cpp.o"

# External object files for target bug1213
bug1213_EXTERNAL_OBJECTS =

_deps/eigen3-build/test/bug1213: _deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213.cpp.o
_deps/eigen3-build/test/bug1213: _deps/eigen3-build/test/CMakeFiles/bug1213.dir/bug1213_main.cpp.o
_deps/eigen3-build/test/bug1213: _deps/eigen3-build/test/CMakeFiles/bug1213.dir/build.make
_deps/eigen3-build/test/bug1213: _deps/eigen3-build/test/CMakeFiles/bug1213.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bug1213"
	cd /root/software/nuisance/build/_deps/eigen3-build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bug1213.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/eigen3-build/test/CMakeFiles/bug1213.dir/build: _deps/eigen3-build/test/bug1213
.PHONY : _deps/eigen3-build/test/CMakeFiles/bug1213.dir/build

_deps/eigen3-build/test/CMakeFiles/bug1213.dir/clean:
	cd /root/software/nuisance/build/_deps/eigen3-build/test && $(CMAKE_COMMAND) -P CMakeFiles/bug1213.dir/cmake_clean.cmake
.PHONY : _deps/eigen3-build/test/CMakeFiles/bug1213.dir/clean

_deps/eigen3-build/test/CMakeFiles/bug1213.dir/depend:
	cd /root/software/nuisance/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/software/nuisance /root/software/nuisance/build/_deps/eigen3-src/test /root/software/nuisance/build /root/software/nuisance/build/_deps/eigen3-build/test /root/software/nuisance/build/_deps/eigen3-build/test/CMakeFiles/bug1213.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/eigen3-build/test/CMakeFiles/bug1213.dir/depend

