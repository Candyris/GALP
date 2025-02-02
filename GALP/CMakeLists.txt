cmake_minimum_required(VERSION 3.28)
project(GALP VERSION 0.0.1)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)


# include the GALP 
include_directories(include)

# source cpp files
set(SOURCES_FILES 
    "lib/widget.cpp"
    "lib/resources.cpp" 
    "lib/Label.cpp"
    "lib/Button.cpp" 
    "lib/HBox.cpp" 
    "lib/Slider.cpp" 
    "lib/Application.cpp" 
    "lib/Object.cpp"
    "lib/Utility.cpp"
    "lib/LineEdit.cpp"
    "lib/SpinBox.cpp"
    "lib/VBox.cpp"
)
    # "sources/application/main.cpp"
add_library(${PROJECT_NAME} ${SOURCES_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics)

