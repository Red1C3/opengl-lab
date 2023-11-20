// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <learnopengl/shader_m.h>

import OpenGlShape;
import Drawer;

module Sample;

using namespace std;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace HelloTriangle_Ortho
{
	Drawer drawer;

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		Shader ourShader("./shaders/vs/transform-no-tex.vs", "./shaders/fs/red.fs");
		vector data{
			glm::vec3(-0.5f, -0.5f, 0.0f),
			glm::vec3(0.5f, -0.5f, 0.0f),
			glm::vec3(0.0f, 0.5f, 0.0f),
		};

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0, 0, -3)); // move the scene toward -z
		glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);

		ourShader.use();
		ourShader.setMat4("projection", projection);
		ourShader.setMat4("view", view);
		ourShader.setMat4("model", model);

		OpenGlShape triangle(data, GL_TRIANGLES);
		while (!glfwWindowShouldClose(window))
		{
			// Render
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			drawer.draw(triangle);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}
}
