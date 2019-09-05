cmake_minimum_required(VERSION 2.8.0)
project(plugin_panel)

find_package(catkin REQUIRED COMPONENTS roscpp sensor_msgs)

include_directories(include ${catkin_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

catkin_package()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5 REQUIRED Core Widgets)
## make target_link_libraries(${QT_LIBRARIES}) pull in all required dependencies
set(QT_LIBRARIES Qt5::Widgets)

add_definitions(-DQT_NO_KEYWORDS)

qt5_wrap_cpp(QT_MOC include/plugin_panel.h)


set(SOURCES src/plugin_panel.cpp ${QT_MOC})
add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${catkin_LIBRARIES})  

