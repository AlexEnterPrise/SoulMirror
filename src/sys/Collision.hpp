
#ifndef Collision_hpp_
#define Collision_hpp_

#include <irrlicht.h>
#include <vector>

class Collision{
private: 
public:
    Collision();
    bool checkCollision(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, irr::scene::ISceneNode* two);
    void createCollisionMoving(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, irr::scene::ISceneNode* two);
    bool checkCollisionWalls(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p);

    bool collisionUpdate();
};

#endif 