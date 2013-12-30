#ifndef INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_SHADER_HXX
#define INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_SHADER_HXX

#include <string>
#include <GL/glew.h>

namespace std {
	class istream;
}

namespace Net {
namespace Kaspervandenberg {
namespace Kb_OpenGL {

/**
 * Shaders define how OpenGL renders an image.
 *
 * @author Kasper van den Berg <kasper@kaspervandenberg.net>
 */
class Shader {
	Shader () = delete;
	Shader (const Shader&) = delete;
	Shader (Shader&&) = delete;
	Shader& operator= (const Shader&) = delete;
	Shader& operator= (Shader&&) = delete;

	virtual ~Shader();

public:

	/**
	 * Read a shader source from an input stream.
	 */
	friend std::istream& operator>>(std::istream&, Shader&);

protected:
	std::string source;
};

/**
 * Read a shader source from an input stream.
 */
std::istream& operator>>(std::istream&, Shader&);


}}}
#endif

// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :



