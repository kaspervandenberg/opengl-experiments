# use_kb_OpenGL
# Use kb-OpenGL, a custom C++ wrapper arround OpenGL, GLUT, GLEW, etc.
#
# Pre conditions:
# - Part of project1
#
# Post condtions:
# - Variable ${LIBS} contains libraries required to link to kb_OpenGL,
#   including OpenGL, GLUT, and GLEW.
# - Include directories contain path for kb_OpenGL

cmake_minimum_required ( VERSION 2.8 )

include_directories ( "${OpenGL_Experiments_SOURCE_DIR}/include" )
link_directories ( "${OpenGL_Experiments_BINARY_DIR}/kb_opengl" )
set ( LIBS ${LIBS} kb_OpenGL )

# vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :

