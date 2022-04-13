#ifndef SCENE2_H
#define SCENE2_H
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

class Scene2 : public Scene {
private:
	Actor* skull;
	Actor* LEye;
	Actor* REye;
	Shader* shader;

	// Camera zone
	Matrix4 projectionMatrix;
	Matrix4 viewMatrix;
	///

	Vec3 lightPos[2];
	int x, y, InitX, InitY, LastX, LastY;
public:
	explicit Scene2();
	virtual ~Scene2() override;

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event& sdlEvent) override;
};


#endif // SCENE0_H