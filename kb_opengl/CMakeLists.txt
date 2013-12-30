cmake_minimum_required ( VERSION 2.8 )
set ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake )

add_library ( kb_OpenGL
	net/kaspervandenberg/kb_opengl/opengl_init.cxx
	net/kaspervandenberg/kb_opengl/exceptions/initialisation_exception.cxx
)


include ( use_X11 )
include ( use_OpenGL )
include  ( use_GLUT )
include ( use_GLEW )

target_link_libraries ( kb_OpenGL ${LIBS} )

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


