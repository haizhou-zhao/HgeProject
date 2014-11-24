cmake_minimum_required( VERSION 2.8 )
# Set the build type.  Options are:
#  Coverage       : w/  debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/  debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/  optimization
#  RelWithDebInfo : w/  debug symbols, w/  optimization
#  MinSizeRel     : w/o debug symbols, w/  optimization, stripped binaries

set(CMAKE_MODULE_PATH "C:/Users/Haizhou/Documents/GitHub/CMake")

# Include necessary submodules
#if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/../CMake")
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../CMake")
#else()
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
#endif()

include(SetOutputDirectories)
include(SourceFileScanner)

# Add compile flags and preprocessor definitions
add_definitions( "/FC")
SET( HGE_DIRECTX_VER "9" )
add_definitions( "-DHGE_DIRECTX_VER=${HGE_DIRECTX_VER}" "-DHGE_UNICODE=${HGE_UNICODE}" )
SET( DIRECTX_SDK_DIR "C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)" )


#create solution
parse_directory_name(PROJECT_NAME)
project( ${PROJECT_NAME} )
setup_solution(PROJECT_NAME)
##----------------------------------------
## End of manual configuration section
## try to minimize tampering with code below unless you know how CMake works
##----------------------------------------
