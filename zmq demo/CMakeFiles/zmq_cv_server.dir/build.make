# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/peyton/Downloads/zmq demo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/peyton/Downloads/zmq demo"

# Include any dependencies generated for this target.
include CMakeFiles/zmq_cv_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zmq_cv_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zmq_cv_server.dir/flags.make

CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o: CMakeFiles/zmq_cv_server.dir/flags.make
CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o: zmq_cv_server.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/peyton/Downloads/zmq demo/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o -c "/home/peyton/Downloads/zmq demo/zmq_cv_server.cpp"

CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/peyton/Downloads/zmq demo/zmq_cv_server.cpp" > CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.i

CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/peyton/Downloads/zmq demo/zmq_cv_server.cpp" -o CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.s

CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o.requires:
.PHONY : CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o.requires

CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o.provides: CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o.requires
	$(MAKE) -f CMakeFiles/zmq_cv_server.dir/build.make CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o.provides.build
.PHONY : CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o.provides

CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o.provides.build: CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o

# Object files for target zmq_cv_server
zmq_cv_server_OBJECTS = \
"CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o"

# External object files for target zmq_cv_server
zmq_cv_server_EXTERNAL_OBJECTS =

zmq_cv_server: CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o
zmq_cv_server: CMakeFiles/zmq_cv_server.dir/build.make
zmq_cv_server: /usr/local/lib/libzmq.so
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.9
zmq_cv_server: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.9
zmq_cv_server: CMakeFiles/zmq_cv_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable zmq_cv_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zmq_cv_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zmq_cv_server.dir/build: zmq_cv_server
.PHONY : CMakeFiles/zmq_cv_server.dir/build

CMakeFiles/zmq_cv_server.dir/requires: CMakeFiles/zmq_cv_server.dir/zmq_cv_server.cpp.o.requires
.PHONY : CMakeFiles/zmq_cv_server.dir/requires

CMakeFiles/zmq_cv_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zmq_cv_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zmq_cv_server.dir/clean

CMakeFiles/zmq_cv_server.dir/depend:
	cd "/home/peyton/Downloads/zmq demo" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/peyton/Downloads/zmq demo" "/home/peyton/Downloads/zmq demo" "/home/peyton/Downloads/zmq demo" "/home/peyton/Downloads/zmq demo" "/home/peyton/Downloads/zmq demo/CMakeFiles/zmq_cv_server.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/zmq_cv_server.dir/depend

