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
	//irr::scene::ISceneNode* one;
	//irr::scene::ISceneNode* two;
	std::vector<irr::scene::ISceneNode*> collideables; // Array para toos los objetos con colisión
	std::vector<irr::scene::ISceneNode*> enemies;
	std::vector<irr::scene::ISceneNode*> barriles;
	std::vector<irr::scene::ISceneNode*> draggables;
	std::vector<irr::scene::ISceneNode*> buttons;
	//std::vector<irr::scene::ISceneNode*> npc;

	irr::scene::ISceneNode *cube_second;

	irr::scene::ICameraSceneNode *camera;
	irr::scene::ICameraSceneNode *scamera;
	irr::gui::IGUIButton *btn;
    irr::gui::IGUIWindow* win;

	Render render;
	Collision collider;
	Input input;

	bool SwitchCam;
	bool colisiona;
	int  hit_points;	// Puntos de salud (HP) del jugador
	// ---------------------------------------------------------
	int  direction;		// 1 --> derecha; 2 --> izquierda; 3 --> arriba; 4 --> abajo; 
	int throw_direction;// 5 --> derecha-arriba; 6 --> izquierda-arribs; 7 --> derecha-abajo; 8 --> izquierda-abajo;
	// --------------------------------------------------------- 

	int  died; 			// 0 --> normal; 1 --> golpeado; 2 --> muerto 
	// ---------------------------------------------------------
	int catched;		// 0 --> Sin coger; 1 --> Cogido; 2 --> Lanzado; 3 --> Arrastrable cogido
	// ---------------------------------------------------------
	int bomb;			// 0 --> Sin poner; 1 --> Puesta;
	// ---------------------------------------------------------
	bool isPressed; 	// Comprobar si se sigue pulsando una tecla
	int  arrows;		// Número de flechas
	bool key_gotcha;
	bool pocion_gotcha;

public:
	RavenGraphics();
	void run();
	void drop();
	void comproveHP(irr::core::vector3df cubePosition);
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
