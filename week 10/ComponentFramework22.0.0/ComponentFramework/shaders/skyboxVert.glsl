#version 450
#extension GL_ARB_separate_shader_objects : enable

// these are attributes
layout(location = 0) in vec4 vVertex;


layout(location = 0) uniform mat4 projectionMatrix;
layout(location = 1) uniform mat4 viewMatrix;
layout(location = 0) out vec3 texCoord;


void main() {
    texCoord = vec3(vVertex);
    gl_Position = projectionMatrix * viewMatrix *  vVertex;
}