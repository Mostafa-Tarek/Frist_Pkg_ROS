cmake_minimum_required(VERSION 3.0.2)
project(my_frist_pkg)
find_package(catkin REQUIRED COMPONENTS roscpp actionlib actionlib_msgs std_msgs  message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
 add_message_files(FILES MSTutorial.msg)

## Generate services in the 'srv' folder
add_service_files(FILES addTwoint.srv
area_of_Rect.srv )

## Generate actions in the 'action' folder
add_action_files(
   FILES Fiboncci.action )

## Generate added messages and services with any dependencies listed here
generate_messages( DEPENDENCIES std_msgs actionlib_msgs )
catkin_package( LIBRARIES my_frist_pkg 
CATKIN_DEPENDS std_msgs actionlib actionlib_msgs roscpp message_runtime)
include_directories( ${catkin_INCLUDE_DIRS} )

#confiuguration for publisher
add_executable(talker_topic src/my_frist_talker.cpp)
add_dependencies(talker_topic ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
## Specify libraries to link a library or executable target against
target_link_libraries(talker_topic ${catkin_LIBRARIES} )

#confiuguration for subscriber
add_executable(listener_topic src/my_frist_listener.cpp)
add_dependencies(listener_topic ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(listener_topic ${catkin_LIBRARIES})

#confiuguration for frist_server
add_executable(server_node src/frist_server.cpp)
add_dependencies(server_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(server_node ${catkin_LIBRARIES} )
#confiuguration for frist_client
add_executable(client_node src/frist_client.cpp)
add_dependencies(client_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(client_node ${catkin_LIBRARIES} )

#confiuguration for second_server
add_executable(server_Rect src/server.cpp)
add_dependencies(server_Rect ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(server_Rect ${catkin_LIBRARIES} )

#confiuguration for second_client
add_executable(client_Rect src/client_area.cpp)
add_dependencies(client_Rect ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(client_Rect ${catkin_LIBRARIES} )


