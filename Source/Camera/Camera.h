#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <chrono>
#include <thread>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "../Shader/Shader.h"
#include "../World/Mesh.h"

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 Model;
	glm::mat4 View;
	glm::mat4 Projection;

	glm::mat4 CameraMatrix = glm::mat4(1.0f);

	float Yaw = -90.0f;
	float Pitch = 0.0f;

	bool click = true;
	bool wireframe = false;

	int width;
	int height;

	float speed;
	const float Speed = 10.0f;
	const float SprintSpeed = 2.5f;
	float deltaTime = 0.0f;
	float sensitivity = 100.0f;

	float previousFrame = 0.0f;
	int framerate = 0;
	double fps;

	double lastToggleTime = 0.0;
	const double toggleDelay = 0.2;

	Camera(GLFWwindow* window, int width, int height, glm::vec3 position);
	void Update(GLFWwindow* window, float FOVdegree, float nearPlane, float farPlane);
	void Matrix(const Shader& Shader, const char* uniform);
	void Input(GLFWwindow* window);
	void Wireframe();
	void Framerate();
	~Camera() = default;
};

#endif
