# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build

# Include any dependencies generated for this target.
include CMakeFiles/segway_zmq_sample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/segway_zmq_sample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/segway_zmq_sample.dir/flags.make

image.pb.cc: ../protocol/raw/image.proto
image.pb.cc: /usr/local/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running C++ protocol buffer compiler on ./protocol/raw/image.proto"
	/usr/local/bin/protoc --cpp_out=/home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build -I /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/protocol/raw /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/protocol/raw/image.proto

image.pb.h: image.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate image.pb.h

CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o: CMakeFiles/segway_zmq_sample.dir/flags.make
CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o -c /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/main.cpp

CMakeFiles/segway_zmq_sample.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segway_zmq_sample.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/main.cpp > CMakeFiles/segway_zmq_sample.dir/src/main.cpp.i

CMakeFiles/segway_zmq_sample.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segway_zmq_sample.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/main.cpp -o CMakeFiles/segway_zmq_sample.dir/src/main.cpp.s

CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o.requires

CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o.provides: CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/segway_zmq_sample.dir/build.make CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o.provides

CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o.provides.build: CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o


CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o: CMakeFiles/segway_zmq_sample.dir/flags.make
CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o: ../src/Receiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o -c /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/Receiver.cpp

CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/Receiver.cpp > CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.i

CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/Receiver.cpp -o CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.s

CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o.requires:

.PHONY : CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o.requires

CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o.provides: CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o.requires
	$(MAKE) -f CMakeFiles/segway_zmq_sample.dir/build.make CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o.provides.build
.PHONY : CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o.provides

CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o.provides.build: CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o


CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o: CMakeFiles/segway_zmq_sample.dir/flags.make
CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o: ../src/Publisher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o -c /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/Publisher.cpp

CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/Publisher.cpp > CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.i

CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/src/Publisher.cpp -o CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.s

CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o.requires:

.PHONY : CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o.requires

CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o.provides: CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o.requires
	$(MAKE) -f CMakeFiles/segway_zmq_sample.dir/build.make CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o.provides.build
.PHONY : CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o.provides

CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o.provides.build: CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o


CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o: CMakeFiles/segway_zmq_sample.dir/flags.make
CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o: image.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o -c /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/image.pb.cc

CMakeFiles/segway_zmq_sample.dir/image.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segway_zmq_sample.dir/image.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/image.pb.cc > CMakeFiles/segway_zmq_sample.dir/image.pb.cc.i

CMakeFiles/segway_zmq_sample.dir/image.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segway_zmq_sample.dir/image.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/image.pb.cc -o CMakeFiles/segway_zmq_sample.dir/image.pb.cc.s

CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o.requires:

.PHONY : CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o.requires

CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o.provides: CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o.requires
	$(MAKE) -f CMakeFiles/segway_zmq_sample.dir/build.make CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o.provides.build
.PHONY : CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o.provides

CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o.provides.build: CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o


# Object files for target segway_zmq_sample
segway_zmq_sample_OBJECTS = \
"CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o" \
"CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o" \
"CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o" \
"CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o"

# External object files for target segway_zmq_sample
segway_zmq_sample_EXTERNAL_OBJECTS =

segway_zmq_sample: CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o
segway_zmq_sample: CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o
segway_zmq_sample: CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o
segway_zmq_sample: CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o
segway_zmq_sample: CMakeFiles/segway_zmq_sample.dir/build.make
segway_zmq_sample: /usr/local/lib/libprotobuf.so
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
segway_zmq_sample: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
segway_zmq_sample: CMakeFiles/segway_zmq_sample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable segway_zmq_sample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/segway_zmq_sample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/segway_zmq_sample.dir/build: segway_zmq_sample

.PHONY : CMakeFiles/segway_zmq_sample.dir/build

CMakeFiles/segway_zmq_sample.dir/requires: CMakeFiles/segway_zmq_sample.dir/src/main.cpp.o.requires
CMakeFiles/segway_zmq_sample.dir/requires: CMakeFiles/segway_zmq_sample.dir/src/Receiver.cpp.o.requires
CMakeFiles/segway_zmq_sample.dir/requires: CMakeFiles/segway_zmq_sample.dir/src/Publisher.cpp.o.requires
CMakeFiles/segway_zmq_sample.dir/requires: CMakeFiles/segway_zmq_sample.dir/image.pb.cc.o.requires

.PHONY : CMakeFiles/segway_zmq_sample.dir/requires

CMakeFiles/segway_zmq_sample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/segway_zmq_sample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/segway_zmq_sample.dir/clean

CMakeFiles/segway_zmq_sample.dir/depend: image.pb.cc
CMakeFiles/segway_zmq_sample.dir/depend: image.pb.h
	cd /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build /home/yuehu/Desktop/comm_performance_compare/zmq+protobuf/build/CMakeFiles/segway_zmq_sample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/segway_zmq_sample.dir/depend
