cmake_minimum_required ( VERSION 2.8 )
set ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake )

add_executable ( Try3
	try3.cxx
)

set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

include ( use_kb_OpenGL )
# include ( use_X11 )
# include ( use_OpenGL )
# include  ( use_GLUT )
# include ( use_GLEW )

target_link_libraries ( Try3
	${LIBS}
)

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


