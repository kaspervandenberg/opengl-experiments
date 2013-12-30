#include "net/kaspervandenberg/kb_opengl/opengl_init.hxx"

/* Use glew.h instead of gl.h to get all the GL prototypes declared */
#include <GL/glew.h>
/* Using the GLUT library for the base windowing setup */
#include <GL/glut.h>

#include "net/kaspervandenberg/kb_opengl/exceptions/initialisation_exception.hxx"

namespace Kb_OpenGL = Net::Kaspervandenberg::Kb_OpenGL;

Kb_OpenGL::OpenGL_Init::Options&
Kb_OpenGL::OpenGL_Init::Options::commandLineArgs (
		int *argc_, char **argv_)
{
	argc = argc_;
	argv = argv_;

	return *this;
}


Kb_OpenGL::OpenGL_Init::OpenGL_Init ()
: OpenGL_Init{Options{}}
{

}

Kb_OpenGL::OpenGL_Init::OpenGL_Init(const Options& options)
{
	int dummyArgc {};
	char *dummyArgv[] {};

	int *pArgc = &dummyArgc;
	char **pArgv = dummyArgv;

	if (options.argc && options.argv) {
		pArgc = options.argc;
		pArgv = options.argv;
	}

	glutInit (pArgc, pArgv);

	/* TODO provide options to set these; instead of hardcoding the
	 * settings.
	 */
	glutInitDisplayMode (GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);


	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK) {
		throw Exception::Initialisation_Exception (
				glew_status);
	}
}
// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


