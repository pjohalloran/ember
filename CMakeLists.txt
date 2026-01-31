cmake_minimum_required(VERSION 3.15)

# Set project name and version
project(ember-engine
    VERSION 0.1.0
    LANGUAGES C CXX
)

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for IDE integration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Options
option(EMBER_USE_LUAJIT "Use LuaJIT instead of standard Lua" OFF)
option(EMBER_ENABLE_REMOTERY "Enable Remotery profiling" ON)
option(EMBER_ENABLE_TESTS "Build test executable" ON)

# Platform definitions
if(APPLE)
    add_compile_definitions(TARGET_OS_MAC)
elseif(WIN32)
    add_compile_definitions(_WINDOWS NOMINMAX)
endif()

# Conan setup (if using Conan 2.0)
# This will be populated by: conan install . --output-folder=build --build=missing
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")

# Find Conan-provided dependencies
find_package(glfw3 REQUIRED)
find_package(EASTL REQUIRED)

if(EMBER_USE_LUAJIT)
    find_package(luajit REQUIRED)
    set(LUA_PACKAGE luajit::luajit)
else()
    find_package(lua REQUIRED)
    set(LUA_PACKAGE lua::lua)
endif()

# Header-only libraries (can use FetchContent as fallback if not in Conan)
# These are available in Conan Center
find_package(sol2 REQUIRED)
find_package(loguru REQUIRED)

# For string_id, we might need FetchContent since it's less common in Conan
include(FetchContent)

FetchContent_Declare(
    string_id
    GIT_REPOSITORY https://github.com/foonathan/string_id.git
    GIT_TAG        v1.1.0
)

FetchContent_MakeAvailable(string_id)

# flextGL - built as part of the project
add_library(flextGL STATIC
    src/flextGL/flextGL.c
    src/flextGL/flextGL.h
)
target_include_directories(flextGL PUBLIC src/flextGL)

# Remotery - built as part of the project (if enabled)
if(EMBER_ENABLE_REMOTERY)
    add_library(Remotery STATIC
        src/thirdparty/Remotery/lib/Remotery.c
        src/thirdparty/Remotery/lib/Remotery.h
    )

    target_include_directories(Remotery PUBLIC
        src/thirdparty/Remotery/lib
    )

    # Remotery options (can be made configurable via CMake options)
    target_compile_definitions(Remotery PUBLIC
        RMT_USE_OPENGL=1
        RMT_USE_D3D11=0
        RMT_USE_METAL=0
    )

    # Metal support on macOS
    if(APPLE)
        target_sources(Remotery PRIVATE src/thirdparty/Remotery/lib/Remotery.mm)
        find_library(METAL_FRAMEWORK Metal)
        target_link_libraries(Remotery PUBLIC ${METAL_FRAMEWORK})
    endif()
endif()

# Main ember library
add_subdirectory(src)

# Test executable
if(EMBER_ENABLE_TESTS)
    add_subdirectory(src/ember-test)
endif()

# Print configuration summary
message(STATUS "========================================")
message(STATUS "Ember Engine Configuration Summary")
message(STATUS "========================================")
message(STATUS "Build type:        ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard:      C++${CMAKE_CXX_STANDARD}")
message(STATUS "Use LuaJIT:        ${EMBER_USE_LUAJIT}")
message(STATUS "Enable Remotery:   ${EMBER_ENABLE_REMOTERY}")
message(STATUS "Build Tests:       ${EMBER_ENABLE_TESTS}")
message(STATUS "Install prefix:    ${CMAKE_INSTALL_PREFIX}")
message(STATUS "========================================")
