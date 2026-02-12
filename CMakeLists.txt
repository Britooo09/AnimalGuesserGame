cmake_minimum_required(VERSION 3.16)
project(animalguessergame)

# 1. Global settings and Qt compatibility
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enabling automatic processing of Qt files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 2. Search for packages (If it cannot find Qt, the console version will still work)
find_package(Qt6 COMPONENTS Widgets QUIET)

# 3. Header directories
# 'include' for core logic, 'src/gui' for Qt .h files
include_directories(include src/gui)

# 4. TARGET: Core Logic (Shared Library)
file(GLOB CORE_SOURCES "src/core/*.cpp")
add_library(GameCore ${CORE_SOURCES})

# 5. TARGET: Console App
file(GLOB CLI_SOURCES "src/cli/*.cpp")
add_executable(animalguesser_cli ${CLI_SOURCES})
target_link_libraries(animalguesser_cli PRIVATE GameCore)

# 6. TARGET: GUI App (For Qt)
if(Qt6_FOUND)
    file(GLOB GUI_SOURCES "src/gui/*.cpp" "src/gui/*.h" "src/gui/*.ui" "*.qrc")
    add_executable(animalguesser_gui ${GUI_SOURCES})
    target_link_libraries(animalguesser_gui PRIVATE GameCore Qt6::Widgets)
    
    # Opcional: Evita que se abra una consola negra al lanzar la GUI en Windows
    # set_target_properties(animalguesser_gui PROPERTIES WIN32_EXECUTABLE TRUE)
else()
    message(WARNING "Qt6 not found. Target 'animalguesser_gui' will not be created.")
endif()
