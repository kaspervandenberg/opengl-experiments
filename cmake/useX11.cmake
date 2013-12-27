# useX11
# Use X11 window system
#
# Post conditions:
# - Variable ${LIBS} contains libraries required to link to X11
# - include directories contain include path for X11
 
find_package ( X11 REQUIRED )
if ( FOUND_X11 )
	include_directories ( ${X11_INCLUDE_DIR} )
	set ( LIBS ${LIBS} ${X11_LIBRARIES} )
endif ( FOUND_X11 )

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :

