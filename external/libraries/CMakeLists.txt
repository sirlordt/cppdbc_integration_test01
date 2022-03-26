# version 3.11 or later of CMake needed later for installing GoogleTest
# so let's require it now.
cmake_minimum_required( VERSION 3.11 )

project( MAIN_EXTERNAL_LIBRARIES
         VERSION 0.1
         DESCRIPTION "Main External Libraries" )

# ******* cppdb ********
add_subdirectory( ${PROJECT_SOURCE_DIR}/cppdbc )  # look in cppdbc subdirectory for CMakeLists.txt to process
# ******* cppdb ********

# ******* mysql ********
add_subdirectory( ${PROJECT_SOURCE_DIR}/mysql )  # look in mysql subdirectory for CMakeLists.txt to process
# ******* mysql ********

# ******* nanojson ********
add_subdirectory( ${PROJECT_SOURCE_DIR}/nanojson )  # look in nanojson subdirectory for CMakeLists.txt to process
# ******* nanojson ********

# # ******* conan package manager ********

# #set(CONAN_DISABLE_CHECK_COMPILER TRUE)

# # Download automatically, you can also just copy the conan.cmake file
# if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
#    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
#    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
#                   "${CMAKE_BINARY_DIR}/conan.cmake")
# endif()

# set(CONAN_DISABLE_CHECK_COMPILER True CACHE BOOL "" FORCE )

# include(${CMAKE_BINARY_DIR}/conan.cmake)

# conan_cmake_run(REQUIRES restinio/0.6.14
#                 BASIC_SETUP
#                 BUILD missing )

# # conan_cmake_run(REQUIRES mongo-cxx-driver/3.6.6
# #                 BASIC_SETUP
# #                 BUILD missing )

# # conan_cmake_run(REQUIRES nlohmann_json/3.10.4
# #                 BASIC_SETUP)

# conan_cmake_run(REQUIRES fmt/8.0.1
#                 BASIC_SETUP
# #                SETTINGS compiler.version=9.3;
#                 BUILD missing)

# # conan_cmake_run(REQUIRES rapidjson/cci.20211112
# #                 BASIC_SETUP )

# # conan_cmake_run(REQUIRES spdlog/1.9.2
# #                 BASIC_SETUP
# #                 BUILD missing )

# add_library(${PROJECT_NAME} INTERFACE)

# message(STATUS "CONAN_INCLUDE_DIRS=${CONAN_INCLUDE_DIRS}")

# target_include_directories( ${PROJECT_NAME} INTERFACE ${CONAN_INCLUDE_DIRS} )

# # ******* conan package manager ********
