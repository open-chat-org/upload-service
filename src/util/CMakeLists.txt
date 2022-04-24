add_library(util "")

set_target_properties(util PROPERTIES LINKER_LANGUAGE CXX)

target_sources(
  util
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/endianness.h
  ${CMAKE_CURRENT_LIST_DIR}/uuid_v4.h
)

target_include_directories(
  util
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
)
