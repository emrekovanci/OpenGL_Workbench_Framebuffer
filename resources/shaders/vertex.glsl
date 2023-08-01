#version 330 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 vertexTexCoord;

out vec3 VertexColor;
out vec2 VertexTexCoord;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

void main()
{
    VertexColor = vertexColor;
    VertexTexCoord = vertexTexCoord;

    gl_Position = Projection * View * Model * vec4(vertexPosition, 1.0);
}