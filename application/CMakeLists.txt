#add_subdirectory( src/modules/GUI )   # look in module_a subdirectory for CMakeLists.txt to process
#add_subdirectory(src/modules/b)   # look in module_a subdirectory for CMakeLists.txt to process

# version 3.11 or later of CMake or needed later for installing GoogleTest
# so let's require it now.
cmake_minimum_required( VERSION 3.11-3.18 )

project( main )

#file( GLOB_RECURSE SOURCES "src/*.cpp" )
#file( GLOB_RECURSE SOURCES "src/main_01.cpp" )
#file( GLOB_RECURSE SOURCES "src/main_02.cpp" )
file( GLOB_RECURSE SOURCES "src/main_03.cpp" )

file( GLOB_RECURSE CONFIGS "config/*.*" )

#configure_file( ${PROJECT_SOURCE_DIR}/config/test.json ${CMAKE_CURRENT_BINARY_DIR}/config/test.json COPYONLY )

#file(COPY ${PROJECT_SOURCE_DIR}/config/test.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/config )
#${PROJECT_SOURCE_DIR}/

file(COPY ${CONFIGS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/config)

#add_definitions( -DRESTINIO_EXTERNAL_STRING_VIEW_LITE=1 )

add_executable( main ${SOURCES} )

#message(STATUS "CONAN_INCLUDE_DIRS=${CONAN_INCLUDE_DIRS}")

#include_directories( ${CONAN_INCLUDE_DIRS} )

#target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/modules/GUI/include )
target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/include )

# include(CMakePrintHelpers)

# cmake_print_properties(TARGETS raylib
#                        PROPERTIES
#                        LOCATION
#                        INTERFACE_INCLUDE_DIRECTORIES)

# cmake_print_properties(
#     TARGETS raylib
#     PROPERTIES ALL
# )

#find_package(fmt)

target_link_libraries( ${PROJECT_NAME} PRIVATE CPPDBC NANOJSON )

# ***************** Conan Integration ***************

target_link_libraries( ${PROJECT_NAME} PRIVATE PACKAGE_MANAGER_CONAN_LIBS )

# ***************** Conan Integration ***************

# -static-libgcc -static-libstdc++

# Tell C++ compiler to use C++20 features. We don't actually use any of them.
target_compile_features( main PUBLIC cxx_std_20 )
