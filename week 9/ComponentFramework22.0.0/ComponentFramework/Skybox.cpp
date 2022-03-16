#include <glew.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Skybox.h"


Skybox::Skybox(const char* posXfilename_, const char* posYfilename_, const char* posZfilename_,
	const char* negXfilename_, const char* negYfilename_, const char* negZfilename_) :Component (nullptr){

	posXfilename = posXfilename_;
	posYfilename = posYfilename_;
	posZfilename = posZfilename_;
	negXfilename = negXfilename_;
	negYfilename = negYfilename_;
	negZfilename = negZfilename_;

}

Skybox::~Skybox(){}

bool Skybox::OnCreate() {


	mesh = new Mesh(nullptr, "meshes/Cube.obj");

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
	SDL_Surface* textureSurface;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	textureSurface = IMG_Load(posXfilename);
	if (textureSurface == nullptr) {
		return false;
	}
	int mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X,0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	//free the memory
	SDL_FreeSurface(textureSurface);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	textureSurface = IMG_Load(posYfilename);

	if (textureSurface == nullptr) {
		return false;
	}

	int mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);

	//free the memory
	SDL_FreeSurface(textureSurface);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	textureSurface = IMG_Load(posZfilename);

	if (textureSurface == nullptr) {
		return false;
	}

	int mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);

	//free the memory
	SDL_FreeSurface(textureSurface);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	textureSurface = IMG_Load(negXfilename);

	if (textureSurface == nullptr) {
		return false;
	}

	int mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);

	//free the memory
	SDL_FreeSurface(textureSurface);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	textureSurface = IMG_Load(negYfilename);

	if (textureSurface == nullptr) {
		return false;
	}

	int mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);

	//free the memory
	SDL_FreeSurface(textureSurface);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	textureSurface = IMG_Load(negZfilename);

	if (textureSurface == nullptr) {
		return false;
	}

	int mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);

	//free the memory
	SDL_FreeSurface(textureSurface);


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0); /// Unbind the texture
	return true;
}

void Skybox::OnDestroy() { glDeleteTextures(1, &textureID); }

void Skybox::Update(const float deltaTime_) {}
void Skybox::Render() const{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	mesh->Render();

}
