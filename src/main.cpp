
#include "RavenGraphics.hpp"

int main(){
    RavenGraphics rgraphics;
    
    bool dev = rgraphics.getDevice();
    //bool mes = rgraphics.getMesh();
    rgraphics.addTextGUI();

    if(!dev){
        return 1;
    }
    
    bool cube = rgraphics.getCube();
    //bool node = rgraphics.getNode();
    if(cube){
        rgraphics.NodeLoadMaterial();
    }
    rgraphics.addCamera();
    rgraphics.run();
    rgraphics.drop();
    return 0;
}
