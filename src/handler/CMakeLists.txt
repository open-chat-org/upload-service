add_library(handler "")

target_sources(
  handler
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/upload_avatar.cpp
  ${CMAKE_CURRENT_LIST_DIR}/response.cpp
  ${CMAKE_CURRENT_LIST_DIR}/publish.cpp
  ${CMAKE_CURRENT_LIST_DIR}/image_processing.cpp
  ${CMAKE_CURRENT_LIST_DIR}/grpc_user.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/upload_avatar.h
  ${CMAKE_CURRENT_LIST_DIR}/response.h
  ${CMAKE_CURRENT_LIST_DIR}/publish.h
  ${CMAKE_CURRENT_LIST_DIR}/image_processing.h
  ${CMAKE_CURRENT_LIST_DIR}/grpc_user.h
)

target_include_directories(
  handler
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
