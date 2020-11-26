#ifdef _MSC_VER
// We'll also define this to stop MSVC complaining about sprintf().
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

#include <irrlicht.h>
#include "Collision.hpp"

using namespace irr;


class Input : public irr::IEventReceiver
{
public:
    Input();
    // This is the one method that we have to implement
    virtual bool OnEvent(const irr::SEvent& event);
    // This is used to check whether a key is being held down
    virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;
    irr::core::vector3df comproveMovement(irr::core::vector3df pos, irr::f32 speed, irr::f32 frame, irr::scene::ISceneNode* one, irr::scene::ISceneNode* two);
    bool moveCam(bool cam, irr::scene::ISceneNode *map);
    //void printXYZ(scene::ISceneNode *);
    


private:
    // We use this array to store the current state of each key
    bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
    Collision col;
};