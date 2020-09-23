cmake_minimum_required(VERSION 2.8.3)
project(server_service)

set(CMAKE_PREFIX_PATH "/home/arshia/catkin_ws/devel"  "/opt/ros/melodic")

find_package(catkin REQUIRED COMPONENTS 
message_generation 
message_runtime
roscpp
std_msgs

)

add_service_files(
  DIRECTORY srv
  FILES
  feedback.srv
)

generate_messages(DEPENDENCIES std_msgs)



catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)



add_executable(server_service src/main.cpp include/server_service/server.h src/server.cpp )
target_link_libraries(server_service ${catkin_LIBRARIES})
