# version 3.11 or later of CMake needed later for installing GoogleTest
# so let's require it now.
cmake_minimum_required( VERSION 3.11 )

project( CPPDBC
         VERSION 0.1
         DESCRIPTION "CPPDBC Library connection" )

# ******* cppdb ********

file( GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp )
#file( GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/include/*.hpp )

add_library( ${PROJECT_NAME} ${SOURCES} ) # ${HEADERS} )

target_include_directories( ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )

target_link_libraries( ${PROJECT_NAME} INTERFACE mysql_client mysql_services )

# ******* cppdb ********
