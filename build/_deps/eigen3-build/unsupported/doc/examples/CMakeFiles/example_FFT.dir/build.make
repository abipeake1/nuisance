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
include _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/flags.make

_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/FFT.cpp.o: _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/flags.make
_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/FFT.cpp.o: _deps/eigen3-src/unsupported/doc/examples/FFT.cpp
_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/FFT.cpp.o: _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/FFT.cpp.o"
	cd /root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/FFT.cpp.o -MF CMakeFiles/example_FFT.dir/FFT.cpp.o.d -o CMakeFiles/example_FFT.dir/FFT.cpp.o -c /root/software/nuisance/build/_deps/eigen3-src/unsupported/doc/examples/FFT.cpp

_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/FFT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_FFT.dir/FFT.cpp.i"
	cd /root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/software/nuisance/build/_deps/eigen3-src/unsupported/doc/examples/FFT.cpp > CMakeFiles/example_FFT.dir/FFT.cpp.i

_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/FFT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_FFT.dir/FFT.cpp.s"
	cd /root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/software/nuisance/build/_deps/eigen3-src/unsupported/doc/examples/FFT.cpp -o CMakeFiles/example_FFT.dir/FFT.cpp.s

# Object files for target example_FFT
example_FFT_OBJECTS = \
"CMakeFiles/example_FFT.dir/FFT.cpp.o"

# External object files for target example_FFT
example_FFT_EXTERNAL_OBJECTS =

_deps/eigen3-build/unsupported/doc/examples/example_FFT: _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/FFT.cpp.o
_deps/eigen3-build/unsupported/doc/examples/example_FFT: _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/build.make
_deps/eigen3-build/unsupported/doc/examples/example_FFT: _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_FFT"
	cd /root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_FFT.dir/link.txt --verbose=$(VERBOSE)
	cd /root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples && ./example_FFT >/root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples/FFT.out

# Rule to build all files generated by this target.
_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/build: _deps/eigen3-build/unsupported/doc/examples/example_FFT
.PHONY : _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/build

_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/clean:
	cd /root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/example_FFT.dir/cmake_clean.cmake
.PHONY : _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/clean

_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/depend:
	cd /root/software/nuisance/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/software/nuisance /root/software/nuisance/build/_deps/eigen3-src/unsupported/doc/examples /root/software/nuisance/build /root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples /root/software/nuisance/build/_deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/eigen3-build/unsupported/doc/examples/CMakeFiles/example_FFT.dir/depend

