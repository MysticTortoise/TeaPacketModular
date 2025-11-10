static float4 o_color;

struct SPIRV_Cross_Input {};

struct SPIRV_Cross_Output{
    float4 o_color : SV_Target0;
};

void frag_main()
{
    o_color = float4(0.0,0.0,1.0,1.0);
}

SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
{
    frag_main();
    SPIRV_Cross_Output stage_output;
    stage_output.o_color = o_color;
    return stage_output;
}