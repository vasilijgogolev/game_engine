cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(engine)

#for better filtering in project
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

add_library(${PROJECT_NAME} STATIC)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

set(ENGINE_WORKING_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(ENGINE_TARGET ${PROJECT_NAME})

#glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "glfw: do not build examples" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "glfw: do not build tests" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "glfw: do not build docs" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "glfw: do not install glfw" FORCE)
add_subdirectory(glfw)

#application
add_subdirectory(application)

target_include_directories(${PROJECT_NAME} PUBLIC ${ENGINE_WORKING_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC glfw opengl32)

get_target_property(_ENGINE_SOURCES ${PROJECT_NAME} SOURCES)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/" FILES ${_ENGINE_SOURCES})
unset(_ENGINE_SOURCES)