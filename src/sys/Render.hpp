#ifndef render_hpp_
#define render_hpp_

#include <irrlicht.h>
using namespace irr;
using namespace gui;


class Render{
private: 
public:
    void draw(scene::ISceneManager* smgr, IGUIEnvironment *guienv);

};
#endif