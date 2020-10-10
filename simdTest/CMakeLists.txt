cmake_minimum_required(VERSION 2.8)

project(NNDMA_TEST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfp64 -EL -static -O3 -lm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfp64 -EL -static -O3 -lm")

set(CMAKE_CXX_STANDARD 11)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/source
  ${PROJECT_SOURCE_DIR}/include/mxu3
  )

enable_language(ASM)

set(AIE_NNA_OBJS
  "${PROJECT_BINARY_DIR}/test_LIW.o"
  )
set(AIE_NNA_INC
  -I ${PROJECT_SOURCE_DIR}/source
  -I ${PROJECT_SOURCE_DIR}/include/mxu3
  )

set(AIE_NNA_C_FLAGS -mfp64 -mnan=2008 -fPIC -O3 -L/mllib/tools/mips-gcc520-glibc222/mips-linux-gnu/libc/usr -lm)
add_custom_command(
  OUTPUT ${AIE_NNA_OBJS}
  #PRE_BUILD
  COMMAND ${CMAKE_C_COMPILER} ${AIE_NNA_C_FLAGS} ${AIE_NNA_INC} -S ${PROJECT_SOURCE_DIR}/source/test_LIW.c -o ${PROJECT_BINARY_DIR}/test_LIW.s
  COMMAND python3 ${PROJECT_SOURCE_DIR}/tools/mxu3_asm.py ${PROJECT_BINARY_DIR}/test_LIW.s >| ${PROJECT_BINARY_DIR}/test_LIW.c.s
  COMMAND rm -f ${PROJECT_BINARY_DIR}/test_LIW.s
  COMMAND ${CMAKE_C_COMPILER} ${AIE_NNA_C_FLAGS} ${AIE_NNA_INC} -c ${PROJECT_BINARY_DIR}/test_LIW.c.s -o ${PROJECT_BINARY_DIR}/test_LIW.o)

add_executable(testliw
  ${PROJECT_SOURCE_DIR}/testliw.c
  ${AIE_NNA_OBJS}
  )
target_link_libraries(testliw m)
