# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/leonardo/Desktop/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/leonardo/Desktop/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leonardo/CLionProjects/beholder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonardo/CLionProjects/beholder/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/beholder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/beholder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/beholder.dir/flags.make

CMakeFiles/beholder.dir/main.cpp.o: CMakeFiles/beholder.dir/flags.make
CMakeFiles/beholder.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/CLionProjects/beholder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/beholder.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/beholder.dir/main.cpp.o -c /home/leonardo/CLionProjects/beholder/main.cpp

CMakeFiles/beholder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/beholder.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leonardo/CLionProjects/beholder/main.cpp > CMakeFiles/beholder.dir/main.cpp.i

CMakeFiles/beholder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/beholder.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leonardo/CLionProjects/beholder/main.cpp -o CMakeFiles/beholder.dir/main.cpp.s

CMakeFiles/beholder.dir/classes/roi/roi.cpp.o: CMakeFiles/beholder.dir/flags.make
CMakeFiles/beholder.dir/classes/roi/roi.cpp.o: ../classes/roi/roi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/CLionProjects/beholder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/beholder.dir/classes/roi/roi.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/beholder.dir/classes/roi/roi.cpp.o -c /home/leonardo/CLionProjects/beholder/classes/roi/roi.cpp

CMakeFiles/beholder.dir/classes/roi/roi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/beholder.dir/classes/roi/roi.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leonardo/CLionProjects/beholder/classes/roi/roi.cpp > CMakeFiles/beholder.dir/classes/roi/roi.cpp.i

CMakeFiles/beholder.dir/classes/roi/roi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/beholder.dir/classes/roi/roi.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leonardo/CLionProjects/beholder/classes/roi/roi.cpp -o CMakeFiles/beholder.dir/classes/roi/roi.cpp.s

CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.o: CMakeFiles/beholder.dir/flags.make
CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.o: ../classes/image_loader/image_loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/CLionProjects/beholder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.o -c /home/leonardo/CLionProjects/beholder/classes/image_loader/image_loader.cpp

CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leonardo/CLionProjects/beholder/classes/image_loader/image_loader.cpp > CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.i

CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leonardo/CLionProjects/beholder/classes/image_loader/image_loader.cpp -o CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.s

CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.o: CMakeFiles/beholder.dir/flags.make
CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.o: beholder_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/CLionProjects/beholder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.o -c /home/leonardo/CLionProjects/beholder/cmake-build-debug/beholder_autogen/mocs_compilation.cpp

CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leonardo/CLionProjects/beholder/cmake-build-debug/beholder_autogen/mocs_compilation.cpp > CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.i

CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leonardo/CLionProjects/beholder/cmake-build-debug/beholder_autogen/mocs_compilation.cpp -o CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.s

# Object files for target beholder
beholder_OBJECTS = \
"CMakeFiles/beholder.dir/main.cpp.o" \
"CMakeFiles/beholder.dir/classes/roi/roi.cpp.o" \
"CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.o" \
"CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.o"

# External object files for target beholder
beholder_EXTERNAL_OBJECTS =

beholder: CMakeFiles/beholder.dir/main.cpp.o
beholder: CMakeFiles/beholder.dir/classes/roi/roi.cpp.o
beholder: CMakeFiles/beholder.dir/classes/image_loader/image_loader.cpp.o
beholder: CMakeFiles/beholder.dir/beholder_autogen/mocs_compilation.cpp.o
beholder: CMakeFiles/beholder.dir/build.make
beholder: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.9.5
beholder: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.9.5
beholder: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.9.5
beholder: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.9.5
beholder: CMakeFiles/beholder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonardo/CLionProjects/beholder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable beholder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/beholder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/beholder.dir/build: beholder

.PHONY : CMakeFiles/beholder.dir/build

CMakeFiles/beholder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/beholder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/beholder.dir/clean

CMakeFiles/beholder.dir/depend:
	cd /home/leonardo/CLionProjects/beholder/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonardo/CLionProjects/beholder /home/leonardo/CLionProjects/beholder /home/leonardo/CLionProjects/beholder/cmake-build-debug /home/leonardo/CLionProjects/beholder/cmake-build-debug /home/leonardo/CLionProjects/beholder/cmake-build-debug/CMakeFiles/beholder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/beholder.dir/depend

