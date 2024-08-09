cmake_minimum_required(VERSION 2.8.3)
project(arna_base_control)

find_package(catkin REQUIRED COMPONENTS
  controller_interface
  urdf
  realtime_tools
  tf
  nav_msgs
  roslaunch)

set(mecanum_drive_controller_sources
  src/mecanum_drive_controller/mecanum_drive_controller.cpp
  src/mecanum_drive_controller/odometry.cpp
  src/mecanum_drive_controller/speed_limiter.cpp
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES mecanum_drive_controller
  CATKIN_DEPENDS controller_interface realtime_tools
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

add_library(mecanum_drive_controller ${mecanum_drive_controller_headers} ${mecanum_drive_controller_sources})
target_link_libraries(mecanum_drive_controller ${catkin_LIBRARIES})

add_executable(arna_base_teleop_tablet src/arna_base_teleop_tablet/arna_base_teleop_tablet.cpp)
target_link_libraries(arna_base_teleop_tablet ${catkin_LIBRARIES})

add_executable(arna_base_teleop_keyboard src/arna_base_teleop_keyboard/arna_base_teleop_keyboard.py)
target_link_libraries(arna_base_teleop_keyboard ${catkin_LIBRARIES})


install(TARGETS mecanum_drive_controller
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  )

install(FILES mecanum_drive_controller_plugins.xml
    DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY config launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)


# if(CATKIN_ENABLE_TESTING)
#  find_package(roslaunch REQUIRED)
#  roslaunch_add_file_check(launch/control.launch)
#  roslaunch_add_file_check(launch/teleop.launch)
# endif()
