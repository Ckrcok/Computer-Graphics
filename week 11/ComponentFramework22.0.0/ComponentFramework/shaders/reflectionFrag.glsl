#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 vertNormal;
layout(location = 1) in vec3 verDir;

uniform samplerCube skybox;
layout(location = 0) out vec4 fragColor;

void main() {
	fragColor =  texture(skybox, texCoord);
}