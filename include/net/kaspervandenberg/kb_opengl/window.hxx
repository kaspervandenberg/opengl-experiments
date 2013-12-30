#ifndef INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_WINDOW_HXX
#define INCLUDED_NET_KASPERVANDENBERG_KB_OPENGL_WINDOW_HXX

#include <memory>
#include <vector>

namespace Net {
namespace Kaspervandenberg {
namespace Kb_OpenGL {

class OpenGL_Init;

class Window {
public:
	struct PixelCount {
		int n;
	};

	struct Dimension {
		PixelCount width;
		PixelCount heigth;

		constexpr inline int getWidth() { return width.n; } const;
		constexpr inline int getHeight() { return height.n; } const;
	};

	class Options {
	public:
		/**
		 * The windowSize supplied to `glutInitWindowSize()`.
		 */
		Options& windowSize(const Dimension& size);

		/**
		 * The title of the application window.
		 */
		Options& windowTitle(const std::string& title);

		/**
		 * Options are used by `Window::Window`.
		 */
		friend Window::Window(
				std::shared_ptr<OpenGL_Init>,
				const Options& opts);

	private:
		Dimension size;
		std::string title;
	};

public:
	Window(std::shared_ptr<OpenGL_Init>, const Options& opts);
	Window(Window&& other);
	Window& operator=(Window&& other);
	~Window();

private:
	Window() = delete;
	Window(const Window&) = delete;
	Window& operator(const Window&) = delete;

private:
	static std::vector<std::shared_ptr<Window>> cannonical_windows;
	std::shared_ptr<OpenGL_Init> initialiser;
	int glut_handle;
};

}}}

#endif

// vim:set tabstop=4 shiftwidth=4 autoindent fo=cqwan :


