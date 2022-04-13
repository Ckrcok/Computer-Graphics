#ifndef Scene4_H
#define Scene4_H
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

class Scene4 : public Scene {
private:
	Actor* sphere;
	Actor* LEye;
	Actor* REye;
	Shader* shader;
	Camera*	camera;

public:
	explicit Scene4();
	virtual ~Scene4() override;

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event& sdlEvent) override;
};


#endif // SCENE0_H