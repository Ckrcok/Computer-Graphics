#include "Camera.h"
#include "MMath.h"
using namespace MATH;

Camera::Camera(Actor* parent_):Actor(parent_) {
	trackball = new Trackball();
	projectionMatrix = MMath::perspective(45.0f, 16.0f / 9.0f, 0.5f, 100.0f);
	translationMatrix = MMath::translate(Vec3(0.0f, 0.0f, -10.0f));
	rotationMatrix = MMath::rotate(0.0f, Vec3(0.0f, 1.0f, 0.0f));
	viewMatrix = rotationMatrix * translationMatrix;

}

Camera::~Camera()
{
	if (trackball) delete trackball;
}

void Camera::HandleEvents(const SDL_Event& sdlEvent){
	trackball->HandleEvents(sdlEvent);
	rotationMatrix = trackball->getMatrix4();
	viewMatrix = rotationMatrix * translationMatrix;
}
