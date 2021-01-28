#pragma once

#include <cstdint>
#include <util/typealias.hpp>

struct Controller_t
{
    virtual ~Controller_t() = default;
    virtual void createWindow(uint32_t, uint32_t) = 0;
    virtual void beginScene() = 0;
    virtual void renderEntities() = 0;
    virtual bool run() = 0;
    virtual void endScene() = 0;
    virtual void renderInit() = 0;
    virtual void physicsInit() = 0;
    virtual void physicsUpdate() = 0;
    virtual void cameraTrack() = 0;
    virtual void cameraUpdate() = 0;
    virtual void createEntities(VecEntities_t const&) = 0;
    virtual void renderScene() = 0;
};
