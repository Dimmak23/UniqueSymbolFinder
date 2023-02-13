cmake_minimum_required(VERSION 3.8.0)
project(PROJECT_NAME_TESTS VERSION 0.0.1)

# add test files
set(TEST_SRC_DIR "${CMAKE_SOURCE_DIR}/tests")
include_directories(${TEST_SRC_DIR})
# Find all code files and add them accordingly
file(
	GLOB TEST_SOURCES CONFIGURE_DEPENDS 
	"${TEST_SRC_DIR}/*.cpp"
)

# add headers (we only use them as includes)
set(HEADERS_DIR "${CMAKE_SOURCE_DIR}/../tested_headers")
include_directories(${HEADERS_DIR})

# add executable for test code
add_executable(PROJECT_NAME_TESTS ${TEST_SOURCES})

# link with googletest library
target_link_libraries(PROJECT_NAME_TESTS
	PUBLIC
	gtest_main
	PROJECT_NAME
)

add_test(
	NAME PROJECT_NAME_TESTS
	COMMAND PROJECT_NAME_TESTS
)
