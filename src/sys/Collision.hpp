
#ifndef Collision_hpp_
#define Collision_hpp_

#include <irrlicht.h>
using namespace irr;
using namespace core;

class Collision{
private: 
public:
    Collision();
    bool checkCollision(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two);

};

#endif 