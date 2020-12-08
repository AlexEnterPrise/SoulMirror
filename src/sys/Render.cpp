#include "Render.hpp"
#include "RavenGraphics.hpp"

Render::Render(uint32_t w,uint32_t h,EntityManager_t& em,RavenGraphics& ravengraphcs)
  : m_w{w},m_h{h},m_entMan{em},rgphraics{ravengraphcs}
{
    rgphraics.openWindow(w,h);
}


void Render::draw(scene::ISceneManager* smgr, IGUIEnvironment *guienv){
    smgr->drawAll();
    guienv->drawAll();
}

