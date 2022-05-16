#pragma once
#include <GLFW/glfw3.h>
#include <thread>
#pragma comment(lib,"OpenGL32")

#include "Color.hpp"

namespace Engine
{

	class WindowManager 
	{
		GLFWwindow* window;
	public:
		static void error_callback(int error, const char* description)
		{
			fputs(description, stderr);
		}
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
				glfwSetWindowShouldClose(window, GL_TRUE);
		}
	public:
		int IsWindowClose()
		{
			return glfwWindowShouldClose(window);
		}
	public:
		void Initialize() 
		{
			glfwSetErrorCallback(error_callback);
			if (!glfwInit())
				exit(EXIT_FAILURE);
			window = glfwCreateWindow(800, 800, "Simple example", NULL, NULL);
			if (!window)
			{
				glfwTerminate();
				exit(EXIT_FAILURE);
			}
			glfwMakeContextCurrent(window);
			glfwSetKeyCallback(window, key_callback);
		}
		void Release()
		{
			glfwDestroyWindow(window);
			glfwTerminate();
			exit(EXIT_SUCCESS);
		}

		void DrawSquare(double x, double y, double size, Color color)
		{
			glPointSize(10);
			glBegin(GL_TRIANGLES);
			glColor3f(color.r, color.g, color.b);
			glVertex2d(x - size, y - size);
			glVertex2d(x - size, y + size);
			glVertex2d(x + size, y + size);
			glEnd();

			glBegin(GL_TRIANGLES);
			glColor3f(color.r, color.g, color.b);
			glVertex2d(x + size, y - size);
			glVertex2d(x + size, y + size);
			glVertex2d(x - size, y - size);
			glEnd();
		}
		void DrawTriangle(double x, double y, double size, Color color)
		{
			glPointSize(10);
			glBegin(GL_TRIANGLES);
			glColor3f(color.r, color.g, color.b);
			glVertex2d(x - size, y);
			glVertex2d(x + size, y + size);
			glVertex2d(x + size, y - size);
			glEnd();
		}
		////////////////////////////
		void RenderStart()
		{
			glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		}
		void RenderEnd()
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

	};
}