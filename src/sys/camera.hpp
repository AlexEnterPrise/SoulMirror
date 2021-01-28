#pragma once

#include <cstdint>
#include <facade/RavenGraphics.hpp>

struct ControllerMan;

struct Camera_t
{
    Camera_t(ControllerMan&);
    void cameraTracking() const;
    void cameraUpdate() const;
    bool getRun() const;
private:
ControllerMan& rginterfaz;

};  //RenderSystem_t
