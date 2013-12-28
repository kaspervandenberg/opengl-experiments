cmake_minimum_required ( VERSION 2.8 )
set ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake )

add_executable ( Try2
	try2.cxx
)

set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")

include ( useX11 )
include ( useOpenGL )
include  ( useGLUT )
include ( useGLEW )

target_link_libraries ( Try2
	${LIBS}
)

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


