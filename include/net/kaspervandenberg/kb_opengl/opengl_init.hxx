#ifndef INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_INIT_HXX
#define INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_INIT_HXX

namespace Net {
namespace Kaspervandenberg {
namespace Kb_OpenGL {

/**
 * OpenGL as a resource takes care of inialisation and cleanup.
 */
class OpenGL_Init {

public:
	class Options {
	public:
		/**
		 * Pointers to the (unmodified) `argc` and `argv` with which `main`
		 * was invoked.
		 * `OpenGL_Init()` supplies these to `glutInit()`.
		 * `glutInit()` modifies these, extracting the arguments to the
		 * glut library.
		 */
		Options& commandLineArgs (int *argc, char **argv);

		friend OpenGL_Init;

	private:
		int *argc;
		char **argv;
	};

public:
	OpenGL_Init ();
	OpenGL_Init (const Options&);
	~OpenGL_Init ();

private:
	OpenGL_Init (const OpenGL_Init&) = delete;
	OpenGL_Init (OpenGL_Init&&) = delete;
	OpenGL_Init& operator= (const OpenGL_Init&) = delete;
	OpenGL_Init& operator= (OpenGL_Init&&) = delete;
};

}}}

#endif


// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :

