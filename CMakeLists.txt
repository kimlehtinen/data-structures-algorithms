cmake_minimum_required(VERSION 3.10)
project(MyApp)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Fetch GoogleTest and make it available
FetchContent_MakeAvailable(googletest)

# Automatically find all source files in src/ and tests/
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE TEST_FILES "tests/*.cpp")

# Add the executable for the main application
add_executable(myapp ${SRC_FILES})

# Optionally install the application
install(TARGETS myapp DESTINATION bin)

# Specify the include directories for your project (for both `myapp` and `run_tests`)
# This will allow the tests to include headers from the src/ folder.
target_include_directories(myapp PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Enable testing
enable_testing()

# Exclude main.cpp from SRC_FILES for the test executable
list(FILTER SRC_FILES EXCLUDE REGEX ".*main.cpp")

# Add the test executable
add_executable(run_tests ${TEST_FILES} ${SRC_FILES})

# Now that the test executable exists, specify the include directories
target_include_directories(run_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link GoogleTest to the test executable
target_link_libraries(run_tests gtest gtest_main)

# Register the test with CTest
add_test(NAME run_tests COMMAND run_tests)
