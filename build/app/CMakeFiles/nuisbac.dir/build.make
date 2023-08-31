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
include app/CMakeFiles/nuisbac.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include app/CMakeFiles/nuisbac.dir/compiler_depend.make

# Include the progress variables for this target.
include app/CMakeFiles/nuisbac.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/nuisbac.dir/flags.make

app/CMakeFiles/nuisbac.dir/nuisbac.cxx.o: app/CMakeFiles/nuisbac.dir/flags.make
app/CMakeFiles/nuisbac.dir/nuisbac.cxx.o: ../app/nuisbac.cxx
app/CMakeFiles/nuisbac.dir/nuisbac.cxx.o: app/CMakeFiles/nuisbac.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/CMakeFiles/nuisbac.dir/nuisbac.cxx.o"
	cd /root/software/nuisance/build/app && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT app/CMakeFiles/nuisbac.dir/nuisbac.cxx.o -MF CMakeFiles/nuisbac.dir/nuisbac.cxx.o.d -o CMakeFiles/nuisbac.dir/nuisbac.cxx.o -c /root/software/nuisance/app/nuisbac.cxx

app/CMakeFiles/nuisbac.dir/nuisbac.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nuisbac.dir/nuisbac.cxx.i"
	cd /root/software/nuisance/build/app && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/software/nuisance/app/nuisbac.cxx > CMakeFiles/nuisbac.dir/nuisbac.cxx.i

app/CMakeFiles/nuisbac.dir/nuisbac.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nuisbac.dir/nuisbac.cxx.s"
	cd /root/software/nuisance/build/app && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/software/nuisance/app/nuisbac.cxx -o CMakeFiles/nuisbac.dir/nuisbac.cxx.s

# Object files for target nuisbac
nuisbac_OBJECTS = \
"CMakeFiles/nuisbac.dir/nuisbac.cxx.o"

# External object files for target nuisbac
nuisbac_EXTERNAL_OBJECTS =

app/nuisbac: app/CMakeFiles/nuisbac.dir/nuisbac.cxx.o
app/nuisbac: app/CMakeFiles/nuisbac.dir/build.make
app/nuisbac: src/Reweight/libReweight.a
app/nuisbac: src/Config/libConfig.so
app/nuisbac: src/FCN/libFCN.so
app/nuisbac: src/FitBase/libFitBase.so
app/nuisbac: src/InputHandler/libInputHandler.so
app/nuisbac: src/Logger/libLogger.so
app/nuisbac: src/MCStudies/libMCStudies.so
app/nuisbac: src/Routines/libRoutines.so
app/nuisbac: src/Smearceptance/libSmearceptance.so
app/nuisbac: src/Splines/libSplines.so
app/nuisbac: src/Statistical/libStatistical.so
app/nuisbac: src/Utils/libUtils.so
app/nuisbac: /usr/lib64/libxml2.so
app/nuisbac: /usr/lib64/libgsl.so
app/nuisbac: /usr/lib64/libgslcblas.so
app/nuisbac: app/CMakeFiles/nuisbac.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/software/nuisance/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nuisbac"
	cd /root/software/nuisance/build/app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nuisbac.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/nuisbac.dir/build: app/nuisbac
.PHONY : app/CMakeFiles/nuisbac.dir/build

app/CMakeFiles/nuisbac.dir/clean:
	cd /root/software/nuisance/build/app && $(CMAKE_COMMAND) -P CMakeFiles/nuisbac.dir/cmake_clean.cmake
.PHONY : app/CMakeFiles/nuisbac.dir/clean

app/CMakeFiles/nuisbac.dir/depend:
	cd /root/software/nuisance/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/software/nuisance /root/software/nuisance/app /root/software/nuisance/build /root/software/nuisance/build/app /root/software/nuisance/build/app/CMakeFiles/nuisbac.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/nuisbac.dir/depend

