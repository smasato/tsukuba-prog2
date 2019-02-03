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
#add_library(png STATIC
#        )
add_library(glpng STATIC ${PROJECT_SOURCE_DIR}/lib/glpng.c
        ${PROJECT_SOURCE_DIR}/lib/png/png.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngerror.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngget.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngmem.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngread.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngpread.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngrio.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngrtran.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngrutil.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngset.c
        ${PROJECT_SOURCE_DIR}/lib/png/pngtrans.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/adler32.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/crc32.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/infblock.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/infcodes.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/inffast.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/inflate.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/inftrees.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/infutil.c
        ${PROJECT_SOURCE_DIR}/lib/zlib/zutil.c)

set(LIBRARIES
        GenericTimer
        glpng
        )

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
