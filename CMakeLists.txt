cmake_minimum_required(VERSION 3.5)

project(MultilanguageSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)

include(GNUInstallDirs)

add_subdirectory(json)

include_directories(json/include)
include_directories(Types)
include_directories(include)

add_library(MultilanguageSystem STATIC
    include/MLSystem.hpp
    src/getReplic.cpp
)

install(TARGETS MultilanguageSystem
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

target_link_libraries(MultilanguageSystem PRIVATE nlohmann_json::nlohmann_json spdlog::spdlog )
