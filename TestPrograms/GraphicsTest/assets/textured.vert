#version 450

layout(location = 0) in vec2 i_position;
layout(location = 1) in vec2 i_uv;

layout(location = 0) out vec2 o_uv;

layout(binding = 0, std140) uniform u_block1
{
    vec4 u_color;
};

void main()
{
    gl_Position = vec4(i_position, 0.5f, 1.0f);
    o_uv = i_uv;
}