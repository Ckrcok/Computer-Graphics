#include <glew.h>
#include <iostream>
#include <SDL.h>
#include "Debug.h"
#include "Scene1.h"
#include "MMath.h"
#include "Debug.h"
#include "Actor.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

Scene1::Scene1() :sphere(nullptr), shader{ nullptr }, mesh{nullptr}  {
	Debug::Info("Created Scene1: ", __FILE__, __LINE__);
}

Scene1::~Scene1() {
	Debug::Info("Deleted Scene1: ", __FILE__, __LINE__);
}

bool Scene1::OnCreate() {
	Debug::Info("Loading assets Scene1: ", __FILE__, __LINE__);
	sphere = new Actor(nullptr);
	sphere->OnCreate();

	mesh = new Mesh(nullptr, "meshes/Mario.obj");
	mesh->OnCreate();

	shader = new Shader(nullptr, "shaders/multiLightVert.glsl", "shaders/multiLightFrag.glsl");
	shader->OnCreate();
	if (shader->OnCreate() == false){
		std::cout << "Shader Failed..";
	}

	texture = new Texture();
	texture->LoadImage("textures/mario_main.png");

	projectionMatrix = MMath::perspective(45.0f, (16.0f/9.0f), 0.5f, 100.f );
	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 5.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
	modelMatrix.loadIdentity();
	lightPos0 = Vec3(10.0f, 0.0f, 0.0f);
	lightPos1 = Vec3(-10.0f, 0.0f, 0.0f);
	return true;
}

void Scene1::OnDestroy() {
	Debug::Info("Deleting assets Scene1: ", __FILE__, __LINE__);

	sphere->OnDestroy();
	delete sphere;

	shader->OnDestroy();
	delete shader;

	mesh->OnDestroy();
	delete mesh;

}

void Scene1::HandleEvents(const SDL_Event &sdlEvent) {
	switch( sdlEvent.type ) {
    case SDL_KEYDOWN:
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

void Scene1::Update(const float deltaTime) {
	static float time = 0;
	time += deltaTime;

	if (time > 5) {
		Physics::applyForce(Vec3(500000), 0, 0, *ship);
		Physics::applyTorque(Vec3(500000), 0, 0, *ship);
	}

	if (time >= 5 && time <= 35) {
		Pyhsics::applyForce(Vec3(0, 0, 0), *ship);
		Pyhsics::applyTorque(0, *ship);
	}

	Vec3 force(0.0f, 0.0f, 0.0f);
	force.x = ship->getForce().x * cos(ship->getAngle()) - ship->getForce().y * sin(ship->getAngle());
	force.y = ship->getForce().x * sin(ship->getAngle()) + ship->getForce().y * cos(ship->getAngle());

	Pyhsics::simpleNewtonMoption(*ship, deltaTime);
	cout << time << endl;
}

void Scene1::Render() const {
	glEnable(GL_DEPTH_TEST);
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader->GetProgram());
	glUniformMatrix4fv(shader->GetUniformID("projectionMatrix"), 1, GL_FALSE, projectionMatrix);
	glUniformMatrix4fv(shader->GetUniformID("viewMatrix"), 1, GL_FALSE, viewMatrix);
	glUniformMatrix4fv(shader->GetUniformID("modelMatrix"), 1, GL_FALSE, modelMatrix);
	glUniform3fv(shader->GetUniformID("lightPos0"), 1, lightPos0);


	glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
	mesh->Render(GL_TRIANGLES);
	glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
	glUseProgram(0);
}
