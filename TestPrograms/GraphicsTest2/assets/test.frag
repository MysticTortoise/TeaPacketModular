#version 450
//layout(location = 0) in vec2 i_uv;

layout(location = 0) out vec4 o_color;

//layout(binding = 0, std140) uniform u_block1
//{
//    vec4 u_color;
//};

//layout(binding = 1) uniform sampler2D u_tex;

void main()
{
    o_color = vec4(0.0,1.0,0.0,1.0);
}