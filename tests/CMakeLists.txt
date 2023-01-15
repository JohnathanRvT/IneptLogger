#CMakeLists.txt for IneptLogger test
cmake_minimum_required(VERSION 3.10)

#Set project name
project(IneptLoggerTest)

# Add IneptLogger as a dependency
include_directories("../inc")

#Add test source files
file(GLOB_RECURSE TESTS_SOURCES "*.cpp")

#Download and import GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Now simply link against gtest or gtest_main as needed. Eg
add_executable(IneptLoggerTest ${TESTS_SOURCES})
add_test(NAME IneptLoggerTester COMMAND IneptLogger)

target_link_libraries(IneptLoggerTest "../Debug/IneptLogger" gtest_main)