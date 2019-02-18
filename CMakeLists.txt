cmake_minimum_required(VERSION 3.5)
set(CMAKE_C_EXTENSIONS OFF)

project(prog2 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-deprecated -std=gnu11")

set(INCLUDE_DIR
        ${PROJECT_SOURCE_DIR}/include
        )
include_directories("${INCLUDE_DIR}")

add_library(Texture STATIC ${PROJECT_SOURCE_DIR}/lib/Texture.c)
add_library(Ranking STATIC ${PROJECT_SOURCE_DIR}/lib/Ranking.c)
add_library(Text STATIC ${PROJECT_SOURCE_DIR}/lib/Text.c)
add_library(Timer STATIC ${PROJECT_SOURCE_DIR}/lib/Timer.c)

set(LIBRARIES
        Texture
        Ranking
        Text
        Timer
        png
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

add_executable(test_ranking ${PROJECT_SOURCE_DIR}/test/ranking.c)
target_link_libraries(test_ranking ${LIBRARIES})
