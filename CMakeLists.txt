cmake_minimum_required(VERSION 3.16)

# project(yolov8 C CXX)

set(EXE list)
project(${EXE} C)

# set(TENSORFLOW_SOURCE_DIR "" CACHE PATH
#   "Directory that contains the TensorFlow project"
# )
# if(NOT TENSORFLOW_SOURCE_DIR)
#   get_filename_component(TENSORFLOW_SOURCE_DIR
#     "${CMAKE_CURRENT_LIST_DIR}/../../../../"
#     ABSOLUTE
#   )
# endif()

# add_subdirectory(
#   "${TENSORFLOW_SOURCE_DIR}/tensorflow/lite"
#   "${CMAKE_CURRENT_BINARY_DIR}/tensorflow-lite"
#   EXCLUDE_FROM_ALL
# )

# add_definitions(-D_GL_2_APPENDIX)
# aux_source_directory(./src/ SRC_LIST)
# aux_source_directory(./shader_c/ REF_LIST)
set (SRC_LIST
${CMAKE_CURRENT_LIST_DIR}/list.c
${CMAKE_CURRENT_LIST_DIR}/main.c
)
# set(INCLUDE_DIR ./include)
include_directories(
        ${CMAKE_CURRENT_LIST_DIR}
)

add_executable(${EXE} ${SRC_LIST})

target_link_libraries(
-g
${EXE}
-O0
)
