#version 330 core

in vec2 VertexTexCoord;
out vec4 FragmentColor;

uniform sampler2D ScreenTexture;

const float offset = 1.0 / 300.0;

const vec2 offsets[9] = vec2[]
(
	vec2(-offset, offset),
	vec2(0.0, offset),
	vec2(offset, offset),
	vec2(-offset, 0.0),
	vec2(0.0, 0.0),
	vec2(offset, 0.0),
	vec2(-offset, -offset),
	vec2(0.0, -offset),
	vec2(offset, -offset)
);

const float kernel[9] = float[]
(
    1, 1, 1,
    1, -8, 1,
    1, 1, 1
);

void main()
{
	vec3 samples[9];
	for (int i = 0; i < 9; ++i)
	{
		samples[i] = vec3(texture(ScreenTexture, VertexTexCoord.st + offsets[i]));
	}

	vec3 color = vec3(0.0);
	for (int i = 0; i < 9; ++i)
	{
		color += samples[i] * kernel[i];
	}

	FragmentColor = vec4(color, 1.0);
}