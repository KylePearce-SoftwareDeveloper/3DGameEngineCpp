#include "common.glh"

varying vec2 texCoord0;

#if defined(VS_BUILD)
attribute vec4 vertex;

uniform mat4 T_MVP;

void main()
{
    gl_Position = T_MVP * vec4(vertex.xy, 0.0, 1.0);
    texCoord0 = vertex.zw;
} 

#elif defined(FS_BUILD)

uniform sampler2D H_text;
uniform vec3 H_textColor;

DeclareFragOutput(0, vec4);
void main()
{    
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(H_text, texCoord0).r);
    vec4 color = vec4(H_textColor, 1.0) * sampled;
	SetFragOutput(0, color);
}  
#endif