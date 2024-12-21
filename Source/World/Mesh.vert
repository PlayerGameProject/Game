#version 460 core

layout (location = 0) in vec3 Positions;
layout (location = 1) in vec3 Colors;
layout (location = 2) in vec2 Textures;
layout (location = 3) in vec3 Normals;

out vec3 Color;
out vec2 TextureCoordinate;
out vec3 Normal;
out vec3 CurrentPosition;

uniform mat4 CameraMatrix;
uniform mat4 Model;

void main()
{
    CurrentPosition = vec3(Model * vec4(Positions, 1.0f));
    gl_Position = CameraMatrix * vec4(CurrentPosition, 1.0f);
    
    Color = Colors;
    TextureCoordinate = Textures;
    Normal = Normals;
}
