#include <facade/RavenGraphics.hpp>
#include <sys/render.hpp>
#include <sys/physics.hpp>
#include <sys/camera.hpp>
#include <man/entityManager.hpp>
#include <iostream>
#include <facade/ControllerMan.hpp>
int main(){
    ControllerMan contrlMan;
    //RenderSystem_t render(contrlMan,640,480);
    RenderSystem_t render(contrlMan,1920,1080);
    PhysicsSystem_t physics(contrlMan);
    render.renderInit();
    physics.physicsInit();
    //render.renderUpdate();
    render.renderUpdate();
    
    
    //ControllerMan::p().controller().createWindow(640,480);
    //ControllerMan::p().controller().renderInit();
    //ControllerMan::p().controller().physicsInit();
    //ControllerMan::p().controller().renderScene();
    
    
    
    
    
      
    
    //EntityManager_t entMan;
    //RenderSystem_t render(rgraphics,640,480);
    //PhysicsSystem_t physics(rgraphics);
    //Camera_t camera(rgraphics);
    //entMan.createEntity(0,0,0);
    //entMan.createEntity(30,0,0);
    //entMan.createEntity(15,0,20);
    //render.renderInit();
    //entMan.createEntities(rgraphics);
    //physics.physicsInit();
    //while(render.getRun()){
    //    physics.physicsUpdate();
    //    camera.cameraTracking();
    //    render.renderUpdate();
    //    camera.cameraUpdate();
    //}
    
    
    return 0;
}

