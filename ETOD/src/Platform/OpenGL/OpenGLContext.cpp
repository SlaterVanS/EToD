#include "etodpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace ETOD {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		ETOD_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		ETOD_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ETOD_CORE_ASSERT(status, "Failed to initialize Glad!");

		ETOD_CORE_INFO("OpenGL Info:");
		ETOD_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ETOD_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ETOD_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		ETOD_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "ETOD requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		ETOD_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
