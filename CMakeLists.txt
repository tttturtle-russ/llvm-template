cmake_minimum_required(VERSION 3.25.0)

project(MyPass)

set(CMKAE_CXX_STANDARD 14)
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM in ${LLVM_PATH}")

include(AddLLVM)
add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

# Add pass plugin
add_llvm_pass_plugin(MyPass src/MyPass.cpp)
