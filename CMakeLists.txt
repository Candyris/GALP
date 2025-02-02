cmake_minimum_required(VERSION 3.28)
project(GUI_APP LANGUAGES CXX)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

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

include_directories(GALP)
add_subdirectory(GALP)

# # Find the SFML package
# find_package(SFML 3.0.0 COMPONENTS Graphics REQUIRED)
# include_directories(example)
# add_subdirectory(example)

add_executable(main "application/main.cpp" )

#add_executable(main WIN32 ${SOURCES_FILES} ${HEADER_FILES} )
# target_include_directories(main PUBLIC include)

target_link_libraries(main PUBLIC GALP)
# target_link_libraries(main example)

target_compile_features(main PRIVATE cxx_std_20)
target_link_libraries(main PRIVATE SFML::Graphics)

message("PRINT OUT DIR ${CMAKE_BINARY_DIR}")

file (COPY resources DESTINATION "${CMAKE_BINARY_DIR}")

