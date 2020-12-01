#ifndef RavenGraphics_hpp_
#define RavenGraphics_hpp_

#include <irrlicht.h>
#include <iostream>
#include <vector>
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
	irr::scene::ISceneNode *object;
	//irr::scene::ISceneNode *map;
	//irr::scene::ISceneNode *cube_player;
	//irr::scene::ISceneNode *enemy_01;
	//irr::scene::ISceneNode *enemy_02;
	//irr::scene::ISceneNode *key_01;
	//irr::scene::ISceneNode *door_01;
	//irr::scene::ISceneNode *wall;
	//irr::scene::ISceneNode *wall_2;
	irr::scene::ISceneNode* one;
	irr::scene::ISceneNode* two;
	std::vector<irr::scene::ISceneNode*> walls;
	std::vector<irr::scene::ISceneNode*> enemies;

	irr::scene::ISceneNode *cube_second;

	irr::scene::ICameraSceneNode *camera;
	irr::scene::ICameraSceneNode *scamera;
	//irr::scene::ISceneNode *sphere;

	Render render;
	Collision collider;
	Input input;

	bool SwitchCam;
	bool colisiona;
	bool died;
	bool key_gotcha;

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

	irr::IrrlichtDevice* getDevice();
	irr::scene::IAnimatedMesh* getMesh();
	irr::scene::IAnimatedMeshSceneNode* getNode();
	irr::scene::ISceneNode* getCube();
};

#endif
