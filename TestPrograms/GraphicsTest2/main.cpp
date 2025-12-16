#include "TeaPacket/Assets/ReadAsset.hpp"
#include "TeaPacket/Graphics/Graphics.hpp"

#include "TeaPacket/System/System.hpp"
#include "TeaPacket/Graphics/Display.hpp"
#include "TeaPacket/Graphics/DisplayParameters.hpp"

#include "TeaPacket/Graphics/Mesh/Mesh.hpp"
#include "TeaPacket/Graphics/Mesh/MeshParameters.hpp"
#include "TeaPacket/Graphics/Shader/Shader.hpp"
#include "TeaPacket/Graphics/Shader/ShaderParameters.hpp"
#include "TeaPacket/Graphics/Shader/ShaderVariable.hpp"
#include "TeaPacket/Logging/Logging.hpp"
#include "TeaPacket/Types/Enums/PrimitiveTypes.hpp"

namespace TeaPacket::Graphics
{
    struct ShaderVariableType;
}

using namespace TeaPacket;
using namespace TeaPacket::Graphics;

constexpr float vertData[] = {
    -1.0f, 1.0f,
     1.0f, 1.0f,
    -1.0f,-1.0f,
     1.0f,-1.0f
};

unsigned long faceData[] = {
    0, 1, 2,
    1, 3, 2
};

int main()
{
    TeaPacket::Initialize();

    auto dispParams = DisplayParameters{.width = 1280, .height = 720};
    Display::InitializeDefaultDisplays({dispParams});

    auto vertInfo = std::vector<VertexDataInfo>(1);
    vertInfo[0].size = 2;
    vertInfo[0].type = PrimitiveType::Float;
    //vertInfo[1].size = 2;
    //vertInfo[1].type = PrimitiveType::Float;
    
    const auto meshParms = MeshParameters{
        .flags = MeshFlags{.useIndices = true},
        .vertexData = BorrowedFixedArray((void*)vertData, sizeof(vertData)),
        .vertexInfo = vertInfo,
        .indices = BorrowedFixedArray(faceData, std::size(faceData))
    };
    auto mesh = Mesh(meshParms);

    auto inputAttrs = std::vector<ShaderVariableType>(1);
    inputAttrs[0].baseType = ShaderVariableBaseType::Float;
    inputAttrs[0].amount = 2;
    //inputAttrs[1].baseType = ShaderVariableBaseType::Float;
    //inputAttrs[1].amount = 2;
    
    const auto shaderParms = ShaderParameters{
        .flags = {},
        .vertexShaderCode = Assets::ReadTextFile("test.vert"),
        .fragmentShaderCode = Assets::ReadTextFile("test.frag"),
        .inputAttributes = inputAttrs,
        .uniformBufferSizes = {16}
    };
    auto shader = Shader(shaderParms);

    while (System::ShouldRun())
    {
        System::ProcessSystem();
        Display::WaitForVSync();
        static uint16_t number = 0;
        number = (number + 1) % 255;
        
        Display::BeginRender(0);
        Viewport::ClearColor(0, 0, 0);
        mesh.SetActive();
        shader.SetActive();
        DrawMesh();//
        Display::FinishRender(0);
        Display::BeginRender(1);
        Viewport::ClearColor(static_cast<unsigned char>(number), 0, 0);
        Display::FinishRender(1);
        Display::PresentAll();
    }
    
    TeaPacket::DeInitialize();
}