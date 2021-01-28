#pragma once

#include <facade/RavenGraphics.hpp>

struct ControllerMan;

struct PhysicsSystem_t
{
    PhysicsSystem_t(ControllerMan&);
    void physicsInit() const;
    void physicsUpdate() const;

private:
ControllerMan& rginterfaz;

}; //PhysicsSystem
