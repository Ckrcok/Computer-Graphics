#ifndef SCENE3_H
#define SCENE3_H
#include "Scene.h"
#include "Vector.h"
#include "Matrix.h"

using namespace MATH;

/// Forward declarations 
union SDL_Event;
class Actor;
class Mesh;
class Shader;
class Texture;
class Camera;

class Scene3 : public Scene {
private:
	Actor* skull;
	Actor* LEye;
	Actor* REye;
	Shader* shader;
	Camera*	camera;
	Vec3 lightPos[2];
public:
	explicit Scene3();
	virtual ~Scene3() override;

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event& sdlEvent) override;
};


#endif // SCENE0_H