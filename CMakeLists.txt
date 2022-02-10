cmake_minimum_required(VERSION 3.16)

project(Upload)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(upload-lib)

target_include_directories(upload-lib PUBLIC src)

find_package(oatpp          1.3.0 REQUIRED)

target_link_libraries(upload-lib
    PUBLIC oatpp::oatpp
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(upload-lib INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()

add_executable(upload-exe src/App.cpp)
target_link_libraries(upload-exe upload-lib)
