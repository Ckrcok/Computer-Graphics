#pragma once
#include "Matrix.h"
using namespace MATH;
#include "Actor.h"
#include "Trackball.h"
#include "Skybox.h"

class Camera : public Actor{
private:

	Matrix4 projectionMatrix;
	Matrix4 viewMatrix;
	Matrix4 rotationMatrix;
	Matrix4 translationMatrix;
	Trackball* trackball;
	Skybox* skybox;
public:
	Camera(Actor* parent_);
	~Camera();
	bool OnCreate();
	Matrix4 GetProjectionMatrix() { return projectionMatrix; }
	Matrix4 GetViewMatrix() { return viewMatrix; }
	void HandleEvents(const SDL_Event& sdlEvent);
	void Render() const;

};

