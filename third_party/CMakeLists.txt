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
set(ZLIB_LIBRARY zlib)
set(ZLIB_INCLUDE_DIR zlib-ng)
add_subdirectory(libpng)
message("imported libpng")

set(THIRD_PARTY_INCLUDE_DIRS
        "${CMAKE_CURRENT_LIST_DIR}/zlib-ng"
        "${CMAKE_CURRENT_LIST_DIR}/libpng"
        "${CMAKE_CURRENT_LIST_DIR}/glfw/include"
        PARENT_SCOPE)
set(THIRD_PARTY_LIBS
        zlib
        png_shared
        glfw
        PARENT_SCOPE)
