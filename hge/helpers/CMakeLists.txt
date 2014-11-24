cmake_minimum_required( VERSION 2.8 )

SET( INCLUDE_DIRS
${CMAKE_SOURCE_DIR}/hge/core
)
SET( LINK_DIRS
${CMAKE_SOURCE_DIR}/lib
${DIRECTX_SDK_DIR}/lib
${DIRECTX_SDK_DIR}/lib/x86
${DIRECTX_SDK_DIR}/lib/x64
)
SET( LINK_LIBS
)

parse_directory_name(PROJECT_NAME)
project( ${PROJECT_NAME} )
create_project_ex(STATIC "${INCLUDE_DIRS}" "${LINK_DIRS}" "${LINK_LIBS}")
