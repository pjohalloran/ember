# Collect test source files
file(GLOB EMBER_TEST_SOURCES
    "*.cpp"
)

file(GLOB EMBER_TEST_HEADERS
    "*.h"
)

# Create the test executable
add_executable(ember-test
    ${EMBER_TEST_SOURCES}
    ${EMBER_TEST_HEADERS}
)

# Set target properties
set_target_properties(ember-test PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# Link against the ember library
target_link_libraries(ember-test PRIVATE
    ember
    flextGL
)

# Link Remotery if enabled
if(EMBER_ENABLE_REMOTERY)
    target_link_libraries(ember-test PRIVATE Remotery)
endif()

# Include directories
target_include_directories(ember-test PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

# Compile definitions
target_compile_definitions(ember-test PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:NDEBUG RELEASE>
)

# Platform-specific link options
if(APPLE)
    target_compile_options(ember-test PRIVATE -stdlib=libc++)
    target_link_options(ember-test PRIVATE -stdlib=libc++)
endif()

# Install rule
install(TARGETS ember-test
    RUNTIME DESTINATION bin
)
