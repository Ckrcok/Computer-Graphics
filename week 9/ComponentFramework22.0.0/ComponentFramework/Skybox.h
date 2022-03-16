#pragma once
#include "Component.h"
#include "Mesh.h"


class Skybox: public Component{
private:
	unsigned int textureID;
	const char *posXfilename, *posYfilename, *posZfilename, *negXfilename, *negYfilename, *negZfilename;
	Mesh* mesh;
public:
	Skybox(const char *posXfilename_, const char *posYfilename_, const char *posZfilename_, const char *negXfilename_, const char *negYfilename_, const char *negZfilename_);
	~Skybox();
	 bool OnCreate() ;
	 void OnDestroy() ;
	 void Update(const float deltaTime_) ;
	 void Render()const ;
};

