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
CMAKE_SOURCE_DIR = /home/shouzo/桌面/opencv/Yester-place/Introduce/2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shouzo/桌面/opencv/Yester-place/Introduce/2/build

# Include any dependencies generated for this target.
include CMakeFiles/Introduce_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Introduce_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Introduce_2.dir/flags.make

CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o: CMakeFiles/Introduce_2.dir/flags.make
CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o: ../Introduce_2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/shouzo/桌面/opencv/Yester-place/Introduce/2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o -c /home/shouzo/桌面/opencv/Yester-place/Introduce/2/Introduce_2.cpp

CMakeFiles/Introduce_2.dir/Introduce_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Introduce_2.dir/Introduce_2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/shouzo/桌面/opencv/Yester-place/Introduce/2/Introduce_2.cpp > CMakeFiles/Introduce_2.dir/Introduce_2.cpp.i

CMakeFiles/Introduce_2.dir/Introduce_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Introduce_2.dir/Introduce_2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/shouzo/桌面/opencv/Yester-place/Introduce/2/Introduce_2.cpp -o CMakeFiles/Introduce_2.dir/Introduce_2.cpp.s

CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o.requires:
.PHONY : CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o.requires

CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o.provides: CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o.requires
	$(MAKE) -f CMakeFiles/Introduce_2.dir/build.make CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o.provides.build
.PHONY : CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o.provides

CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o.provides.build: CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o

# Object files for target Introduce_2
Introduce_2_OBJECTS = \
"CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o"

# External object files for target Introduce_2
Introduce_2_EXTERNAL_OBJECTS =

Introduce_2: CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o
Introduce_2: CMakeFiles/Introduce_2.dir/build.make
Introduce_2: /usr/local/lib/libopencv_videostab.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_superres.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_stitching.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_shape.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_photo.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_objdetect.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_calib3d.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_features2d.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_ml.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_highgui.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_videoio.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_flann.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_video.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_imgproc.so.3.1.0
Introduce_2: /usr/local/lib/libopencv_core.so.3.1.0
Introduce_2: CMakeFiles/Introduce_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Introduce_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Introduce_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Introduce_2.dir/build: Introduce_2
.PHONY : CMakeFiles/Introduce_2.dir/build

CMakeFiles/Introduce_2.dir/requires: CMakeFiles/Introduce_2.dir/Introduce_2.cpp.o.requires
.PHONY : CMakeFiles/Introduce_2.dir/requires

CMakeFiles/Introduce_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Introduce_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Introduce_2.dir/clean

CMakeFiles/Introduce_2.dir/depend:
	cd /home/shouzo/桌面/opencv/Yester-place/Introduce/2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shouzo/桌面/opencv/Yester-place/Introduce/2 /home/shouzo/桌面/opencv/Yester-place/Introduce/2 /home/shouzo/桌面/opencv/Yester-place/Introduce/2/build /home/shouzo/桌面/opencv/Yester-place/Introduce/2/build /home/shouzo/桌面/opencv/Yester-place/Introduce/2/build/CMakeFiles/Introduce_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Introduce_2.dir/depend

