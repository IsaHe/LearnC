# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/isaacherbozo/CLionProjects/LearnC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/isaacherbozo/CLionProjects/LearnC/cmake-build-debug

# Include any dependencies generated for this target.
include /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/compiler_depend.make

# Include the progress variables for this target.
include /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/progress.make

# Include the compile flags for this target's objects.
include /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/flags.make

/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/main.c.o: /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/flags.make
/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/main.c.o: ../LibroCh1/main.c
/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/main.c.o: /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/isaacherbozo/CLionProjects/LearnC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/main.c.o"
	cd /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/main.c.o -MF CMakeFiles/LibroCh1.dir/main.c.o.d -o CMakeFiles/LibroCh1.dir/main.c.o -c /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/main.c

/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LibroCh1.dir/main.c.i"
	cd /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/main.c > CMakeFiles/LibroCh1.dir/main.c.i

/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LibroCh1.dir/main.c.s"
	cd /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/main.c -o CMakeFiles/LibroCh1.dir/main.c.s

# Object files for target LibroCh1
LibroCh1_OBJECTS = \
"CMakeFiles/LibroCh1.dir/main.c.o"

# External object files for target LibroCh1
LibroCh1_EXTERNAL_OBJECTS =

/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/LibroCh1: /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/main.c.o
/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/LibroCh1: /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/build.make
/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/LibroCh1: /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/isaacherbozo/CLionProjects/LearnC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LibroCh1"
	cd /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LibroCh1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/build: /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/LibroCh1
.PHONY : /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/build

/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/clean:
	cd /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output && $(CMAKE_COMMAND) -P CMakeFiles/LibroCh1.dir/cmake_clean.cmake
.PHONY : /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/clean

/Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/depend:
	cd /Users/isaacherbozo/CLionProjects/LearnC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/isaacherbozo/CLionProjects/LearnC /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1 /Users/isaacherbozo/CLionProjects/LearnC/cmake-build-debug /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : /Users/isaacherbozo/CLionProjects/LearnC/LibroCh1/Output/CMakeFiles/LibroCh1.dir/depend

