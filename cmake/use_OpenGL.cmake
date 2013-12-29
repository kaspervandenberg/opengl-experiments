# use_OpenGL
# Use OpenGL 3D graphics rendering library
#
# Post conditions:
# - Variable ${LIBS} contains libraries required to link to OpenGL
# - include directories contain include path for OpenGL
 
# Open GL
find_package ( OpenGL REQUIRED )
if ( OPENGL_FOUND )
	include_directories ( ${OPENGL_INCLUDE_DIR} )
	set ( LIBS ${LIBS} ${OPENGL_LIBRARIES} )
endif ( OPENGL_FOUND )

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :

