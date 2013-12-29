cmake_minimum_required ( VERSION 2.8 )
set ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake )

add_executable ( Try1
	try1.cxx
)

include ( use_X11 )
include ( use_OpenGL )

target_link_libraries ( Try1
	${LIBS}
)

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :

