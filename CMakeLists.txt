cmake_minimum_required(VERSION 3.15)
project(showboat)

set(CMAKE_CXX_STANDARD 14)



set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.14.1\\mingw73_64\\")
set(Qt5_DIR "C:\\Qt\\5.14.1\\mingw73_64\\lib\\cmake\\Qt5")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON) # if you have any .ui files
set(CMAKE_AUTORCC ON) # if you have any .qrc files

include_directories(cmake-build-debug/crapsStarter_autogen/include)
find_package(Qt5 COMPONENTS Widgets)

include_directories(${Qt5Widgets_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

qt5_generate_moc(main.cpp main.moc showData.cpp showData.moc)

add_executable(showboat main.cpp showData.h showData.cpp Final_UI.ui)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)