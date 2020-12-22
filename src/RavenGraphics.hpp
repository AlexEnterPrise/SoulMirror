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

	// Vectores de objetos
	std::vector<irr::scene::ISceneNode*> collideables; // Array para toos los objetos con colisión
	std::vector<irr::scene::ISceneNode*> enemies;
	std::vector<irr::scene::ISceneNode*> barriles;
	std::vector<irr::scene::ISceneNode*> draggables;
	std::vector<irr::scene::ISceneNode*> buttons;
	// Vector de zonas a las que se puede dirigir
	std::vector<irr::scene::ISceneNode*> zones;
	// Vector de nombres para rellenar los vectores al cargar un nivel
	std::vector<std::string> names;
	//std::vector<irr::scene::ISceneNode*> npc;

	irr::scene::ICameraSceneNode *camera;
	irr::scene::ICameraSceneNode *scamera;
	irr::gui::IGUIButton *btn;
    irr::gui::IGUIWindow* win;
	irr::scene::ISceneNodeAnimator *anim;
	//irr::core::vector3df save_pos;
	// Creamos el array de posiciones para la animación
    //irr::core::array<irr::core::vector3df> points;

	Render render;
	Collision collider;
	Input input;

	int zone;			// Número para conocer la zona en la que nos encontramos
	bool SwitchCam;
	bool colisiona;
	int  hit_points;	// Puntos de salud (HP) del jugador
	// ---------------------------------------------------------
	int  direction;		// 1 --> derecha; 2 --> izquierda; 3 --> arriba; 4 --> abajo; 
	int throw_direction;// 5 --> derecha-arriba; 6 --> izquierda-arribs; 7 --> derecha-abajo; 8 --> izquierda-abajo;
	// --------------------------------------------------------- 
	int weapon;			// 0 --> Sin arma; 1 --> espada; 2 --> escudo; 3 --> arco; 4 --> bomba; 5 --> pociones;
	// ---------------------------------------------------------
	int shield;			// 0 --> Sin proteger; 1 --> Proteger;
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
	bool potion_gotcha;

public:
	RavenGraphics();
	void run();
	void drop();
	void fillVectors();
	void drawZone(const char* z, int pos_object);
	void comproveHP(irr::core::vector3df cubePosition, bool colBomba);
	void beginScene();
	void endScene();
	void NodeLoadMaterial();
	void addCamera();

	irr::IrrlichtDevice* getDevice();
	irr::scene::IAnimatedMesh* getMesh();
	irr::scene::IAnimatedMeshSceneNode* getNode();
	irr::scene::ISceneNode* getCube();
};

#endif
