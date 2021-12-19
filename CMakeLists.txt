cmake_minimum_required(VERSION 3.14)
project(SpaceInvadersSFML)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-static")
endif()


find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.h src/Vector2.h src/Vector2.cpp src/MainEnemyClass.cpp src/MainEnemyClass.h src/BasicEnemyMovement.cpp src/BasicEnemyMovement.h src/MainFriendlyClass.cpp src/MainFriendlyClass.h src/PlayerObj.cpp src/PlayerObj.h src/ShieldObj.cpp src/ShieldObj.h src/BulletsObj.cpp src/BulletsObj.h src/StrafingEnemyMovement.cpp src/StrafingEnemyMovement.h src/CircleEnemyMovement.cpp src/CircleEnemyMovement.h src/SinEnemyMovement.cpp src/SinEnemyMovement.h src/MeteorEnemyClass.cpp src/MeteorEnemyClass.h src/QuadraticEnemyMovement.cpp src/QuadraticEnemyMovement.h)
add_executable(SpaceInvadersSFML ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

target_link_libraries (SpaceInvadersSFML sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Data/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Data/)