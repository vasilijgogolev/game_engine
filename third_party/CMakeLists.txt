SET(SKIP_INSTALL_EXPORT TRUE)

#glfw
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "glfw: do not build examples" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "glfw: do not build tests" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "glfw: do not build docs" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "glfw: do not install glfw" FORCE)
add_subdirectory(glfw)
message("imported glfw")

#zlib
set(ZLIB_COMPAT ON)
set(ZLIB_ENABLE_TESTS OFF)
add_subdirectory(zlib-ng)
message("imported zlib-ng")

#libpng
option(PNG_BUILD_ZLIB "build zlib, do not use find_package" ON)
option(PNG_SHARED "Build libpng as a shared lib" OFF)
option(PNG_EXECUTABLES "Build libpng executables" OFF)
option(PNG_TESTS "Build libpng tests" OFF)
option(PNG_DEBUG "Enable debug output" OFF)
add_subdirectory(libpng)
message("imported libpng")

set(THIRD_PARTY_INCLUDE_DIRS
        "${CMAKE_CURRENT_LIST_DIR}/zlib-ng"
        "${CMAKE_CURRENT_LIST_DIR}/libpng"
        "${CMAKE_CURRENT_LIST_DIR}/glfw/include"
        PARENT_SCOPE)
set(THIRD_PARTY_LIBS
        zlib
        png_static
        glfw
        PARENT_SCOPE)
