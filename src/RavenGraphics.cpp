#include "RavenGraphics.hpp"


RavenGraphics::RavenGraphics(){
	device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
            false, false, false, &receiver);
    
    if(device){
    	device->setWindowCaption(L"SoulMirror");
    	driver = device->getVideoDriver();
    	smgr = device->getSceneManager();
    	guienv = device->getGUIEnvironment();
    	mesh = smgr->getMesh("media/cofre.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
		cube = smgr->addCubeSceneNode();
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
		 core::vector3df cubePosition = cube->getPosition();

        if(receiver.IsKeyDown(irr::KEY_KEY_W))
            cubePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
        else if(receiver.IsKeyDown(irr::KEY_KEY_S))
            cubePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;

        if(receiver.IsKeyDown(irr::KEY_KEY_A))
            cubePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
        else if(receiver.IsKeyDown(irr::KEY_KEY_D))
            cubePosition.X += MOVEMENT_SPEED * frameDeltaTime;

        cube->setPosition(cubePosition);
        
		driver->beginScene(true, true, SColor(100,20,101,140));

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

	cube->setPosition(core::vector3df(10,0,0));
    cube->setMaterialTexture(0, driver->getTexture("media/wall.bmp"));
    cube->setMaterialFlag(video::EMF_LIGHTING, false);
}

void RavenGraphics::addCamera(){
	smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
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