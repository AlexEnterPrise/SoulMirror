
#include <RavenGraphics.hpp>
#include <sys/Render.hpp>
#include <sys/Collision.hpp>
#include <man/entitymanager.hpp>



int main(){
        EntityManager_t EntityMan;
        EntityMan.createEntity(0,0,0);
        EntityMan.createEntity(30,0,0);
        EntityMan.createEntity(15,0,20);
        RavenGraphics rgraphics{EntityMan};
        Render renderSystem(640,480,EntityMan,rgraphics);
        rgraphics.createEntities();
        

        

        
        //bool dev = rgraphics.getDevice();
        //bool mes = rgraphics.getMesh();
        //rgraphics.addTextGUI();

        //if(!dev){
        //    return 1;
        //}
        //
        //bool cube = rgraphics.getCube();
        //bool node = rgraphics.getNode();
        //if(cube && node){
        //    rgraphics.NodeLoadMaterial();
        //}
        //rgraphics.addCamera();
        rgraphics.run();
        rgraphics.drop();
        return 0;
    }
