cmake_minimum_required( VERSION 2.8 )

parse_directory_name(PROJECT_NAME)
project( ${PROJECT_NAME} )
create_project(STATIC)

set(VERSION "1.2.8")