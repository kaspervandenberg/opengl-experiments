/* Tutorial from
 * http://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Introduction
 */

/* Using the standard output for fprintf */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
/* Use glew.h instead of gl.h to get all the GL prototypes declared */
#include <GL/glew.h>
/* Using the GLUT library for the base windowing setup */
#include <GL/glut.h>

/* ADD GLOBAL VARIABLES HERE LATER */
GLuint program;
GLint attribute_coord2d;
 
int init_resources(void)
{
	GLint compile_ok = GL_FALSE;
	GLint link_ok = GL_FALSE;
	GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);

	const char* vs_source {
#ifdef GL_ES_VERSION__2_0
		"#version 100\n"	// OpenGL ES 2.0
#else
		"#version 120\n"	// OpenGL 2.1
#endif
		"attribute vec2 coord2d;						\n"
		"void main(void) {								\n"
		"    gl_Position = vec4 (coord2d, 0.0, 1.0);	\n"
		"}												\n"
	};
	glShaderSource(vertex_shader, 1, &vs_source, nullptr);
	glCompileShader(vertex_shader);
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &compile_ok);
	if (!compile_ok) {
		std::cerr << "Error in vertex shader.\n";
		return 0;
	}
	

	GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* fs_source {
		"#version 120\n"
		"void main(void) {								\n"
		"	gl_FragColor[0] = 0.0;						\n"
		"	gl_FragColor[1] = 0.0;						\n"
		"	gl_FragColor[2] = 1.0;						\n"
		"}												\n"
	};
	glShaderSource(fragment_shader, 1, &fs_source, nullptr);
	glCompileShader(fragment_shader);
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &compile_ok);
	if (!compile_ok) {
		std::cerr << "Error in fragment shader.\n";
		return 0;
	}


	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
	if(!link_ok) {
		std::cerr << "glLinkProgram:\n";
		return 0;
	}

	const char* attribute_name = "coord2d";
	attribute_coord2d = glGetAttribLocation(program, attribute_name);
	if (attribute_coord2d == -1) {
		std::cerr << "Could not bind attribute " << attribute_name << std::endl;
		return 0;
	}

	return 1;
}
 
void onDisplay()
{
	/* Clear the background as white */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(program);
	glEnableVertexAttribArray(attribute_coord2d);
	GLfloat triangle_vertexes[] {
		0.0, 0.8,
		-0.8, -0.8,
		0.8, 0.8
	};
	/* Describe our vertices array to OpenGL (it can't guess its format 
	 * automatically) */
	glVertexAttribPointer(
		attribute_coord2d,	// attribute
		2,					// number of elements per vertex, here (x, y)
		GL_FLOAT,			// the type of each element
		GL_FALSE,			// take our values as-is
		0,					// no extra data between each possition
		triangle_vertexes	// pointer to the C array
	);

	/* Push each element in triangle_vertexes to the vertex shader */
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(attribute_coord2d);

	/* Display the result */
	glutSwapBuffers();
}
 
void free_resources()
{
	glDeleteProgram(program);
}
 
int main(int argc, char* argv[])
{
	/* Glut-related initialising functions */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutCreateWindow("My First Triangle");
 
	/* Extension wrangler initialising */
	GLenum glew_status = glewInit();
	if (glew_status != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		return EXIT_FAILURE;
	}
 
	/* When all init functions run without errors,
	the program can initialise the resources */
	if (1 == init_resources())
	{
		/* We can display it if everything goes OK */
		glutDisplayFunc(onDisplay);
		glutMainLoop();
	}
 
	/* If the program exits in the usual way,
	free resources and exit with a success */
	free_resources();
	return EXIT_SUCCESS;
}

// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


