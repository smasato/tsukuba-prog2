cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_EXTENSIONS OFF)

project(prog2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-deprecated -std=c11")

set(CMAKE_C_COMPILER gcc)

set(INCLUDE_DIR
        ${PROJECT_SOURCE_DIR}/include
        )
include_directories("${INCLUDE_DIR}")

add_library(GenericTimer STATIC ${PROJECT_SOURCE_DIR}/lib/GenericTimer.c)

set(LIBRARIES GenericTimer)

IF (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    SET(LIBRARIES
            ${LIBRARIES}
            -framework\ GLUT
            -framework\ OpenGL)
ELSE ()
    SET(LIBRARIES
            ${LIBRARIES}
            -lglut -lGL -lGLU -lm)
ENDIF ()

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.c)
target_link_libraries(main ${LIBRARIES})