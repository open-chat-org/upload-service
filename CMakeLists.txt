cmake_minimum_required(VERSION 3.16)

# set the project name
project(UploadService VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
if(CMAKE_CROSSCOMPILING)
  find_program(_PROTOBUF_PROTOC protoc)
else()
  set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
endif()

find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_GRPC_GRPCPP gRPC::grpc++)
if(CMAKE_CROSSCOMPILING)
  find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
else()
  set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
endif()

add_executable(upload-service src/main.cpp)

link_directories("/usr/local/lib")
link_directories("/usr/lib/x86_64-linux-gnu")
include_directories("/usr/local/include/opencv4")

target_link_libraries(
  upload-service
  PRIVATE
  libnats.so
  libhttpserver.so
  libopencv_core.so
  libopencv_imgcodecs.so
  
  libpthread.so
  libprotobuf.so
  
  libgrpcpp_channelz.so
  libgrpc++.so
  libgpr.so
  libabsl_synchronization.so
)

add_subdirectory(src)
