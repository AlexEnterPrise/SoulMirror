#ifndef RavenGraphics_hpp_
#define RavenGraphics_hpp_

#include <irrlicht.h>
#include <iostream>
#include "sys/collision.hpp"
#include "sys/Input.hpp"
#include "sys/Render.hpp"


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

class RavenGraphics {

private:
	IrrlichtDevice *device;
	IVideoDriver *driver;
	ISceneManager *smgr;
	IGUIEnvironment *guienv;
	IAnimatedMesh *mesh;
	IAnimatedMeshSceneNode *node;
	ISceneNode *map;
	ISceneNode *cube;
	ISceneNode *wall;
	ISceneNode* one;
	ISceneNode* two;
	ICameraSceneNode *camera;

	ISceneNode *cube_second;
	ICameraSceneNode *scamera;

	Render render;
	collision collider;
	Input input;
	bool SwitchCam;

public:
	RavenGraphics();
	void run();
	void drop();
	void escenadrawAll();
	void envirodrawAll();
	void addTextGUI();
	void beginScene();
	void endScene();
	void NodeLoadMaterial();
	void addCamera();
	IrrlichtDevice* getDevice();
	IAnimatedMesh* getMesh();
	IAnimatedMeshSceneNode* getNode();
	ISceneNode* getCube();
};

#endif
