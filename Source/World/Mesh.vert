#version 460 core

layout (location = 0) in vec3 Positions;
layout (location = 1) in vec3 Colors;

out vec3 Color;

void main()
{
    gl_Position = vec4(Positions, 1.0f);
    Color = Colors;
}
