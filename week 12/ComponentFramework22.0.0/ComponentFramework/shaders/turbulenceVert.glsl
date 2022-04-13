#version 450
#extension GL_ARB_separate_shader_objects : enable


    layout(location = 0) in vec4 vVertex;
    layout(location = 1) in vec4 vNormal;


    out vec3 vertNormal;
    out vec3 vertDir;


    uniform mat4 projectionMatrix;
    uniform mat4 viewMatrix;
    uniform mat4 modelMatrix;
    uniform mat3 normalMatrix;
    uniform float totalTime;
    uniform vec3 offset;
    uniform sampler3D noiseTexture;

void main() {
    vertNormal = normalMatrix * vNormal.xyz;
    vec3 vertPos = vec3(modelMatrix * vVertex);
    vertDir = normalize(vertPos);
    vec3 vertex = vec3(vVertex);
    vec4 noiseVec = texture(noiseTexture, (vertex * 0.4) + (0.25 * offset));
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * (vVertex + noiseVec);
}