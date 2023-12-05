cmake_minimum_required (VERSION 3.11)

project (Sorts CXX)

if(MSVC)
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_library(sorts STATIC "../src/sorts/sorts.cc" "../src/sorts/stats.cc")
target_include_directories(sorts PUBLIC "../include/")

add_executable(${PROJECT_NAME} "../src/main.cpp")
target_link_libraries(${PROJECT_NAME} sorts)
#target_link_libraries(sorts "../src/sorts/sorts.cc" "../src/sorts/stats.cc")