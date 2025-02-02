cmake_minimum_required(VERSION 3.28)
project(example VERSION 0.0.1)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


# source cpp files
set(EXAMPLE_FILES 
"example/buttton.cpp" 
"example/AddShortcut.cpp" 
"example/test.cpp"
"example/HBox.cpp" 
"example/slider.cpp"
"example/label.cpp"
)
    # "sources/application/main.cpp"
add_library(${PROJECT_NAME} EXAMPLE_FILES)