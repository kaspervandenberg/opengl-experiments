#ifndef INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_EXCEPTIONS_INITIALISATION_EXCEPTION_HXX
#define INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_EXCEPTIONS_INITIALISATION_EXCEPTION_HXX

#include <GL/glew.h>

#include "net/kaspervandenberg/kb_opengl/exceptions/opengl_base_exception.hxx"
#include <exception>

namespace Net {
namespace Kaspervandenberg {
namespace Kb_OpenGL {
namespace Exception {

class Initialisation_Exception : public OpenGL_Base_Exception {
public:
	Initialisation_Exception (GLenum glew_status);

	const char* what () const noexcept override;

private:
	GLenum glew_status;
};

}}}}

#endif

// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :



