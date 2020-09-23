cmake_minimum_required(VERSION 2.8.3)
project(client_service)

set(CMAKE_PREFIX_PATH "/home/arshia/catkin_ws/devel"  "/opt/ros/melodic")
set(server_service_DIR)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  message_runtime
  roscpp
  std_msgs
  server_service
)


generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
  message_runtime
  roscpp
  std_msgs

)

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

add_executable(client_service src/main.cpp include/client_service/client.h src/client.cpp )
add_dependencies(client_service client_generate_messages_cpp)
target_link_libraries(client_service ${catkin_LIBRARIES})