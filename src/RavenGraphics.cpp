#include "RavenGraphics.hpp"


RavenGraphics::RavenGraphics(){
    //si es false significa que la camara es lejana, si es true pasamos a FP (primera persona)
    SwitchCam = false;

	device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
            false, false, false, &receiver);
    
    if(device){
    	device->setWindowCaption(L"SoulMirror");
    	driver = device->getVideoDriver();
    	smgr = device->getSceneManager();
    	guienv = device->getGUIEnvironment();
        device->getFileSystem()->addFileArchive("media/map-20kdm2.pk3");
    	mesh = smgr->getMesh("media/cofre.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
		cube = smgr->addCubeSceneNode();
 
        camera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

        cube_second = smgr->addCubeSceneNode();
        vector3df posCube = vector3df(20,0,20);
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

		 vector3df cubePosition = cube->getPosition();

		core::vector3df cubePosition = cube->getPosition();


        if(receiver.IsKeyDown(irr::KEY_KEY_W))
            cubePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
        else if(receiver.IsKeyDown(irr::KEY_KEY_S))
            cubePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;

        if(receiver.IsKeyDown(irr::KEY_KEY_A))
            cubePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
        else if(receiver.IsKeyDown(irr::KEY_KEY_D))
            cubePosition.X += MOVEMENT_SPEED * frameDeltaTime;

        if(receiver.IsKeyDown(irr::KEY_KEY_P)){
            if(SwitchCam)
                SwitchCam = false;
            else
                SwitchCam = true;
        }

        if(receiver.IsKeyDown(irr::KEY_KEY_B)){
            delete map;
            map = NULL;
        }

        cube->setPosition(cubePosition);
        
		driver->beginScene(true, true, SColor(100,20,101,140));

        addCamera();


        if(collision(cube,cube_second) == true){
            //Colisionan
            cube_second->setPosition(core::vector3df(10,0,0));
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

bool RavenGraphics::collision(ISceneNode* one, ISceneNode* two){
   aabbox3d<f32> b1, b2;

   b1 = one->getBoundingBox ();
   b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   two->getRelativeTransformation().transformBoxEx( b2 );
   return b1.intersectsWithBox( b2 );
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

	cube->setPosition(core::vector3df(10,0,0));
    cube->setMaterialTexture(0, driver->getTexture("media/wall.bmp"));
    cube->setMaterialFlag(video::EMF_LIGHTING, false);
}

void RavenGraphics::addCamera(){

	//smgr->addCameraSceneNode(0, vector3df(0,30,-40), cube->getPosition());
    //ICameraSceneNode *camera = smgr->getActiveCamera();
    vector3df camaraPosition;
    camaraPosition.X = 0;
    camaraPosition.Y = 30;
    camaraPosition.Z = -40;
    
    if(!SwitchCam){
        camera->setPosition(camaraPosition);
        camera->setTarget(cube->getPosition());
    }
    else
        camera->setPosition(cube->getPosition());
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