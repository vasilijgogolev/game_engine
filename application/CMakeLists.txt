message("importing Engine::Application")

set(MODULE_SOURCES)

#common sources
file(GLOB_RECURSE _SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/system/*.*"
)
list(APPEND MODULE_SOURCES ${_SOURCES})

if(TARGET ${ENGINE_TARGET})
    target_sources(${ENGINE_TARGET} PRIVATE ${MODULE_SOURCES})
endif(TARGET ${ENGINE_TARGET})
