#include "Render.hpp"
#include "RavenGraphics.hpp"

void Render::draw(irr::scene::ISceneManager* smgr, irr::gui::IGUIEnvironment *guienv){
    smgr->drawAll();
    guienv->drawAll();
}

