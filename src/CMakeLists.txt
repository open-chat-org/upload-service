add_subdirectory(handler)
add_subdirectory(pb)
add_subdirectory(util)

target_link_libraries(
  upload-service
  PRIVATE
  handler
  pb
  util
)
