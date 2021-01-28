#include <facade/irrlichtGraphics.hpp>


irrlichtGraphics::~irrlichtGraphics(){
    
}
void irrlichtGraphics::createWindow(uint32_t w, uint32_t h)  {
    irr.createWindow(w,h);
}
void irrlichtGraphics::beginScene()  {

}
void irrlichtGraphics::renderEntities()  {

}
bool irrlichtGraphics::run()  {
    return irr.getDeviceRun();
}
void irrlichtGraphics::endScene()  {

}
void irrlichtGraphics::renderInit()  {
    irr.renderInit();
}
void irrlichtGraphics::physicsInit()  {
    irr.physicsInit();
}
void irrlichtGraphics::physicsUpdate()  {

}
void irrlichtGraphics::cameraTrack()  {

}
void irrlichtGraphics::cameraUpdate()  {

}
void irrlichtGraphics::createEntities(VecEntities_t const&)  {

}
void irrlichtGraphics::renderScene()  {
    irr.run();
}