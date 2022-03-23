#include <glew.h>
#include <iostream>
#include <SDL.h>
#include "Debug.h"
#include "Scene4.h"
#include "MMath.h"
#include "Debug.h"
#include "Actor.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include <math.h>
#include "Camera.h"



Scene4::Scene4() :sphere(nullptr), shader{ nullptr }, camera(nullptr), LEye(nullptr) {
	camera = new Camera(nullptr);
	camera->OnCreate();
	Debug::Info("Created Scene4: ", __FILE__, __LINE__);
}

Scene4::~Scene4() {
	Debug::Info("Deleted Scene4: ", "Scene4.cpp", __LINE__);
	if (camera) delete camera;
}

bool Scene4::OnCreate() {
	Debug::Info("Loading assets Scene4: ", __FILE__, __LINE__);
	sphere = new Actor(nullptr);
	sphere->OnCreate();

	sphere->SetMesh(new Mesh(nullptr, "meshes/Sphere.obj")) ;
	sphere->GetMesh()->OnCreate();

	shader = new Shader(nullptr, "shaders/defaultVert.glsl", "shaders/defaultFrag.glsl");
	shader->OnCreate();

	if (shader->OnCreate() == false) {std::cout << "Shader Failed..";}

	return true;
}

void Scene4::OnDestroy() {
	Debug::Info("Deleting assets Scene4: ", __FILE__, __LINE__);

	if (sphere)
	{
		sphere->OnDestroy();
		delete sphere;
	}

	if (shader)
	{
		shader->OnDestroy();
		delete shader;
	}


}

void Scene4::HandleEvents(const SDL_Event& sdlEvent) {
	camera->HandleEvents(sdlEvent);

	switch (sdlEvent.type) {
	case SDL_KEYDOWN:
		if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_LEFT) {

			sphere->SetModelMatrix(sphere->GetModelMatrix() *= MMath::rotate(1.0f, Vec3(0.0f, 1.0f, 0.0f)));

		}
		else if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_RIGHT) {

			sphere->SetModelMatrix(sphere->GetModelMatrix() *= MMath::rotate(-1.0f, Vec3(0.0f, 1.0f, 0.0f)));

		}
		else if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_UP) {

			sphere->SetModelMatrix(sphere->GetModelMatrix() *= MMath::rotate(-1.0f, Vec3(1.0f, 0.0f, 0.0f)));

		}
		else if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_DOWN) {

			sphere->SetModelMatrix(sphere->GetModelMatrix() *= MMath::rotate(1.0f, Vec3(1.0f, 0.0f, 0.0f)));

		}
		break;

	case SDL_MOUSEMOTION: {
						int x, y;
						SDL_GetGlobalMouseState(&x, &y);

						break;
	}
		case SDL_MOUSEBUTTONDOWN:
			int InitX;
			int InitY;
			SDL_GetGlobalMouseState(&InitX, &InitY);

			break;

		case SDL_MOUSEBUTTONUP:
			int LastX;
			int LastY;
			SDL_GetGlobalMouseState(&LastX, &LastY);

			break;

		default:
			break;
		}
}

void Scene4::Update(const float deltaTime) {

}

void Scene4::Render() const {
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	camera->Render();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glUseProgram(shader->GetProgram());
	glUniformMatrix4fv(shader->GetUniformID("projectionMatrix"), 1, GL_FALSE, camera->GetProjectionMatrix());
	glUniformMatrix4fv(shader->GetUniformID("viewMatrix"), 1, GL_FALSE, camera->GetViewMatrix());


	glUniformMatrix4fv(shader->GetUniformID("modelMatrix"), 1, GL_FALSE, sphere->GetModelMatrix());
	sphere->GetMesh()->Render(GL_TRIANGLES);
	glUseProgram(0);
}




