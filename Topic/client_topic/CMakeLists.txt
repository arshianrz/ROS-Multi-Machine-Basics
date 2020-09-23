cmake_minimum_required(VERSION 2.8.3)
project(client_topic)

set(CMAKE_PREFIX_PATH "/home/arshia/catkin_ws/devel"  "/opt/ros/melodic")

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
  server_topic
)

generate_messages(DEPENDENCIES std_msgs client_topic)

catkin_package(
    INCLUDE_DIRS
        include
        LIBRARIES ${client_topic}
        CATKIN_DEPENDS
        roscpp
        CATKIN_DEPENDS
        message_runtime
)

include_directories(
    include ${catkin_INCLUDE_DIRS}
)

add_executable(client_topic include/client_topic/client.h src/client.cpp src/main.cpp)
add_dependencies(client_topic ${catkin_EXPORTED_TARGETS})

target_link_libraries(client_topic ${catkin_LIBRARIES})
