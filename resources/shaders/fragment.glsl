#version 330 core

in vec3 VertexColor;
in vec2 VertexTexCoord;

out vec4 FragmentColor;

uniform sampler2D Image;

void main()
{
    FragmentColor = texture(Image, VertexTexCoord) * vec4(VertexColor, 1.0);
}