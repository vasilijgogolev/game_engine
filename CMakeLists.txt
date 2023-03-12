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

#third_party
add_subdirectory(third_party)

#application
add_subdirectory(application)

target_include_directories(${PROJECT_NAME} PUBLIC ${ENGINE_WORKING_DIR} ${THIRD_PARTY_INCLUDE_DIRS})
set(SYSTEM_LIBS)
if (WIN32)
    list(APPEND SYSTEM_LIBS opengl32)
elseif(APPLE)
    list(APPEND SYSTEM_LIBS "-framework OpenGL")
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC ${SYSTEM_LIBS} ${THIRD_PARTY_LIBS})

get_target_property(_ENGINE_SOURCES ${PROJECT_NAME} SOURCES)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/" FILES ${_ENGINE_SOURCES})
unset(_ENGINE_SOURCES)