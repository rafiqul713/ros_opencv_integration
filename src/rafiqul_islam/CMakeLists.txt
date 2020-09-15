cmake_minimum_required(VERSION 3.18)
project(rafiqul_islam)
find_package(catkin REQUIRED COMPONENTS
  std_msgs
  actionlib_msgs
  roscpp
  cv_bridge
  image_transport
  message_generation)

find_package(OpenCV)

catkin_package(
  LIBRARIES rafiqul_islam
  CATKIN_DEPENDS roscpp  std_msgs message_runtime)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS})

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(rafiqul_islam ros_opencv.cpp)
target_link_libraries(rafiqul_islam ${catkin_LIBRARIES})
target_link_libraries(rafiqul_islam ${OpenCV_LIBRARIES})