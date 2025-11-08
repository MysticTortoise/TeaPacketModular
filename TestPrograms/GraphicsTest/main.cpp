#include <iostream>

#include "TeaPacket/Window/Window.hpp"
#include "TeaPacket/Graphics/Display.hpp"
#include "TeaPacket/Graphics/DisplayParameters.hpp"
#include "TeaPacket/Graphics/Graphics.hpp"
#include "TeaPacket/Graphics/Mesh/Mesh.hpp"
#include "TeaPacket/Graphics/Mesh/MeshParameters.hpp"
#include "TeaPacket/Graphics/Shader/Shader.hpp"
#include "TeaPacket/Graphics/Shader/ShaderParameters.hpp"
#include "TeaPacket/Graphics/Texture/TextureData.hpp"
#include "TeaPacket/System/System.hpp"
#include "TeaPacket/Types/Enums/PrimitiveTypes.hpp"

using namespace TeaPacket::Window;

std::string vertShader = "static float4 gl_Position;"
"static float2 i_position;"
"struct SPIRV_Cross_Input"
"{"
"    float2 i_position : TEXCOORD0;"
"};"
"struct SPIRV_Cross_Output"
"{"
"    float4 gl_Position : SV_Position;"
"};"
"void vert_main()"
"{"
"    gl_Position = float4(i_position, 0.5f, 1.0f);"
"}"
"SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)	"
"{"
"    i_position = stage_input.i_position;"
"    vert_main();"
"    SPIRV_Cross_Output stage_output;"
"    stage_output.gl_Position = gl_Position;"
"    return stage_output;"
"}";

const std::string pixelShader = "static float4 o_color;struct SPIRV_Cross_Input{};struct SPIRV_Cross_Output{    float4 o_color : SV_Target0;};void frag_main(){o_color = float4(0.0,0.0,1.0,1.0);}SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input){    frag_main();    SPIRV_Cross_Output stage_output;    stage_output.o_color = o_color;    return stage_output;}";

constexpr float vertData[] = {
    0.0f, 1.0f,
    1.0f,-1.0f,
    -1.0f,-1.0f
};

unsigned long faceData[] = {
    0, 1, 2
};

[[noreturn]] int main()
{
    TeaPacket::Graphics::Initialize();
    auto dispParams = TeaPacket::Graphics::DisplayParameters{.width = 1280, .height = 720};
    TeaPacket::Graphics::Display::InitializeDefaultDisplays({dispParams});
    TeaPacket::Graphics::Viewport* viewport = TeaPacket::Graphics::Display::GetDisplay(0)->GetViewport();

    auto vertInfo = TeaPacket::FixedArray<TeaPacket::Graphics::VertexDataInfo>(1);
    vertInfo[0].size = 2;
    vertInfo[0].type = TeaPacket::PrimitiveType::Float;
    
    const auto meshParms = TeaPacket::Graphics::MeshParameters{
        .flags = TeaPacket::Graphics::MeshFlags{.useIndices = true},
        .vertexData = TeaPacket::BorrowedFixedArray((void*)vertData, sizeof(vertData)),
        .vertexInfo = vertInfo,
        .indices = TeaPacket::BorrowedFixedArray(faceData, 3)
    };
    auto mesh = TeaPacket::Graphics::Mesh(meshParms);

    auto inputAttrs = TeaPacket::FixedArray<TeaPacket::Graphics::ShaderVariableType>(1);
    inputAttrs[0].baseType = TeaPacket::Graphics::ShaderVariableBaseType::Float;
    inputAttrs[0].amount = 2;
    auto uniform = TeaPacket::FixedArray<TeaPacket::Graphics::ShaderVariableType>(0);
    const auto shaderParms = TeaPacket::Graphics::ShaderParameters{
        .flags = {},
        .vertexShaderCode = vertShader,
        .fragmentShaderCode = pixelShader,
        .inputAttributes = inputAttrs,
        .uniforms = std::nullopt
    };
    auto shader = TeaPacket::Graphics::Shader(shaderParms);
    
    while (true)
    {
        TeaPacket::System::ProcessSystem();
        viewport->BeginRender();
        viewport->ClearColor(255, 0, 0);

        mesh.SetActive();
        shader.SetActive();
        TeaPacket::Graphics::DrawMesh();
        
        viewport->FinishRender();
        static int number = 0;
        number++;
        if (number == 0)
        {
            auto texData = viewport->GetTexture()->GetData();
            const Color rgb = texData.GetColor4(1,1);
            std::cout << static_cast<std::string>(rgb);
        }
    }
    TeaPacket::Graphics::DeInitialize();
}