#version 460 core

layout (location = 0) in vec3 Positions;

uniform mat4 CameraMatrix;
uniform mat4 Model;

void main()
{
    gl_Position = CameraMatrix * Model * vec4(Positions, 1.0f);
}
