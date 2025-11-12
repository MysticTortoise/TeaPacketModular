#include "TeaPacket/Graphics/Shader/Shader.hpp"

#include <d3dcompiler.h>

#include <wrl/client.h>

#include "TeaPacket/Graphics/PlatformShader.hpp"
#include "TeaPacket/Graphics/WindowsGraphics.hpp"

#include "TeaPacket/Graphics/Shader/ShaderParameters.hpp"
#include "TeaPacket/MacroUtils/WindowsSpecific.hpp"

using namespace TeaPacket::Graphics;


static constexpr DXGI_FORMAT GetDXGIFormatFromVertexAttribute(ShaderVariableType shaderVarType)
{
    using enum ShaderVariableBaseType;
    switch (shaderVarType.amount)
    {
    case 1:
        switch (shaderVarType.baseType)
        {
    case Float:     return DXGI_FORMAT_R32_FLOAT;
    case Int:       return DXGI_FORMAT_R32_SINT;
    case UInt:      return DXGI_FORMAT_R32_UINT;
    case Texture:   return DXGI_FORMAT_UNKNOWN;
        }
    case 2:
        switch (shaderVarType.baseType)
        {
    case Float: return DXGI_FORMAT_R32G32_FLOAT;
    case Int: return DXGI_FORMAT_R32G32_SINT;
    case UInt: return DXGI_FORMAT_R32G32_UINT;
    case Texture: return DXGI_FORMAT_UNKNOWN;
        }
    case 3:
        switch (shaderVarType.baseType)
        {
    case Float: return DXGI_FORMAT_R32G32B32_FLOAT;
    case Int: return DXGI_FORMAT_R32G32B32_SINT;
    case UInt: return DXGI_FORMAT_R32G32B32_UINT;
    case Texture: return DXGI_FORMAT_UNKNOWN;
        }
    case 4:
        switch (shaderVarType.baseType)
        {
    case Float: return DXGI_FORMAT_R32G32B32A32_FLOAT;
    case Int: return DXGI_FORMAT_R32G32B32A32_SINT;
    case UInt: return DXGI_FORMAT_R32G32B32A32_UINT;
    case Texture: return DXGI_FORMAT_UNKNOWN;
        }
    }
    throw std::exception();
}

Shader::Shader(const ShaderParameters& parameters):
platformShader(std::make_unique<PlatformShader>())
{
    Microsoft::WRL::ComPtr<ID3D10Blob> errorMessage, vertexShaderBuffer;
    
    CheckErrorWinCom(D3DCompile(
        parameters.vertexShaderCode.c_str(), parameters.vertexShaderCode.length(),
        NULL, NULL, NULL,
        "main", "vs_5_0",
        D3D10_SHADER_ENABLE_STRICTNESS, 0,
        vertexShaderBuffer.GetAddressOf(), errorMessage.GetAddressOf()
        ));

    Microsoft::WRL::ComPtr<ID3D10Blob> pixelShaderBuffer;

    CheckErrorWinCom(
        D3DCompile(
            parameters.fragmentShaderCode.c_str(), parameters.fragmentShaderCode.length(),
            NULL, NULL, NULL,
            "main", "ps_5_0",
            D3D10_SHADER_ENABLE_STRICTNESS, 0,
            pixelShaderBuffer.GetAddressOf(), errorMessage.GetAddressOf()
            ));
    

    CheckErrorWinCom(
        device->CreateVertexShader(
            vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(),
            NULL, platformShader->vertexShader.GetAddressOf()
            ));

    CheckErrorWinCom(
        device->CreatePixelShader(
            pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(),
            NULL, platformShader->pixelShader.GetAddressOf()
    ));

    auto polygonLayout = FixedArray<D3D11_INPUT_ELEMENT_DESC>(parameters.inputAttributes.size);
    for (size_t i = 0; i < polygonLayout.size; i++)
    {
        polygonLayout[i].SemanticName = "TEXCOORD";
        polygonLayout[i].SemanticIndex = static_cast<unsigned int>(i);
        polygonLayout[i].Format = GetDXGIFormatFromVertexAttribute(parameters.inputAttributes[i]);
        polygonLayout[i].InputSlot = 0;
        polygonLayout[i].AlignedByteOffset = 1 == 0 ? 0 : D3D11_APPEND_ALIGNED_ELEMENT;
        polygonLayout[i].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
        polygonLayout[i].InstanceDataStepRate = 0;
    }

    CheckErrorWinCom(
        device->CreateInputLayout(polygonLayout.data, static_cast<UINT>(parameters.inputAttributes.size),
            vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(),
            platformShader->inputLayout.GetAddressOf()
            ));
}
void Shader::SetActive()
{
    deviceContext->IASetInputLayout(platformShader->inputLayout.Get());
    deviceContext->VSSetShader(platformShader->vertexShader.Get(), NULL, 0);
    deviceContext->PSSetShader(platformShader->pixelShader.Get(), NULL, 0);

    // Add Uniform support later
}

Shader::~Shader() = default;
