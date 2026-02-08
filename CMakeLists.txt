cmake_minimum_required(VERSION 3.10)

project(animalguessergame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.cpp")

add_executable(animalguessergame ${SOURCES})
target_include_directories(animalguessergame PUBLIC ${PROJECT_SOURCE_DIR}/include)

if(MSVC)
    target_compile_options(animalguessergame PRIVATE /W4)
else()
    target_compile_options(animalguessergame PRIVATE -Wall -Wextra)
endif()
