cmake_minimum_required(VERSION 3.10)
project(build_wheel_test)

find_package(Threads)
find_package(pinocchio REQUIRED)
find_package(eigenpy REQUIRED)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Maybe this should not be done globally but only for placo's targets
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

if (NOT PYTHON_SITELIB)
set(PYTHON_SITELIB "lib")
endif()

if ("${CMAKE_LIBRARY_OUTPUT_DIRECTORY}" STREQUAL "")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
endif()

find_package (Eigen3 3 REQUIRED NO_MODULE)
find_package(Python3 REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)
find_package(Python REQUIRED COMPONENTS Interpreter)

add_library(build_wheel_test MODULE 
    src/module.cpp
)
set(CMAKE_SHARED_MODULE_PREFIX "")
set_target_properties(build_wheel_test PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PYTHON_SITELIB})
target_compile_definitions(build_wheel_test PUBLIC -DBOOST_DISABLE_PRAGMA_MESSAGE)

target_link_libraries(build_wheel_test ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} pinocchio::pinocchio eigenpy::eigenpy)
target_include_directories(build_wheel_test PRIVATE ${PYTHON_INCLUDE_DIRS})

install(TARGETS build_wheel_test DESTINATION ${PYTHON_SITELIB})
