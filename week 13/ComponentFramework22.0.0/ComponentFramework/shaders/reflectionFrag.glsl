#version 450
#extension GL_ARB_separate_shader_objects : enable

vec4 reflection();
vec4 refraction();

void main() {
	fragColor = reflection();
}

vec4 reflection(){
vec3 vReflection = reflect(vertDir, vertNormal);
vReflection.x *= -1.0;
return texture(skyboxTexture, vReflection);
}

vec4 refraction(){
vec3 vReflection = refract(-vertDir, vertNormal, 1.0/1.52);
return texture(skyboxTexture,vReflection);
}
