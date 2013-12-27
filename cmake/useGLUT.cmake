# useGLUT
# use OpenGL Utility Toolkit, a Window sytem independent toolkit for writing 
# OpenGL programs
#
# postconditions:
# - variable ${LIBS} contains libraries required to link to GLUT
# - include directories contain include path for GLUT

find_package ( GLUT REQUIRED )
if ( GLUT_FOUND )
	include_directories ( ${GLUT_INCLUDE_DIR} )
	set ( LIBS ${LIBS} ${GLUT_LIBRARIES} )
endif ( GLUT_FOUND )

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


