#pragma once
#include <cstdint> 

#include <Motor/MotorRaven/ravenMotor.hpp>
#include <util/typealias.hpp>
#include <facade/Controller.hpp>

struct RavenGraphics : public Controller_t{
    RavenGraphics(){};
    virtual ~RavenGraphics();
    //Funciones para el motor de Irrlicht
    void createWindow(uint32_t , uint32_t)  override;
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
ravenMotor rm;
}; //facade RavenGraphics

