#include <sys/render.hpp>
#include <facade/RavenGraphics.hpp>
#include <facade/ControllerMan.hpp>
//Esto es para quitarlo hay pq incluye enn include del Irrlicht ver lo de Fran

RenderSystem_t::RenderSystem_t(ControllerMan& r,uint32_t m_w,uint32_t m_h)
: rginterfaz{r},w{m_w},h{m_h} {}

void RenderSystem_t::renderInit() const {
    rginterfaz.p().controller().createWindow(w,h);
    rginterfaz.p().controller().renderInit();
}

void RenderSystem_t::renderUpdate() const{
    rginterfaz.p().controller().renderScene();
}

bool RenderSystem_t::getRun() const{
    return rginterfaz.p().controller().run();
}