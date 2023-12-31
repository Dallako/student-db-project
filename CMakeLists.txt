cmake_minimum_required(VERSION 3.14)
project(student-database)

set (SRCS 
    src/database.cpp
    src/student.cpp
)

add_executable(${PROJECT_NAME} src/main.cpp ${SRCS})
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

#For Windows, but imma use it anyways
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#-------

enable_testing()
add_executable(
    ${PROJECT_NAME}-ut
    src/test.cpp
    ${SRCS}
)
target_link_libraries(
    ${PROJECT_NAME}-ut
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)