#ifndef RavenGraphics_hpp_
#define RavenGraphics_hpp_

#include <irrlicht.h>
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
	ISceneNode *cube;
	ISceneNode *cube_second;
	ICameraSceneNode *scamera;
	MyEventReceiver receiver;

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
