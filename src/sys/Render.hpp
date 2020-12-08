#pragma once

#include <irrlicht.h>
#include <cstdint>
using namespace irr;
using namespace gui;

struct EntityManager_t;
struct RavenGraphics;

struct Render{
private: 
    const uint32_t m_w { 0 }, m_h { 0 };
    EntityManager_t& m_entMan;
    RavenGraphics& rgphraics;
public:
    explicit Render(uint32_t w, uint32_t h,EntityManager_t& m_em,RavenGraphics& rvgraphics);
    void draw(scene::ISceneManager* smgr, IGUIEnvironment *guienv);

};
