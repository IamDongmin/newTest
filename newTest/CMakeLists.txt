cmake_minimum_required(VERSION 3.0.0)

project(newTest)

add_executable(${PROJECT_NAME}
    main.cpp
    ./Button/Button.cpp
    ./Led/Led.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ./Button
    ./Led
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    -lwiringPi
)

target_compile_options(${PROJECT_NAME} PUBLIC
    -Wall
)