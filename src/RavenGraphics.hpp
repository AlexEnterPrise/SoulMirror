#ifndef RavenGraphics_hpp_
#define RavenGraphics_hpp_

#include <irrlicht.h>
#include <iostream>
#include "sys/Collision.hpp"
#include "sys/Input.hpp"
#include "sys/Render.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

class RavenGraphics {

private:
	irr::IrrlichtDevice *device;
	irr::video::IVideoDriver *driver;
	irr::scene::ISceneManager *smgr;
	irr::gui::IGUIEnvironment *guienv;
	irr::scene::IAnimatedMesh *mesh;
	irr::scene::IAnimatedMeshSceneNode *node;
	irr::scene::ISceneNode *map;
	irr::scene::ISceneNode *cube;
	irr::scene::ISceneNode *wall;
	irr::scene::ISceneNode *wall_2;
	irr::scene::ISceneNode* one;
	irr::scene::ISceneNode* two;

	irr::scene::ISceneNode *cube_second;
	irr::scene::ISceneNode *sphere;

	irr::scene::ICameraSceneNode *camera;
	irr::scene::ICameraSceneNode *scamera;

	Render render;
	Collision collider;
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
	void drawMap();
	void moveSphere(irr::f32, irr::f32);

	irr::IrrlichtDevice* getDevice();
	irr::scene::IAnimatedMesh* getMesh();
	irr::scene::IAnimatedMeshSceneNode* getNode();
	irr::scene::ISceneNode* getCube();
};

#endif
