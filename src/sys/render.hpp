#pragma once

#include <cstdint>

struct ControllerMan;

struct RenderSystem_t
{
    RenderSystem_t(ControllerMan& ,uint32_t,uint32_t);
    void renderInit() const;
    void renderUpdate() const;
    bool getRun() const;
private:

ControllerMan& rginterfaz;
const uint32_t w {0};
const uint32_t h {0};
};  //RenderSystem_t
