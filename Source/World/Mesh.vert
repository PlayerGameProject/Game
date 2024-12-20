#version 460 core

layout (location = 0) in vec3 Positions;
layout (location = 1) in vec3 Colors;
layout (location = 2) in vec2 Textures;

out vec3 Color;
out vec2 TextureCoordinate;

uniform mat4 CameraMatrix;

void main()
{
    gl_Position = CameraMatrix * vec4(Positions, 1.0f);
    Color = Colors;
    TextureCoordinate = Textures;
}
