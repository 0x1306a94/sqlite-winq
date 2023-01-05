cmake_minimum_required(VERSION 3.6)

project(sqlite-winq-sample)

file(
  GLOB TEMP_SRC_FILES
  RELATIVE ${PROJECT_SOURCE_DIR}
  ./*.cpp ./*.hpp)
list(APPEND SRC_FILES ${TEMP_SRC_FILES})

message(STATUS ${SRC_FILES})
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ../include)
target_link_libraries(${PROJECT_NAME} sqlite-winq)