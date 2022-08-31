cmake_minimum_required(VERSION 3.23.2)

file(TIMESTAMP "${CMAKE_CURRENT_LIST_DIR}/vcpkg.json" vcpkg_json_timestamp)

if(VCPKG_JSON_TIMESTAMP_PREV STREQUAL vcpkg_json_timestamp)
    set(VCPKG_MANIFEST_INSTALL OFF CACHE STRING "" FORCE)
else()
    set(VCPKG_MANIFEST_INSTALL ON CACHE STRING "" FORCE)
endif()

include_directories(${OpenCV_INCLUDE_DIRS})

project(
    PDI-IFCE 
    VERSION 0.1.0
    LANGUAGES CXX
)

find_package(OpenCV CONFIG REQUIRED)

add_executable(${PROJECT_NAME}-01 01/main.cpp)

target_link_libraries(
    ${PROJECT_NAME}-01 
    ${OpenCV_LIBS}
)

target_compile_features(
    ${PROJECT_NAME}-01

    PUBLIC
        cxx_std_20
)

# include(CTest)
# enable_testing()

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
