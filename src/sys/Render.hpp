#ifndef render_hpp_
#define render_hpp_

#include <irrlicht.h>


class Render{
private: 
public:
    void draw(irr::scene::ISceneManager* smgr, irr::gui::IGUIEnvironment *guienv);

};
#endif