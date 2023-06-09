# cmake 最低版本要求
cmake_minimum_required(VERSION 3.22.1)
# 定义工程名称
file(RELATIVE_PATH project_name ${CMAKE_CURRENT_LIST_DIR}/.. ${CMAKE_CURRENT_LIST_DIR})
project (${project_name})
# Generate lexer and parser codes
message("-- Generating lexer and parser codes")
execute_process(WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/src
				COMMAND flex Lexer.l
				COMMAND bison -d Parser.y)
# Set dependencies
set (CMAKE_CXX_STANDARD 20)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS})
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set project files

file(GLOB SOURCES ./src/*.hpp ./src/*.cpp)
add_executable(${project_name} ${SOURCES})

# Link
execute_process(COMMAND llvm-config-14 --libs all
                OUTPUT_VARIABLE llvm_libs)
string(STRIP ${llvm_libs} llvm_libs)
string(REPLACE " " ";" llvm_libs ${llvm_libs})
target_link_libraries(${project_name} ${llvm_libs})


