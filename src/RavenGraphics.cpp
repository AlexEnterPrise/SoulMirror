#include "RavenGraphics.hpp"
#include <man/entitymanager.hpp>


RavenGraphics::RavenGraphics(EntityManager_t& em) : m_EntMan{em}{
    
}

void RavenGraphics::createEntities(){
    auto& entities { m_EntMan.getEntities()};
    
    for(auto& e: entities){
        ISceneNode* b = smgr->addCubeSceneNode(10.0f,0,e.entityID,core::vector3df(e.x,e.y,e.z),core::vector3df(e.rx,e.ry,e.rz),core::vector3df(e.w,e.h,e.d));
        nodes.push_back(b);
    }
}

void RavenGraphics::openWindow(u_int32_t w,uint32_t h){
    //si es false significa que la camara es lejana, si es true pasamos a FP (primera persona)

    SwitchCam = false;

    device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(w, h), 16,
            false, false, false, &input);
    
    if(device){
       
        device->setWindowCaption(L"SoulMirror");
        driver = device->getVideoDriver();
        smgr = device->getSceneManager();
        guienv = device->getGUIEnvironment();
        device->getFileSystem()->addFileArchive("media/map-20kdm2.pk3");
        //mesh = smgr->getMesh("media/cofre.stl");
        //node = smgr->addAnimatedMeshSceneNode( mesh );
        cube = smgr->addCubeSceneNode();
        
    
        wall = smgr->addCubeSceneNode();
        wall->setScale(vector3df(1.0f,1.0f,3.0f));
        wall_2 = smgr->addCubeSceneNode();
        wall_2->setScale(vector3df(1.0f,1.0f,3.0f));
        wall_2->setPosition(vector3df(30,0,0));
        camera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
        cube_second = smgr->addCubeSceneNode();
        vector3df posCube = vector3df(15,0,20);
        cube_second->setPosition(posCube);
    }
}

void RavenGraphics::run(){
     int lastFPS = -1;

    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    u32 then = device->getTimer()->getTime();

    // This is the movemen speed in units per second.
    const f32 MOVEMENT_SPEED = 15.f;
    while(device->run())
    {
        const u32 now = device->getTimer()->getTime();
        const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
        then = now;

        vector3df cubePosition = nodes[0]->getPosition();

        //core::vector3df cubePosition = cube->getPosition();

       
        cubePosition = input.comproveMovement(cubePosition, MOVEMENT_SPEED, frameDeltaTime, nodes[0], wall);
        cubePosition = input.comproveMovement(cubePosition, MOVEMENT_SPEED, frameDeltaTime, nodes[0], wall_2);

        SwitchCam = input.moveCam(SwitchCam, map);
        nodes[0]->setPosition(cubePosition);
        
        driver->beginScene(true, true, SColor(100,20,101,140));

        addCamera();

        if(collider.checkCollision(nodes[0],cube_second) == true){
        //Colisionan
        nodes[0]->setPosition(vector3df(15,0,-10));
        cube_second->setPosition(core::vector3df(-20,0,0));
        cube_second->setMaterialTexture(0, driver->getTexture("media/wall.bmp"));
        cube_second->setMaterialFlag(video::EMF_LIGHTING, false);
       
        }

        smgr->drawAll();
        guienv->drawAll();

        driver->endScene();
         int fps = driver->getFPS();

        if (lastFPS != fps)
        {
            core::stringw tmp(L"Movement Example - Irrlicht Engine [");
            tmp += driver->getName();
            tmp += L"] fps: ";
            tmp += fps;

            device->setWindowCaption(tmp.c_str());
            lastFPS = fps;
        }
    }
}


void RavenGraphics::drop(){
    device->drop();
}

void RavenGraphics::escenadrawAll(){
  smgr->drawAll();
}

void RavenGraphics::envirodrawAll(){
  guienv->drawAll();
}

void RavenGraphics::addTextGUI(){
    guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",rect<s32>(10,10,260,22), true);
}


void RavenGraphics::endScene(){
    driver->endScene();
}

void RavenGraphics::NodeLoadMaterial(){
    //node->setMaterialFlag(EMF_LIGHTING, false);
    //node->setMD2Animation(scene::EMAT_STAND);
    //node->setMaterialTexture( 0, driver->getTexture("media/sydney.bmp"));
    //mesh = smgr->getMesh("20kdm2.bsp");
    //if(mesh)
    //    map = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);

    //if (map)
      //  map->setPosition(core::vector3df(-1300,-144,-1249));

    nodes[0]->setMaterialTexture(0, driver->getTexture("media/wall.bmp"));
    nodes[0]->setMaterialFlag(video::EMF_LIGHTING, false);
}

void RavenGraphics::addCamera(){

    //smgr->addCameraSceneNode(0, vector3df(0,30,-40), cube->getPosition());
    //ICameraSceneNode *camera = smgr->getActiveCamera();
    vector3df camaraPosition;
    camaraPosition.X = nodes[0]->getPosition().X;
    camaraPosition.Y = 30;
    camaraPosition.Z = nodes[0]->getPosition().Z - 40;
    
    if(!SwitchCam){
        camera->setPosition(camaraPosition);
        camera->setTarget(nodes[0]->getPosition());
    }
    else
        camera->setPosition(nodes[0]->getPosition());
    //camera->bindTargetAndRotation(true);
    //if(camera != NULL)
      //  cout<<"siuuu";
    //ICameraSceneNode camera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

    //scamera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

}



IrrlichtDevice* RavenGraphics::getDevice(){
    return device;
}

IAnimatedMesh* RavenGraphics::getMesh(){
    return mesh;
}

IAnimatedMeshSceneNode* RavenGraphics::getNode(){
    return node;
}

ISceneNode* RavenGraphics::getCube(){
    return cube;
}
