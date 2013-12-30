#include "net/kaspervandenberg/kb_opengl/exceptions/initialisation_exception.hxx"

#include <GL/glew.h>

namespace Kb_OpenGL_Except = Net::Kaspervandenberg::Kb_OpenGL::Exception;

Kb_OpenGL_Except::Initialisation_Exception::Initialisation_Exception (
		GLenum glew_status_)
		: glew_status{glew_status_}
{
	
}

const char* Kb_OpenGL_Except::Initialisation_Exception::what () const noexcept
{
	return reinterpret_cast<const char*>(glewGetErrorString(glew_status));
}
// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


