cmake_minimum_required ( VERSION 2.8 )
project ( OpenGL_Experiments )

add_definitions (-std=c++11)

include_directories ( "include" )
add_subdirectory ( try1 )
add_subdirectory ( try2 )
add_subdirectory ( try3 )
add_subdirectory ( kb_opengl )

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :

