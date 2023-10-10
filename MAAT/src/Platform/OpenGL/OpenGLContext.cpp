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
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MAAT_CORE_ASSERT(status, "Failed to initialize Glad!");

		MAAT_CORE_INFO("OpenGL Info:");
		MAAT_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		MAAT_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		MAAT_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}