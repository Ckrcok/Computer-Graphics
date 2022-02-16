#include <glew.h>
#include <iostream>
#include <SDL.h>
#include "Debug.h"
#include "Scene2.h"
#include "MMath.h"
#include "Debug.h"
#include "Actor.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

Scene2::Scene2() :skull(nullptr), shader{ nullptr } {
	Debug::Info("Created Scene2: ", __FILE__, __LINE__);
}

Scene2::~Scene2() {
	Debug::Info("Deleted Scene2: ", "Scene2.cpp", __LINE__);
	// it dies here
}

bool Scene2::OnCreate() {
	Debug::Info("Loading assets Scene2: ", __FILE__, __LINE__);
	skull = new Actor(nullptr);
	skull->OnCreate();
	
	skull->SetMesh(new Mesh(nullptr, "meshes/Skull.obj")) ;
	skull->GetMesh()->OnCreate();

	shader = new Shader(nullptr, "shaders/multiLightVert.glsl", "shaders/multiLightFrag.glsl");
	shader->OnCreate();
	if (shader->OnCreate() == false) {
		std::cout << "Shader Failed..";
	}

	skull->SetTexture(new Texture());
	skull->GetTexture()->LoadImage("textures/skull_texture.jpg");


	projectionMatrix = MMath::perspective(45.0f, (16.0f / 9.0f), 0.5f, 100.f);
	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
	//modelMatrix.loadIdentity();
	lightPos[0] = Vec3(-10.0f, 0.0f, -5.0f);
	lightPos[1] = Vec3(10.0f, 0.0f, -5.0f);
	return true;
}

void Scene2::OnDestroy() {
	Debug::Info("Deleting assets Scene2: ", __FILE__, __LINE__);

	if (skull)
	{
		skull->OnDestroy();
		delete skull;
	}

	if (shader)
	{
		shader->OnDestroy();
		delete shader;
	}


}

void Scene2::HandleEvents(const SDL_Event& sdlEvent) {
	switch (sdlEvent.type) {
		case SDL_KEYDOWN:
			if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_LEFT){
				
				skull->GetModelMatrix() *= MMath::rotate(1.0f, Vec3(0.0f, 1.0f, 0.0f));

			}else if(sdlEvent.key.keysym.scancode == SDL_SCANCODE_RIGHT){

				skull->GetModelMatrix() *= MMath::rotate(-1.0f, Vec3(0.0f, 1.0f, 0.0f));

			}else if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_UP) {

				skull->GetModelMatrix() *= MMath::rotate(-1.0f, Vec3(1.0f, 0.0f, 0.0f));

			}
			else if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_DOWN) {

				skull->GetModelMatrix() *= MMath::rotate(1.0f, Vec3(1.0f, 0.0f, 0.0f));

			}
			break;

		case SDL_MOUSEMOTION:
			break;

		case SDL_MOUSEBUTTONDOWN:
			break;

		case SDL_MOUSEBUTTONUP:
			break;

		default:
			break;
		}
}

void Scene2::Update(const float deltaTime) {

}

void Scene2::Render() const {
	glEnable(GL_DEPTH_TEST);
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader->GetProgram());
	glUniformMatrix4fv(shader->GetUniformID("projectionMatrix"), 1, GL_FALSE, projectionMatrix);
	glUniformMatrix4fv(shader->GetUniformID("viewMatrix"), 1, GL_FALSE, viewMatrix);
	glUniform3fv(shader->GetUniformID("lightPos[0]"), 2, lightPos[0]);
	

	glBindTexture(GL_TEXTURE_2D, skull->GetTexture()->getTextureID());
	glUniformMatrix4fv(shader->GetUniformID("modelMatrix"), 1, GL_FALSE, skull->GetModelMatrix());
	skull->GetMesh()->Render(GL_TRIANGLES);
	glBindTexture(GL_TEXTURE_2D, 0);


	glUseProgram(0);
}




