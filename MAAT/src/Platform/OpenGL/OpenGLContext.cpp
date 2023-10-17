#include "mtpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace MAAT {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		MAAT_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		MAAT_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MAAT_CORE_ASSERT(status, "Failed to initialize Glad!");

		MAAT_CORE_INFO("OpenGL Info:");
		MAAT_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		MAAT_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		MAAT_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	#ifdef MAAT_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			MAAT_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "MAAT requires at least OpenGL version 4.5!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		MAAT_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}