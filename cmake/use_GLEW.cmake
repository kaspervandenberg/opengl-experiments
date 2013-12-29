# use_GLEW
# use the OpenGL Extension Wrangler, GLEW for short, is a library that
# handles initialization of OpenGL extensions in a portable and simple
# way.
#
# postconditions:
# - variable ${LIBS} contains libraries required to link to GLEW
# - include directories contain include path for GLEW

find_package ( GLEW REQUIRED )
if ( GLEW_FOUND )
	include_directories ( ${GLEW_INCLUDE_DIRS} )
	set ( LIBS ${LIBS} ${GLEW_LIBRARIES} )
endif ( GLEW_FOUND )

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :

