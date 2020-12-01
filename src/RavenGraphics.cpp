#include "RavenGraphics.hpp"


//enum{
//   ID_IsNotPickable        = 0,
//   IDFlag_IsPickable       = 1 << 0,
//   IDFlag_IsHighlightable  = 1 << 1
//};
RavenGraphics::RavenGraphics(){
    //si es false significa que la camara es lejana, si es true pasamos a FP (primera persona)
    SwitchCam = false;

	device = irr::createDevice( irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16,
            false, false, false, &input);
    
    if(device){
    	device->setWindowCaption(L"SoulMirror");
    	driver = device->getVideoDriver();
    	smgr = device->getSceneManager();
    	guienv = device->getGUIEnvironment();

        //device->getFileSystem()->addFileArchive("media/map-20kdm2.pk3");
    	mesh = smgr->getMesh("media/paredes_001.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_002.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_003.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_004.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_005.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_006.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_007.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_008.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_009.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_010.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_011.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_012.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_013.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);
        mesh = smgr->getMesh("media/paredes_014.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        walls.push_back(node);

		object = smgr->addCubeSceneNode(4);
        object->setName("cube_player");
        object->setPosition(irr::core::vector3df(4,0,-30));
        //cube_player->setID(IDFlag_IsPickable);

        object = smgr->addCubeSceneNode(4);
        object->setName("enemy_01");
        //object->setScale(irr::core::vector3df(0.5f,0.5f,0.5f));
        object->setPosition(irr::core::vector3df(15,0,15));
        enemies.push_back(object);

        object = smgr->addCubeSceneNode(4);
        object->setName("enemy_02");
        //object->setScale(irr::core::vector3df(0.5f,0.5f,0.5f));
        object->setPosition(irr::core::vector3df(5,0,10));
        enemies.push_back(object);

        object = smgr->addSphereSceneNode(1);
        object->setName("key_01");
        object->setPosition(irr::core::vector3df(-15,1,15));
        walls.push_back(object);
        key_gotcha = false;
        
        object = smgr->addCubeSceneNode(4);
        object->setName("door_01");
        //object->setScale(irr::core::vector3df(1.0f,1.5f,1.0f));
        object->setPosition(irr::core::vector3df(45,0,10));
        walls.push_back(object);

        cube_second = smgr->addCubeSceneNode();
        //irr::core::vector3df posCube = irr::core::vector3df(15,0,20);
        cube_second->setPosition(irr::core::vector3df(90,0,10));
       
        //sphere = smgr->addSphereSceneNode();
        //sphere->setScale(irr::core::vector3df(0.5f,0.5f,0.5f));
        //sphere->setPosition(irr::core::vector3df(40,0,40));

		//wall = smgr->addCubeSceneNode();
        //wall->setID(IDFlag_IsPickable);
        //wall->setScale(irr::core::vector3df(1.0f,1.0f,3.0f));
        //wall_2 = smgr->addCubeSceneNode();
        //wall_2->setScale(irr::core::vector3df(1.0f,1.0f,3.0f));
        //wall_2->setPosition(irr::core::vector3df(30,0,0));
        //walls.push_back(wall);
        //walls.push_back(wall_2);
        colisiona = false;
        died = false;
        camera = smgr->addCameraSceneNode(0, irr::core::vector3df(0,30,-40), irr::core::vector3df(0,5,0));
        //map = 0;

    }
}


void RavenGraphics::run(){
	 int lastFPS = -1;

    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    irr::u32 then = device->getTimer()->getTime();

    //irr::scene::ISceneNode *key_01 = smgr->addSphereSceneNode(1);
    //key_01->setPosition(irr::core::vector3df(-15,1,15));

    // This is the movement speed in units per second.
    const irr::f32 MOVEMENT_SPEED = 15.f;
    //irr::scene::ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();
    //scene::ITriangleSelector* selector = smgr->createTriangleSelectorFromBoundingBox(wall);
    //wall->setTriangleSelector(selector);
    //if(selector){
    //    const irr::core::aabbox3d<irr::f32>& box = cube_player->getBoundingBox();
    //    irr::core::vector3df radius = box.MaxEdge - box.getCenter();
    //    irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(selector,cube_player,radius,
    //    irr::core::vector3df(0,0,0), irr::core::vector3df(0,30,0));
    //    selector->drop(); 
    //    cube_player->addAnimator(anim);
    //    anim->drop();
    //}

    irr::gui::IGUIButton *btn;
    gui::IGUIWindow* win;

	while(device->run())
    {
		const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f; // Time in seconds
        then = now;

		irr::core::vector3df cubePosition = smgr->getSceneNodeFromName("cube_player")->getPosition();
        //core::line3d<f32> ray;
        //ray.start = camera->getPosition();
        //ray.end = ray.start + (camera->getTarget() - ray.start).normalize() * 1000.0f;
        //// Tracks the current intersection point with the level or a mesh
        //core::vector3df intersection;
        //// Used to show with triangle has been hit
        //core::triangle3df hitTriangle;
        //scene::ISceneNode * selectedSceneNode =
        //    collMan->getSceneNodeAndCollisionPointFromRay(
        //            ray,
        //            intersection, // This will be the position of the collision
        //            hitTriangle, // This will be the triangle hit in the collision
        //            IDFlag_IsPickable, // This ensures that only nodes that we have
        //                    // set up to be pickable are considered
        //            0); 
//
        //if(selectedSceneNode){
        //    std::cout << "colisiona" << std::endl;
        //}else{
        //    std::cout << "NO CCcolisiona" << std::endl;
        //}
        cubePosition = input.comproveMovement(smgr,cubePosition, MOVEMENT_SPEED, frameDeltaTime,smgr->getSceneNodeFromName("cube_player"), walls, died);
        //cubePosition = input.comproveMovement(smgr,cubePosition, MOVEMENT_SPEED, frameDeltaTime, cube_player, wall_2);

        //SwitchCam = input.moveCam(SwitchCam, map);

        smgr->getSceneNodeFromName("cube_player")->setPosition(cubePosition);
        
		driver->beginScene(true, true, irr::video::SColor(100,20,101,140));

        addCamera();

        //Comprobamos si el cube_player (jugador) colisiona con la sphere (objeto) y así poder arrastrarlo si colisiona
        //if(collider.checkCollision(smgr,cube_player,sphere))
        //    input.moveSphere(frameDeltaTime, MOVEMENT_SPEED, cube_player,sphere);

        // Comprobamos si el cube_player (jugador) colisiona con algún enemigo en el vector enemies, si colisiona morirá
        for(unsigned int i = 0; i < enemies.size();i++){
            if(collider.checkCollision(smgr, smgr->getSceneNodeFromName("cube_player"), enemies[i])){
                //Colisionan
                smgr->getSceneNodeFromName("cube_player")->setPosition(irr::core::vector3df(4,0,-30));
                win = guienv->addWindow(core::rect<int>(200,90,490,290), true, L"Game Over", 0, 5);
                win->getCloseButton()->setVisible(false);
                gui::IGUIFont* font = guienv->getFont("media/fonthaettenschweiler.bmp");
                if (font)
                    guienv->getSkin()->setFont(font);
                guienv->addStaticText(L"You died. \n Press the button to continue.",core::rect<int>(20,40,250,120), true, true, win);
                died=true;
                const core::rect<int> rect(110,140,170, 180);
                btn = guienv->addButton( rect, win, 1, L"Continue", L"Continue");
            }
        }
        if (died==true)
        {
            if (btn->isPressed()){
                died=false;
                win->remove();
                //cube_player->setPosition(irr::core::vector3df(4,0,-30));
            }
        }
       
        //if(input.getSamorio() == false){
        //    std::cout<<"samorio en false" <<std::endl;
        //    died = false;
        //    input.setSamorio(true);
        //    //button->remove();
        //}
    
        //Comprobamos si el cube_player (jugador) colisiona con la key_01 (objeto llave) y así poder cogerlo si colisiona
        if (smgr->getSceneNodeFromName("key_01")!=NULL){
            if(collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), smgr->getSceneNodeFromName("key_01")) && input.IsKeyDown(irr::KEY_KEY_Q)){
                for(unsigned int i = 0; i < walls.size();i++){
                    if(walls[i] == smgr->getSceneNodeFromName("key_01")){
                        walls.erase(walls.begin() + i);
                        smgr->getSceneNodeFromName("key_01")->remove();
                        key_gotcha = true;
                        break;
                    }
                }
                //key_01->setVisible(false);
                //key_01->drop();
                //smgr->addToDeletionQueue(key_01);
                //scene::ISceneNodeAnimator* anim = smgr->createDeleteAnimator(10);
			    //key_01->addAnimator(anim);
			    //anim->drop();
            }
        }
        
        // Comprobamos si el cube_player (jugador) colisiona con el cube_second (fin del nivel) y así poder pasar de nivel si colisiona
        if(collider.checkCollision(smgr,smgr->getSceneNodeFromName("cube_player"),cube_second)){
        //Colisionan
            smgr->getSceneNodeFromName("cube_player")->setPosition(irr::core::vector3df(4,0,-30));
            cube_second->setPosition(irr::core::vector3df(90,0,10));
            cube_second->setMaterialTexture(0, driver->getTexture("media/color_player.jpg"));
            cube_second->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        }

        // Comprobamos si el cube_player (jugador) colisiona con el door(puerta del nivel) y así poder pasar
        if(smgr->getSceneNodeFromName("door_01") != NULL){
            if(collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), smgr->getSceneNodeFromName("door_01")) && key_gotcha == true && input.IsKeyDown(irr::KEY_KEY_Q)){
                for(unsigned int i = 0; i < walls.size();i++){
                    if(walls[i] == smgr->getSceneNodeFromName("door_01")){
                        walls.erase(walls.begin() + i);
                        smgr->getSceneNodeFromName("door_01")->remove();
                        key_gotcha = false;
                        break;
                    }
                }
            }
        }

        render.draw(smgr, guienv);

        driver->endScene();
		 int fps = driver->getFPS();

        if (lastFPS != fps)
        {
            irr::core::stringw tmp(L"Movement Example - Irrlicht Engine [");
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
	//smgr->drawAll();
}

void RavenGraphics::envirodrawAll(){
	//guienv->drawAll();
}

void RavenGraphics::addTextGUI(){
	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",irr::core::rect<irr::s32>(10,10,260,22), true);
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
    for(unsigned int i = 0; i < walls.size();i++){
        walls[i]->setMaterialTexture(0, driver->getTexture("media/color_pared.jpg"));
        walls[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < enemies.size();i++){
        enemies[i]->setMaterialTexture(0, driver->getTexture("media/color_enemy.jpg"));
        enemies[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    smgr->getSceneNodeFromName("cube_player")->setMaterialTexture(0, driver->getTexture("media/color_player.jpg"));
    smgr->getSceneNodeFromName("cube_player")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    smgr->getSceneNodeFromName("key_01")->setMaterialTexture(0, driver->getTexture("media/color_object.jpg"));
    smgr->getSceneNodeFromName("key_01")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    smgr->getSceneNodeFromName("door_01")->setMaterialTexture(0, driver->getTexture("media/color_door.jpg"));
    smgr->getSceneNodeFromName("door_01")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

}

void RavenGraphics::addCamera(){

	//smgr->addCameraSceneNode(0, vector3df(0,30,-40), cube_player->getPosition());
    //ICameraSceneNode *camera = smgr->getActiveCamera();
    irr::core::vector3df camaraPosition;
    camaraPosition.X = smgr->getSceneNodeFromName("cube_player")->getPosition().X;
    camaraPosition.Y = 40;
    camaraPosition.Z = smgr->getSceneNodeFromName("cube_player")->getPosition().Z - 20;
    
    if(!SwitchCam){
        camera->setPosition(camaraPosition);
        camera->setTarget(smgr->getSceneNodeFromName("cube_player")->getPosition());
    }
    else
        camera->setPosition(smgr->getSceneNodeFromName("cube_player")->getPosition());
    //camera->bindTargetAndRotation(true);
    //if(camera != NULL)
      //  cout<<"siuuu";
    //ICameraSceneNode camera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

    //scamera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

}


void RavenGraphics::drawMap(){
    /*if(device)
        device->getFileSystem()->addFileArchive("media/map-20kdm2.pk3");

    mesh = smgr->getMesh("20kdm2.bsp");
    if(mesh)
        map = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024);
    if (map)
        map->setPosition(core::vector3df(-1300,-144,-1249));*/
}

//irr::core::vector3df spherePosition = input.moveSphere(time, MOVEMENT_SPEED, cube_player,sphere);

irr::IrrlichtDevice* RavenGraphics::getDevice(){
	return device;
}

irr::scene::IAnimatedMesh* RavenGraphics::getMesh(){
	return mesh;
}

irr::scene::IAnimatedMeshSceneNode* RavenGraphics::getNode(){
	return node;
}

irr::scene::ISceneNode* RavenGraphics::getCube(){
	return smgr->getSceneNodeFromName("cube_player");
}