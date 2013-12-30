#ifndef INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_EXCEPTIONS_OPENGL_BASE_EXCEPTION_HXX
#define INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_EXCEPTIONS_OPENGL_BASE_EXCEPTION_HXX

#include <exception>

namespace Net {
namespace Kaspervandenberg {
namespace Kb_OpenGL {
namespace Exception {

class OpenGL_Base_Exception : public std::exception {
	using std::exception::exception;
};

}}}}

#endif

// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


