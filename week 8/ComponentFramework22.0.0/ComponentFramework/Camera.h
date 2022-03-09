#pragma once
#include "Matrix.h"
using namespace MATH;
#include "Actor.h"
#include "Trackball.h"

class Camera : public Actor{
private:

	Matrix4 projectionMatrix;
	Matrix4 viewMatrix;
	Matrix4 rotationMatrix;
	Matrix4 translationMatrix;
	Trackball* trackball;

public:
	Camera(Actor* parent_);
	~Camera();
	Matrix4 GetProjectionMatrix() { return projectionMatrix; }
	Matrix4 GetViewMatrix() { return viewMatrix; }
	void HandleEvents(const SDL_Event& sdlEvent);

	// if there is skybox add sky box if there is camera add camera
};

