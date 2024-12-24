#include "Camera.h"

Camera::Camera(GLFWwindow* window, int width, int height, glm::vec3 position) : width(width), height(height), Position(position)
{
	glfwSetCursorPos(window, (width / 2), (height / 2));
}

void Camera::Update(GLFWwindow* window, float FOVdegree, float nearPlane, float farPlane)
{
	glfwGetWindowSize(window, &width, &height);

	Model = glm::mat4(1.0f);
	View = glm::mat4(1.0f);
	Projection = glm::mat4(1.0f);

	View = glm::lookAt(Position, Position + Orientation, Up);
	Projection = glm::perspective(glm::radians(FOVdegree), (float)width / height, nearPlane, farPlane);

	CameraMatrix = Projection * View * Model;
}

void Camera::Matrix(const Shader& Shader, const char* uniform)
{
	glUniformMatrix4fv(glGetUniformLocation(Shader.programID, uniform), 1, GL_FALSE, glm::value_ptr(CameraMatrix));
}

void Camera::Input(GLFWwindow* window)
{
	// Speed calculation
	this->Framerate();
	speed = this->Speed * deltaTime * (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) ? SprintSpeed : 1.0f);

	// Keyboard
	{
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			Position += speed * Orientation;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			Position += speed * -glm::normalize(glm::cross(Orientation, Up));
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			Position += speed * -Orientation;
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			Position += speed * glm::normalize(glm::cross(Orientation, Up));
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
			Position += speed * Up;
		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
			Position += speed * Up;
		if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
			Position += speed * -Up;
		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
			Position += speed * -Up;
	}

	// Mouse
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		double mouseX, mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotateX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotateY = sensitivity * (float)(mouseX - (width / 2)) / width;

		glm::vec3 orientation = glm::rotate(Orientation, glm::radians(-rotateX), glm::normalize(glm::cross(Orientation, Up)));

		if (glm::abs(glm::angle(orientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
		{
			Orientation = orientation;
		}

		Orientation = glm::rotate(Orientation, glm::radians(-rotateY), Up);

		glfwSetCursorPos(window, (width / 2), (height / 2));
	}

	// Wireframe
	{
		double currentTime = glfwGetTime();
		
		if (glfwGetKey(window, GLFW_KEY_F3) == GLFW_PRESS && currentTime - lastToggleTime > toggleDelay)
		{
			Wireframe();
			lastToggleTime = currentTime;
		}
	}
}

void Camera::Wireframe()
{
	wireframe = !wireframe;

	if (wireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	std::cout << "[Debug] Wireframe mode: " << (wireframe ? "ON" : "OFF") << std::endl;
}

void Camera::Framerate()
{
	double currentFrame = glfwGetTime();

	deltaTime = currentFrame - previousFrame;
	previousFrame = currentFrame;

	this->fps = 1.0f / deltaTime;
	
	std::cout << "[Debug] FPS: " << fps  << " (" << static_cast<int>(fps) << ")" << std::endl;
}
