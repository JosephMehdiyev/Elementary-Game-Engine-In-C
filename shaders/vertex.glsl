#version 460 core
layout (location = 0) in vec3 position;
layout (location = 2) in vec2 texturePosition;

out vec2 textureCoord;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;


void main()
{
    gl_Position = projection * view  * transform * vec4(position, 1.0);
    textureCoord = vec2(texturePosition.x, texturePosition.y); // texture is 2D
}