cmake_minimum_required(VERSION 3.0)
list(APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake
  ${CMAKE_CURRENT_SOURCE_DIR}/platforms/sfml
)

include(add_warnings)
include(add_sources)

project(gbemu)

if (NOT MSVC)
  add_definitions(-std=c++17)
  add_warnings()
  # SDL target
  find_package(SDL2)
else()
  set(SDL2_FOUND True)
  set(SDL2_INCLUDE_DIRS "Unknown" CACHE PATH "Path to SDL2 include directory")
  set(SDL2_LIBRARIES "Unknown" CACHE FILEPATH "Path to SDL2 link library")
endif()

declare_library(gbemu-core src)

# SFML target
# find_package(SFML 2 COMPONENTS system window graphics)

# if (SFML_FOUND)
#   declare_executable(gbemu-sfml platforms/sfml)
#   include_directories(SYSTEM ${SFML_INCLUDE_DIR})
#   target_link_libraries(gbemu-sfml gbemu-core ${SFML_LIBRARIES})
# endif()

if (SDL2_FOUND)
  declare_executable(gbemu platforms/sdl)
  include_directories(SYSTEM ${SDL2_INCLUDE_DIRS})
  target_link_libraries(gbemu gbemu-core ${SDL2_LIBRARIES})
endif()

# Test target
declare_executable(gbemu-test platforms/test)
target_link_libraries(gbemu-test gbemu-core)
