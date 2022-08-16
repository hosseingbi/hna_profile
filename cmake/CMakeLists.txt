cmake_minimum_required(VERSION 3.0.0)
project(hna_profile VERSION 0.1.0)

include(CTest)
enable_testing()

list(APPEND COMMON_CXX_DEBUG_OPTIONS -std=c++11)
list(APPEND COMMON_CXX_DEBUG_OPTIONS -rdynamic)
list(APPEND COMMON_CXX_DEBUG_OPTIONS -ggdb)
list(APPEND COMMON_CXX_DEBUG_OPTIONS -g3)
list(APPEND COMMON_CXX_DEBUG_OPTIONS -Wall)

list(APPEND COMMON_CXX_RELEASE_OPTIONS -std=c++11)
list(APPEND COMMON_CXX_RELEASE_OPTIONS -rdynamic)
list(APPEND COMMON_CXX_RELEASE_OPTIONS -Wall)
list(APPEND COMMON_CXX_RELEASE_OPTIONS -O3)


add_library(hna_profile ../hna_profile/hna_profile.cpp) 
target_include_directories(hna_profile PRIVATE ../hna_profile/)
target_compile_options(hna_profile PRIVATE "$<$<CONFIG:Debug>:${COMMON_CXX_DEBUG_OPTIONS}>")
target_compile_options(hna_profile PRIVATE "$<$<CONFIG:Release>:${COMMON_CXX_RELEASE_OPTIONS}>")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
