cmake_minimum_required( VERSION 2.8 )

SET( INCLUDE_DIRS
${CMAKE_SOURCE_DIR}/3rdParty/zlib
)
SET( LINK_DIRS
${CMAKE_SOURCE_DIR}/lib
)
SET( LINK_LIBS
zlib
)

parse_directory_name(PROJECT_NAME)
project( ${PROJECT_NAME} )
create_project_ex(STATIC "${INCLUDE_DIRS}" "${LINK_DIRS}" "${LINK_LIBS}")