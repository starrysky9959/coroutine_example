cmake_minimum_required(VERSION 3.0.0)
project(coroutine_example VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CXX_STANDARD 17)
add_executable(coroutine_example main.cpp)

set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/third_party/boost_1_82_0")
find_package(Boost 1.82.0 REQUIRED context)
# find_package(Boost REQUIRED context)

target_include_directories(coroutine_example PUBLIC ${Boost_INCLUDE_DIRS})
target_link_directories(coroutine_example PUBLIC ${Boost_LIBRARY_DIRS})
target_link_libraries(coroutine_example PUBLIC ${Boost_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
