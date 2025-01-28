cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

set(SOURCES_FILES 
    "sources/application/main.cpp"
    "sources/lib/widget.cpp"
    "sources/lib/resources.cpp" 
    "example/label.cpp"
 "example/buttton.cpp" "example/AddShortcut.cpp" "example/HBox.cpp")
set(HEADER_FILES 
    "sources/lib/widget.hpp"
    "sources/lib/windef.hpp"
    "sources/lib/resources.hpp"
)

add_executable(main ${SOURCES_FILES} ${HEADER_FILES})

# target_include_directories(main PUBLIC include)
target_compile_features(main PRIVATE cxx_std_20)
target_link_libraries(main PRIVATE SFML::Graphics)
file (COPY resources DESTINATION ${CMAKE_BINARY_DIR})
