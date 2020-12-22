
#ifndef Collision_hpp_
#define Collision_hpp_

#include <irrlicht.h>
#include <iostream>
#include <vector>

class Collision{
private: 
public:
    Collision();
    bool checkCollision(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, irr::scene::ISceneNode* two);
    void createCollisionMoving(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, irr::scene::ISceneNode* two);
    bool checkCollisionCollideables(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> collideables); 
    //bool checkCollisionWalls(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p);
    //bool checkCollisionWallsAnim(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p);
    bool checkCollisionEnemies(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p);
    bool checkCollisionOneEnemy(irr::scene::ISceneNode* one, irr::scene::ISceneNode* enemy);
    bool checkCollisionObject(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* cube_player, irr::scene::ISceneNode* object);
    bool checkCollisionEspada(irr::scene::ISceneNode* sword, irr::scene::ISceneNode* enemy, int direction);
    bool checkPressedButton(irr::scene::ISceneNode* draggable, std::vector<irr::scene::ISceneNode*> buttons);
    bool checkCollisionBomba(irr::scene::ISceneNode* bomba, irr::scene::ISceneNode* enemy);
    bool checkCollisionPlayerBomb(irr::scene::ISceneNode* bomba, irr::scene::ISceneNode* cube_player);
    bool collisionUpdate();
};

#endif 