#include "net/kaspervandenberg/kb_opengl/shader.hxx"

#include <istream>
#include <sstream>

using namespace Kb_OpenGL = Net::Kaspervandenberg::Kb_OpenGL;

/**
 * Read a shader source from an input stream.
 */
std::istream& Kb_OpenGL::operator>> (
		std::istream& in,
		Kb_OpenGL::Shader& target)
{
	std::ostringstream contents;
	contents << in.rdbuf();
	target.source = contents.str();

	return in;
}

// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :

