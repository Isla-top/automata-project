# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/oslab/automate/automata-project/framework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oslab/automate/automata-project/framework/build

# Include any dependencies generated for this target.
include CMakeFiles/turing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/turing.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/turing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/turing.dir/flags.make

CMakeFiles/turing.dir/turing-project/main.cpp.o: CMakeFiles/turing.dir/flags.make
CMakeFiles/turing.dir/turing-project/main.cpp.o: ../turing-project/main.cpp
CMakeFiles/turing.dir/turing-project/main.cpp.o: CMakeFiles/turing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oslab/automate/automata-project/framework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/turing.dir/turing-project/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/turing.dir/turing-project/main.cpp.o -MF CMakeFiles/turing.dir/turing-project/main.cpp.o.d -o CMakeFiles/turing.dir/turing-project/main.cpp.o -c /home/oslab/automate/automata-project/framework/turing-project/main.cpp

CMakeFiles/turing.dir/turing-project/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/turing.dir/turing-project/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oslab/automate/automata-project/framework/turing-project/main.cpp > CMakeFiles/turing.dir/turing-project/main.cpp.i

CMakeFiles/turing.dir/turing-project/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/turing.dir/turing-project/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oslab/automate/automata-project/framework/turing-project/main.cpp -o CMakeFiles/turing.dir/turing-project/main.cpp.s

CMakeFiles/turing.dir/turing-project/parser.cpp.o: CMakeFiles/turing.dir/flags.make
CMakeFiles/turing.dir/turing-project/parser.cpp.o: ../turing-project/parser.cpp
CMakeFiles/turing.dir/turing-project/parser.cpp.o: CMakeFiles/turing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oslab/automate/automata-project/framework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/turing.dir/turing-project/parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/turing.dir/turing-project/parser.cpp.o -MF CMakeFiles/turing.dir/turing-project/parser.cpp.o.d -o CMakeFiles/turing.dir/turing-project/parser.cpp.o -c /home/oslab/automate/automata-project/framework/turing-project/parser.cpp

CMakeFiles/turing.dir/turing-project/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/turing.dir/turing-project/parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oslab/automate/automata-project/framework/turing-project/parser.cpp > CMakeFiles/turing.dir/turing-project/parser.cpp.i

CMakeFiles/turing.dir/turing-project/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/turing.dir/turing-project/parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oslab/automate/automata-project/framework/turing-project/parser.cpp -o CMakeFiles/turing.dir/turing-project/parser.cpp.s

CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o: CMakeFiles/turing.dir/flags.make
CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o: ../turing-project/turing_machine.cpp
CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o: CMakeFiles/turing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oslab/automate/automata-project/framework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o -MF CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o.d -o CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o -c /home/oslab/automate/automata-project/framework/turing-project/turing_machine.cpp

CMakeFiles/turing.dir/turing-project/turing_machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/turing.dir/turing-project/turing_machine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oslab/automate/automata-project/framework/turing-project/turing_machine.cpp > CMakeFiles/turing.dir/turing-project/turing_machine.cpp.i

CMakeFiles/turing.dir/turing-project/turing_machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/turing.dir/turing-project/turing_machine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oslab/automate/automata-project/framework/turing-project/turing_machine.cpp -o CMakeFiles/turing.dir/turing-project/turing_machine.cpp.s

# Object files for target turing
turing_OBJECTS = \
"CMakeFiles/turing.dir/turing-project/main.cpp.o" \
"CMakeFiles/turing.dir/turing-project/parser.cpp.o" \
"CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o"

# External object files for target turing
turing_EXTERNAL_OBJECTS =

../bin/turing: CMakeFiles/turing.dir/turing-project/main.cpp.o
../bin/turing: CMakeFiles/turing.dir/turing-project/parser.cpp.o
../bin/turing: CMakeFiles/turing.dir/turing-project/turing_machine.cpp.o
../bin/turing: CMakeFiles/turing.dir/build.make
../bin/turing: CMakeFiles/turing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oslab/automate/automata-project/framework/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/turing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/turing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/turing.dir/build: ../bin/turing
.PHONY : CMakeFiles/turing.dir/build

CMakeFiles/turing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/turing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/turing.dir/clean

CMakeFiles/turing.dir/depend:
	cd /home/oslab/automate/automata-project/framework/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oslab/automate/automata-project/framework /home/oslab/automate/automata-project/framework /home/oslab/automate/automata-project/framework/build /home/oslab/automate/automata-project/framework/build /home/oslab/automate/automata-project/framework/build/CMakeFiles/turing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/turing.dir/depend

