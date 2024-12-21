#version 460 core

out vec4 FragColor;

in vec3 Color;
in vec2 TextureCoordinate;
in vec3 Normal;
in vec3 CurrentPosition;

uniform sampler2D Texture;
uniform vec4 LightColor;
uniform vec3 LightPosition;
uniform float LightIntensity;
uniform vec3 CameraPosition;

void main()
{
    float Ambient = 0.20f;

    vec3 normal = normalize(Normal);
    vec3 LightDirection = normalize(LightPosition - CurrentPosition);

    float Diffuse = max(dot(normal, LightDirection), 0.0f);

    float SpecularLight = 0.50f;
    vec3 ViewDirection = normalize(CameraPosition - CurrentPosition);
    vec3 ReflectionDirection = reflect(-LightDirection, normal);
    float SpecularAmount = pow(max(dot(ViewDirection, ReflectionDirection), 0.0f), 8);
    float Specular = SpecularAmount * SpecularLight;
    
    vec4 Light = LightColor * LightIntensity;

    FragColor = texture(Texture, TextureCoordinate) * Light * (Diffuse + Ambient + Specular);
}
