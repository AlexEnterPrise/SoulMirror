#ifdef _MSC_VER
// We'll also define this to stop MSVC complaining about sprintf().
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

#include <irrlicht.h>
#include "collision.hpp"
using namespace irr;


class Input : public IEventReceiver
{
public:
    // This is the one method that we have to implement
    virtual bool OnEvent(const SEvent& event);
   
    // This is used to check whether a key is being held down
    virtual bool IsKeyDown(EKEY_CODE keyCode) const;
    core::vector3df comproveMovement(core::vector3df pos, f32 speed, f32 frame, scene::ISceneNode* one, scene::ISceneNode* two);
    bool moveCam(bool cam, scene::ISceneNode *map);
    Input();
    

private:
    // We use this array to store the current state of each key
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
    collision col;
};