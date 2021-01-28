#pragma once

#include <cstdint>
#include <facade/Controller.hpp>
#include <Motor/Irrlicht/irrlicht.hpp>

struct irrlichtGraphics : public Controller_t{
    irrlichtGraphics(){};
    virtual ~irrlichtGraphics();
    //Funciones para el motor de Irrlicht
    void createWindow(uint32_t , uint32_t) override;
    void beginScene() override;
    void renderEntities() override;
    bool run() override;
    void endScene() override;
    void renderInit() override;
    void physicsInit() override;
    void physicsUpdate() override;
    void cameraTrack() override;
    void cameraUpdate() override;
    void createEntities(VecEntities_t const&) override;
    void renderScene() override;

private:
    Irrlicht_t irr;
};
