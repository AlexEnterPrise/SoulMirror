#include "Render.hpp"
#include "RavenGraphics.hpp"

void Render::draw(scene::ISceneManager* smgr, IGUIEnvironment *guienv){
    smgr->drawAll();
    guienv->drawAll();
}

