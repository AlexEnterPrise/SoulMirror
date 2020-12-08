#ifndef RavenGraphics_hpp_
#define RavenGraphics_hpp_

#include <irrlicht.h>
#include <iostream>
#include "sys/Collision.hpp"
#include "sys/Input.hpp"
#include "sys/Render.hpp"
#include <vector>


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

	struct EntityManager_t;

	struct RavenGraphics {
		explicit RavenGraphics(EntityManager_t& em);
	private:

		EntityManager_t& m_EntMan;
		IrrlichtDevice *device;
		IVideoDriver *driver;
		ISceneManager *smgr;
		IGUIEnvironment *guienv;
		IAnimatedMesh *mesh;
		IAnimatedMeshSceneNode *node;
		vector<ISceneNode*> nodes;
		ISceneNode *map;
		ISceneNode *cube;
		ISceneNode *wall;
		ISceneNode *wall_2;
		ISceneNode* one;
		ISceneNode* two;
		ICameraSceneNode *camera;

		ISceneNode *cube_second;
		ICameraSceneNode *scamera;

		
		Collision collider;
		Input input;
		bool SwitchCam;

	public:
		RavenGraphics();
		void openWindow(u_int32_t w,uint32_t h);
		void createEntities();
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
		IrrlichtDevice* getDevice();
		IAnimatedMesh* getMesh();
		IAnimatedMeshSceneNode* getNode();
		ISceneNode* getCube();
	};

#endif
