add_library(pb "")

target_sources(
  pb
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/user.grpc.pb.cc
  ${CMAKE_CURRENT_LIST_DIR}/user.pb.cc
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/user.grpc.pb.h
  ${CMAKE_CURRENT_LIST_DIR}/user.pb.h
)

target_include_directories(
  pb
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
