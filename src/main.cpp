
#include <RavenGraphics.hpp>
#include <man/entitymanager.hpp>



    int main(){
        EntityManager_t EntityMan;
        EntityMan.createEntity(15,0,-10);
        
        
        RavenGraphics rgraphics{EntityMan};
        
        bool dev = rgraphics.getDevice();
        //bool mes = rgraphics.getMesh();
        //rgraphics.addTextGUI();

        if(!dev){
            return 1;
        }
        
        bool cube = rgraphics.getCube();
        bool node = rgraphics.getNode();
        if(cube && node){
            rgraphics.NodeLoadMaterial();
        }
        //rgraphics.addCamera();
        rgraphics.run();
        rgraphics.drop();
        return 0;
    }
