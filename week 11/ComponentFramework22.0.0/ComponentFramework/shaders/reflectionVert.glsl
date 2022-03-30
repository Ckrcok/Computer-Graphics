#version 450
#extension GL_ARB_separate_shader_objects : enable

// these are attributes
layout(location = 0) in vec4 vVertex;
layout(location = 0) in vec3 vNormal;

layout(location = 0) uniform mat4 projectionMatrix;
layout(location = 1) uniform mat4 viewMatrix;
layout(location = 2) uniform mat4 modelMatrix;

layout(location = 0) out vec3 vertNormal;
layout(location = 1) out vec3 vertDir;

void main() {
    // rotating the shpere with the normals
    mat4 pureTotationMatrix =  transpose(inverse(modelMatrix));
    mat3 normalMatrix = mat3(pureTotationMatrix);
    vertNormal = normalMatrix * vNormal;
    vertNormal = normalize(vertNormal);

    vec3 vertPos = vec3(viewMatrix * modelMatrix * vVertex);
    vertDir = normalize(vertPos);

    gl_Position = projectionMatrix * viewMatrix* modelMatrix *  vVertex;
}