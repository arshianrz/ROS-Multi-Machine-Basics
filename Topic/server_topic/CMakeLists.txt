cmake_minimum_required(VERSION 2.8.3)
project(server_topic)

set(CMAKE_PREFIX_PATH "/home/arshia/catkin_ws/devel"  "/opt/ros/melodic")

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_message_files(
  FILES
  AverageResponse.msg
  AverageRequest.msg
)

generate_messages(DEPENDENCIES std_msgs server_topic)

catkin_package(

    INCLUDE_DIRS
        include
        LIBRARIES ${server_topic}
        CATKIN_DEPENDS
        roscpp
        CATKIN_DEPENDS
        message_runtime
)

include_directories(
    include ${catkin_INCLUDE_DIRS}
)

add_executable(server_topic include/server_topic/server.h src/server.cpp src/main.cpp)
add_dependencies(server_topic ${catkin_EXPORTED_TARGETS})

target_link_libraries(server_topic ${catkin_LIBRARIES})

install(FILES
   Avg.launch
   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )
