
#ifndef collision_hpp_
#define collision_hpp_

#include <irrlicht.h>
using namespace irr;
using namespace core;

class collision{
private: 
public:
    collision();
    bool checkCollision(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two);

};

#endif 