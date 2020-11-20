#ifndef RavenGraphics_hpp_
#define RavenGraphics_hpp_

#include <irrlicht.h>
#include <iostream>
#include "MyEventReceiver.hpp"
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
<<<<<<< HEAD
	ICameraSceneNode *camera;
=======
	ISceneNode *cube_second;
	ICameraSceneNode *scamera;
>>>>>>> 71dbc5389b39db357c11a087ba42b51ae42bf487
	MyEventReceiver receiver;
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
	bool collision(ISceneNode* sn1, ISceneNode* sn2);
	IrrlichtDevice* getDevice();
	IAnimatedMesh* getMesh();
	IAnimatedMeshSceneNode* getNode();
	ISceneNode* getCube();
};

#endif
