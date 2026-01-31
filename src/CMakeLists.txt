# Collect all ember source files
file(GLOB_RECURSE EMBER_SOURCES
    "app/*.cpp"
    "core/*.cpp"
    "events/*.cpp"
    "file/*.cpp"
    "input/*.cpp"
    "scripting/*.cpp"
)

file(GLOB_RECURSE EMBER_HEADERS
    "app/*.h"
    "core/*.h"
    "events/*.h"
    "file/*.h"
    "input/*.h"
    "scripting/*.h"
)

# Create the ember static library
add_library(ember STATIC
    ${EMBER_SOURCES}
    ${EMBER_HEADERS}
)

# Set target properties
set_target_properties(ember PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    POSITION_INDEPENDENT_CODE ON
)

# Public include directories (for consumers of this library)
target_include_directories(ember PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Private include directories (only for building this library)
target_include_directories(ember PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/app
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/events
    ${CMAKE_CURRENT_SOURCE_DIR}/file
    ${CMAKE_CURRENT_SOURCE_DIR}/input
    ${CMAKE_CURRENT_SOURCE_DIR}/scripting
)

# Link against third-party dependencies
target_link_libraries(ember
    PUBLIC
        glfw::glfw
        EASTL::EASTL
        sol2::sol2
        ${LUA_PACKAGE}
        foonathan_string_id
        flextGL
)

# Link Remotery if enabled
if(EMBER_ENABLE_REMOTERY)
    target_link_libraries(ember PUBLIC Remotery)
endif()

# Platform-specific configurations
if(APPLE)
    # Link against macOS frameworks
    find_library(COCOA_FRAMEWORK Cocoa REQUIRED)
    find_library(IOKIT_FRAMEWORK IOKit REQUIRED)
    find_library(COREVIDEO_FRAMEWORK CoreVideo REQUIRED)
    find_library(OPENGL_FRAMEWORK OpenGL REQUIRED)

    target_link_libraries(ember PUBLIC
        ${COCOA_FRAMEWORK}
        ${IOKIT_FRAMEWORK}
        ${COREVIDEO_FRAMEWORK}
        ${OPENGL_FRAMEWORK}
    )

    # Add C++14 stdlib flags
    target_compile_options(ember PUBLIC -stdlib=libc++)
    target_link_options(ember PUBLIC -stdlib=libc++)

elseif(WIN32)
    # Link against Windows libraries
    target_link_libraries(ember PUBLIC
        opengl32
        gdi32
    )

elseif(UNIX)
    # Link against Linux libraries
    find_package(OpenGL REQUIRED)
    target_link_libraries(ember PUBLIC
        OpenGL::GL
        ${CMAKE_DL_LIBS}
        pthread
    )
endif()

# Compile definitions
target_compile_definitions(ember PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:NDEBUG RELEASE>
)

# Install rules
install(TARGETS ember
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY
    app core events file input scripting
    DESTINATION include/ember
    FILES_MATCHING PATTERN "*.h"
)
