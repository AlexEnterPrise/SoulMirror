#include "RavenGraphics.hpp"


//enum{
//   ID_IsNotPickable        = 0,
//   IDFlag_IsPickable       = 1 << 0,
//   IDFlag_IsHighlightable  = 1 << 1
//};
RavenGraphics::RavenGraphics(){
    //si es false significa que la camara es lejana, si es true pasamos a FP (primera persona)
    SwitchCam = false;

	device = irr::createDevice( irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16,
            false, false, false, &input);
    
    if(device){
    	device->setWindowCaption(L"SoulMirror");
    	driver = device->getVideoDriver();
    	smgr = device->getSceneManager();
    	guienv = device->getGUIEnvironment();

    	mesh = smgr->getMesh("media/pared01.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        node->setName("pared_01");
        collideables.push_back(node);
        mesh = smgr->getMesh("media/pared02.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/pared03.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/pared04.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/pared05.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/pared06.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/pared07.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/pared08.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/pared09.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        /*mesh = smgr->getMesh("media/paredes_009.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/paredes_010.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/paredes_011.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/paredes_012.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/paredes_013.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);
        mesh = smgr->getMesh("media/paredes_014.stl");
		node = smgr->addAnimatedMeshSceneNode( mesh );
        collideables.push_back(node);*/

		object = smgr->addCubeSceneNode(4);
        object->setName("cube_player");
        object->setPosition(irr::core::vector3df(-15,0,-83));
        //cube_player->setID(IDFlag_IsPickable);

        object = smgr->addCubeSceneNode(4);
        object->setName("enemy_01");
        //object->setScale(irr::core::vector3df(0.5f,0.5f,0.5f));
        object->setPosition(irr::core::vector3df(-15,0,-60));
        enemies.push_back(object);
        collideables.push_back(object);

        object = smgr->addCubeSceneNode(4);
        object->setName("enemy_02");
        //object->setScale(irr::core::vector3df(0.5f,0.5f,0.5f));
        object->setPosition(irr::core::vector3df(-45,0,-50));
        enemies.push_back(object);
        collideables.push_back(object);

        object = smgr->addCubeSceneNode(4);
        object->setName("enemy_03");
        //object->setScale(irr::core::vector3df(0.5f,0.5f,0.5f));
        object->setPosition(irr::core::vector3df(-25,0,-30));
        enemies.push_back(object);
        collideables.push_back(object);

        object = smgr->addCubeSceneNode(4);
        object->setName("enemy_04");
        //object->setScale(irr::core::vector3df(0.5f,0.5f,0.5f));
        object->setPosition(irr::core::vector3df(-20,0,10));
        enemies.push_back(object);
        collideables.push_back(object);

        object = smgr->addSphereSceneNode(1.5);
        object->setName("pocion_01");
        object->setPosition(irr::core::vector3df(-60,0,-30));
        collideables.push_back(object);
        pocion_gotcha = false;

        object = smgr->addSphereSceneNode(1);
        object->setName("key_01");
        object->setPosition(irr::core::vector3df(-60,1,25));
        collideables.push_back(object);
        key_gotcha = false;
        
        object = smgr->addCubeSceneNode(4);
        object->setName("door_01");
        object->setScale(irr::core::vector3df(1.f,1.f,6.f));
        //object->setScale(irr::core::vector3df(1.0f,1.5f,1.0f));
        object->setPosition(irr::core::vector3df(2,0,-10));
        collideables.push_back(object);

        object = smgr->addCubeSceneNode(4);
        object->setName("door_02");
        object->setScale(irr::core::vector3df(1.f,1.f,6.f));
        //object->setScale(irr::core::vector3df(1.0f,1.5f,1.0f));
        object->setPosition(irr::core::vector3df(-40,0,23));
        collideables.push_back(object);

        object = smgr->addSphereSceneNode(2);
        object->setName("npc_01");
        object->setPosition(irr::core::vector3df(-50,0,-83));
        collideables.push_back(object);

        object = smgr->addCubeSceneNode(3);
        object->setName("barril_01");
        object->setPosition(irr::core::vector3df(-5,0,-40));
        barriles.push_back(object);
        collideables.push_back(object);

        object = smgr->addCubeSceneNode(3);
        object->setName("barril_02");
        object->setPosition(irr::core::vector3df(-5,0, -47));
        barriles.push_back(object);
        collideables.push_back(object);

        //cube_second = smgr->addCubeSceneNode();
        //cube_second->setPosition(irr::core::vector3df(90,0,10));
       
        object = smgr->addCubeSceneNode(3);
        object->setName("draggable_01");
        object->setPosition(irr::core::vector3df(-20,0,30));
        draggables.push_back(object);
        collideables.push_back(object);

        object = smgr->addCubeSceneNode(2);
        object->setName("button_01");
        object->setScale(irr::core::vector3df(1.0f,0.5f,1.0f));
        object->setPosition(irr::core::vector3df(-30,0,30));
        buttons.push_back(object);
        
        camera = smgr->addCameraSceneNode(0, irr::core::vector3df(0,30,-40), irr::core::vector3df(0,5,0));

        colisiona = false;
        died = 0;       // Estado normal
        hit_points = 3;
        direction = 3; // Dirección hacia arriba
        throw_direction = 3;    // Dirección hacia arriba
        catched = 0;   // Sin coger
        bomb = 0;   // Bomba sin poner
        isPressed = false; // Tecla sin presionar
        arrows = 5;

    }
}


void RavenGraphics::run(){
	 int lastFPS = -1;

    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    irr::u32 then = device->getTimer()->getTime();

    //irr::scene::ISceneNode *key_01 = smgr->addSphereSceneNode(1);
    //key_01->setPosition(irr::core::vector3df(-15,1,15));
    //device->getFileSystem()->addFileArchive("media/map-20kdm2.pk3");

	//mesh = smgr->getMesh("20kdm2.bsp");
    /*mesh = smgr->getMesh("media/paredes.stl");
	scene::IMeshSceneNode* q3node = 0;

	// The Quake mesh is pickable, but doesn't get highlighted.
	if (mesh)
		//q3node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, 256);
        q3node = smgr->addMeshSceneNode( mesh );*/

    // This is the movement speed in units per second.
    const irr::f32 MOVEMENT_SPEED = 20.f;

    //q3node->setPosition(core::vector3df(-1350,-130,-1400));
    //irr::scene::ITriangleSelector* selector = smgr->createOctreeTriangleSelector(q3node->getMesh(), q3node, 128);
    /*irr::scene::ITriangleSelector* selector = smgr->createTriangleSelector(((scene::IMeshSceneNode*)q3node)->getMesh(), q3node);
    q3node->setTriangleSelector(selector);
    //irr::scene::ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();
    if(selector){
        const irr::core::aabbox3d<irr::f32>& box = smgr->getSceneNodeFromName("cube_player")->getBoundingBox();
        irr::core::vector3df radius = box.MaxEdge - box.getCenter();
        irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(selector,smgr->getSceneNodeFromName("cube_player"),radius,irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,0));
        selector->drop(); 
        smgr->getSceneNodeFromName("cube_player")->addAnimator(anim);
        anim->drop();
    }*/

    gui::IGUIFont* font = guienv->getFont("media/fonthaettenschweiler.bmp");
    if (font)
        guienv->getSkin()->setFont(font);
    //irr::gui::IGUIButton *btn;
    //irr::<çgui::IGUIWindow* win;
    bool open = false;
    //irr::scene::ISceneNodeAnimator *anim;
    //irr::core::vector3df playerPositionOld;
    //irr::core::vector3df playerPositionNew;
    int pos_object = 0;
    bool colBomba = false;
    int contFPS = 0;

	while(device->run())
    {
		const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f; // Time in seconds
        then = now;

        // Comprobamos el movimiento del jugador y lo movemos
        irr::core::vector3df cubePosition = input.comproveMovement(smgr, MOVEMENT_SPEED, frameDeltaTime,smgr->getSceneNodeFromName("cube_player"), collideables, died, driver);

        // Comprobamos a que dirección se dirige el jugador
        if(input.IsKeyDown(irr::KEY_KEY_D))
            direction = 1; // Dirección hacia derecha
        else if(input.IsKeyDown(irr::KEY_KEY_A))
            direction = 2; // Dirección hacia izquierda
        else if(input.IsKeyDown(irr::KEY_KEY_W))
            direction = 3; // Dirección hacia arriba
        else if(input.IsKeyDown(irr::KEY_KEY_S))
            direction = 4; // Dirección hacia abajo

        // Comprobamos si se mueve en diagonal
        if(input.IsKeyDown(irr::KEY_KEY_D) && input.IsKeyDown(irr::KEY_KEY_W))
            direction = 5; // Dirección hacia derecha-arriba
        else if(input.IsKeyDown(irr::KEY_KEY_A) && input.IsKeyDown(irr::KEY_KEY_W))
            direction = 6; // Dirección hacia izquierda-arriba
        else if(input.IsKeyDown(irr::KEY_KEY_D) && input.IsKeyDown(irr::KEY_KEY_S))
            direction = 7; // Dirección hacia derecha-abajo
        else if(input.IsKeyDown(irr::KEY_KEY_A) && input.IsKeyDown(irr::KEY_KEY_S))
            direction = 8; // Dirección hacia izquierda-abajo

        //SwitchCam = input.moveCam(SwitchCam, map);

        smgr->getSceneNodeFromName("cube_player")->setPosition(cubePosition);
        
		driver->beginScene(true, true, irr::video::SColor(100,20,101,140));

        addCamera();

        //Comprobamos si el cube_player (jugador) es golpeado para volver a ponerle su textura original
        if (died == 1){
            contFPS++;
            if(contFPS == 15){
                contFPS = 0;
                died = 0;
                smgr->getSceneNodeFromName("cube_player")->setMaterialTexture(0, driver->getTexture("media/color_player.jpg"));
                smgr->getSceneNodeFromName("cube_player")->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            }
        }

        //---------------------------------------------------- Colisión con el barril (coger/lanzar)------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------------------------------------------
        // Comprobamos si el cube_player (jugador) colisiona con algún objeto (BARRIL) en el vector collideables, si colisiona lo cogerá
        if (catched == 0 && input.IsKeyDown(irr::KEY_SPACE)){
            for(unsigned int i = 0; i < barriles.size();i++){
                if(collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), barriles[i])){
                    catched = 1;
                    pos_object = i;
                    for(unsigned int j = 0; j < collideables.size();j++){
                        if(collideables[j] == barriles[i]){
                            collideables.erase(collideables.begin() + j);
                            /*irr::core::vector3df pos = smgr->getSceneNodeFromName("cube_player")->getPosition();
                            pos.Y = pos.Y + 4;
                            smgr->getSceneNodeFromName("barril_01")->setPosition(pos);*/
                            //collideables[i]->setPosition(pos);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
        //Comprobamos la colision con el barril para ver si lo cogemos 
        if(catched==1){
            irr::core::vector3df pos = smgr->getSceneNodeFromName("cube_player")->getPosition();
            pos.Y = pos.Y + 4;
            barriles[pos_object]->setPosition(pos);
        }
        //lanzamos el objeto
        if(catched==1 && (input.IsKeyDown(irr::KEY_KEY_O) || input.IsKeyDown(irr::KEY_KEY_P) || input.IsKeyDown(irr::KEY_KEY_L) || input.IsKeyDown(irr::KEY_KEY_K))){
            irr::core::vector3df posBar = barriles[pos_object]->getPosition();
                // Comprobamos la dirección para establecer la posición inicial de la flecha
            if(direction == 1)
                posBar.X += 4;
            else if(direction == 2)
                posBar.X -= 4;
            else if(direction == 3)
                posBar.Z += 4;
            else if(direction == 4)
                posBar.Z -= 4;
            else if(direction == 5){
                posBar.X += 4;
                posBar.Z += 4;
            }
            else if(direction == 6){
                posBar.X -= 4;
                posBar.Z += 4;
            }
            else if(direction == 7){
                posBar.X += 4;
                posBar.Z -= 4;
            }
            else if(direction == 8){
                posBar.X -= 4;
                posBar.Z -= 4;
            }
            // Le añadimos altura, la posición al objeto flecha (arrow) y la textura
            posBar.Y = posBar.Y - 4;
            barriles[pos_object]->setPosition(posBar);
            catched = 2;
            throw_direction = direction;
        }
        if(catched == 2){
            
            irr::f32 objectSpeed = 75.f;
            input.moveObject(barriles[pos_object], objectSpeed, frameDeltaTime, throw_direction);

            // Comprobamos si colisiona con algún enemigo
            for(unsigned int i = 0; i < enemies.size();i++){
                if(collider.checkCollisionOneEnemy(barriles[pos_object], enemies[i])){
                    //std::cout << "Entro colision" << std::endl;
                    // Si colisiona borramos el barril y el enemigo
                    barriles[pos_object]->remove();
                    barriles.erase(barriles.begin() + pos_object);
                    // Borramos el enemigo de la escena y del array de enemigos (enemies)
                    enemies[i]->remove();
                    for(unsigned int j = 0; j < collideables.size();j++){
                        if(collideables[j] == enemies[i]){
                            collideables.erase(collideables.begin() + j);
                            break;
                        }
                    }
                    enemies.erase(enemies.begin() + i);
                    catched = 0;
                    break;
                }
            }
            // Comprobamos si colisiona con algún muro u objeto (siempre y cuando no sea NULL por haber colisionado con un enemigo)
            if(catched == 2 && collider.checkCollisionCollideables(smgr, barriles[pos_object], collideables)){
                // Si colisiona borramos el barril
                barriles[pos_object]->remove();
                barriles.erase(barriles.begin() + pos_object);
                catched = 0;
            }
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------------------------------------------

        //---------------------------------------------------- Colisión con el objeto arrastrable --------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------------------------------------------
        // Comprobamos si el cube_player (jugador) colisiona con algún draggable (objeto arrastrable) en el vector collideables, si colisiona lo podrá arrastrar
        if(catched == 0 && input.IsKeyDown(irr::KEY_SPACE)){
            //std::cout << "Entro draggable" << std::endl;
            for(unsigned int i = 0; i < draggables.size();i++){
                if(collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), draggables[i])){
                    pos_object = i;
                    /*for(unsigned int j = 0; j < collideables.size();j++){
                        if(collideables[j] == draggables[i]){
                            collideables.erase(collideables.begin() + j);
                            //std::cout << "Entro draggable" << std::endl;
                        }
                    }*/
                    catched = 3;
                    break;
                }
            }
        }

        // Si lo cogemos (catched = 3) lo movemos, si suelta la tecla deja el objeto
        if(catched == 3){
            input.moveDraggable(smgr, draggables[pos_object], MOVEMENT_SPEED, frameDeltaTime, collideables);
            // Comprobamos si el arrastrable se pone encima de algún botón, si es así no se podrá mover más
            if(collider.checkPressedButton(draggables[pos_object], buttons)){
                catched = 0;
                draggables.erase(draggables.begin() + pos_object);
                for(unsigned int i = 0; i < collideables.size();i++){
                    if(collideables[i] == smgr->getSceneNodeFromName("door_02")){
                        collideables.erase(collideables.begin() + i);
                        break;
                    }
                }
                smgr->getSceneNodeFromName("door_02")->remove();
            }
            // Comprobamos si se deja de presionar la tecla de acción, si se deja de presioanr se suelta el objeto 
            if(!input.IsKeyDown(irr::KEY_SPACE))
                catched = 0;
        }
        
        //------------------------------------------------------------------------------------------------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------------------------------------------

        //-----------------------------------PONER Y EXPLOTAR BOMBA REMOTA--------------------------------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------------------------------------------
        if(input.IsKeyDown(irr::KEY_KEY_L) && isPressed == false && catched == 0){
            if(bomb ==1){
                bomb = 0;
                for(unsigned int i=0; i<enemies.size() && !colBomba; i++){
                    colBomba = collider.checkCollisionBomba(smgr->getSceneNodeFromName("bomba"), enemies[i]);
                    //std::cout << "colBomb: " << colBomba << std::endl;
                    if(colBomba){
                        enemies[i]->remove();
                        for(unsigned int j = 0; j < collideables.size();j++){
                            if(collideables[j] == enemies[i]){
                                collideables.erase(collideables.begin() + j);
                                break;
                            }
                        }
                        enemies.erase(enemies.begin() + i);
                    }
                }
                if(collider.checkCollisionPlayerBomb(smgr->getSceneNodeFromName("bomba"), smgr->getSceneNodeFromName("cube_player"))){
                    if(!input.IsKeyDown(irr::KEY_KEY_K)){
                        hit_points -= 1;
                        comproveHP(cubePosition);
                    } 
                }
                smgr->getSceneNodeFromName("bomba")->remove();
                colBomba = false;
            }else if(bomb == 0){
                object = smgr->addCubeSceneNode(2);
                object->setName("bomba");
                irr::core::vector3df pos = smgr->getSceneNodeFromName("cube_player")->getPosition();
                object->setPosition(pos);
                object->setMaterialTexture(0, driver->getTexture("media/color_bomb.jpg"));
                //object->setScale(irr::core::vector3df(6.0f,6.0f,6.0f));
                object->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                bomb = 1; 
            }
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------------------------------------------
        
        //---------------------------------------------Colidión jugador-enemigo y espada-enemigo----------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------------------------------------------
        // Comprobamos si el cube_player (jugador) colisiona con algún enemigo en el vector enemies, si colisiona morirá
        for(unsigned int i = 0; i < enemies.size();i++){
            if(collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), enemies[i])){
                //Colisionan
                if(catched != 0 || !input.IsKeyDown(irr::KEY_KEY_K)){
                    hit_points -= 1;
                    comproveHP(cubePosition);
                }  
            }
            // Comprobamos si el cube_player (jugador) usa la espada y si colisiona con el enemigo lo mata
            if(catched == 0 && input.IsKeyDown(irr::KEY_KEY_P) && collider.checkCollisionEspada(smgr->getSceneNodeFromName("cube_player"), enemies[i], direction)){
                //std::string nom = collider.checkCollisionEspada(smgr->getSceneNodeFromName("cube_player"), enemies[i]);
                enemies[i]->remove();
                for(unsigned int j = 0; j < collideables.size();j++){
                    if(collideables[j] == enemies[i]){
                        collideables.erase(collideables.begin() + j);
                        break;
                    }
                }
                enemies.erase(enemies.begin() + i);
            }
        }

        // Comprobamos la animación hacia todos los lados y si choca antes con alguna pared
        /*if(died == 1 && collider.checkCollisionWallsAnim(smgr, smgr->getSceneNodeFromName("cube_player"), collideables)){
            smgr->getSceneNodeFromName("cube_player")->removeAnimator(anim);
            died = 0;
            anim->drop();
            std::cout << "Entro colision" << std::endl;
        }
        else if(died == 1 && round(cubePosition.X) == round(playerPositionOld.X)-6){
            smgr->getSceneNodeFromName("cube_player")->removeAnimator(anim);
            died = 0;
            anim->drop();
            std::cout << "Entro" << std::endl;
        }

        else if(died == 1 && round(cubePosition.X) == round(playerPositionOld.X)+6){
            smgr->getSceneNodeFromName("cube_player")->removeAnimator(anim);
            died = 0;
            anim->drop();
            std::cout << "Entro" << std::endl;
        }

        else if(died == 1 && round(cubePosition.Z) == round(playerPositionOld.Z)-6){
            smgr->getSceneNodeFromName("cube_player")->removeAnimator(anim);
            died = 0;
            anim->drop();
            std::cout << "Entro" << std::endl;
        }

        else if(died == 1 && round(cubePosition.Z) == round(playerPositionOld.Z)+6){
            smgr->getSceneNodeFromName("cube_player")->removeAnimator(anim);
            died = 0;
            anim->drop();
            std::cout << "Entro" << std::endl;
        }*/

        // Comprobamos si está muerto para cerrar la ventana si pulsa el botón
        if (hit_points == 0){
            if (btn->isPressed() /*|| input.IsKeyDown(irr::KEY_RETURN)*/){
                died = 0;
                hit_points = 3;
                win->remove();
                //cube_player->setPosition(irr::core::vector3df(4,0,-30));
            }
        }
        //------------------------------------------------------------------------------------------------------------------------------------------------
        //------------------------------------------------------------------------------------------------------------------------------------------------
       
        // Comprobamos si el cube_player (jugador) colisiona con algún bot en el vector npc, si colisiona hablará
        if (smgr->getSceneNodeFromName("npc_01")!=NULL){
            if(!open && collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), smgr->getSceneNodeFromName("npc_01")) && input.IsKeyDown(irr::KEY_RETURN)){
                for(unsigned int i = 0; i < collideables.size();i++){
                    if(collideables[i] == smgr->getSceneNodeFromName("npc_01")){
                        win = guienv->addWindow(core::rect<int>(200,90,490,290), true, L"Hello", 0, 5);
                        win->getCloseButton()->setVisible(false);
                        guienv->addStaticText(L"Hello my name is Tom, you are at the beginning of the game. \n Hope you have a nice adventure!",core::rect<int>(20,40,250,120), true, true, win);
                        const core::rect<int> rect(110,140,170, 180);
                        open=true;
                        died = 2; // Para que no se pueda mover hasta que se cierre el mensaje
                        btn = guienv->addButton( rect, win, 1, L"Continue", L"Continue");
                        //break;
                    }
                }
            }
        }
        
        if(open){
            if(btn->isPressed()){
                open = false;
                died = 0;  
                win->remove();
            }
        }
        
        // Comprobamos si el jugador (cube_player) tiene flechas y si pulsa el espacio para dispararla y la creamos
        if (catched == 0 && arrows > 0 && input.IsKeyDown(irr::KEY_KEY_O) && smgr->getSceneNodeFromName("arrow") == NULL){
            arrows = arrows - 1;
            object = smgr->addSphereSceneNode(0.8);
            object->setName("arrow");
            irr::core::vector3df arrowPosition = cubePosition;

            // Comprobamos la dirección para establecer la posición inicial de la flecha
            if(direction == 1)
                arrowPosition.X += 1;
            else if(direction == 2)
                arrowPosition.X -= 1;
            else if(direction == 3)
                arrowPosition.Z += 1;
            else if(direction == 4)
                arrowPosition.Z -= 1;
            else if(direction == 5){
                arrowPosition.X += 1;
                arrowPosition.Z += 1;
            }
            else if(direction == 6){
                arrowPosition.X -= 1;
                arrowPosition.Z += 1;
            }
            else if(direction == 7){
                arrowPosition.X += 1;
                arrowPosition.Z -= 1;
            }
            else if(direction == 8){
                arrowPosition.X -= 1;
                arrowPosition.Z -= 1;
            }
            // Le añadimos altura, la posición al objeto flecha (arrow) y la textura
            arrowPosition.Y = arrowPosition.Y + 2;
            object->setPosition(arrowPosition);
            object->setMaterialTexture(0, driver->getTexture("media/color_arrow.jpg"));
            object->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            // Cambiamos la dirección de lanzamiento
            throw_direction = direction;
        }
    
        // Comprobamos si existe la felcha (arrow) en la escena (smgr) para así poder moverla
        if(smgr->getSceneNodeFromName("arrow") != NULL){
            // Le ponemos velocidad y la movemos
            irr::f32 arrowSpeed = 75.f;
            input.moveObject (smgr->getSceneNodeFromName("arrow"), arrowSpeed, frameDeltaTime, throw_direction);
            
            // Comprobamos si colisiona con algún enemigo
            for(unsigned int i = 0; i < enemies.size();i++){
                if(collider.checkCollisionOneEnemy(smgr->getSceneNodeFromName("arrow"), enemies[i])){
                    // Si colisiona borramos la flecha y el enemigo
                    smgr->getSceneNodeFromName("arrow")->remove();
                    // Borramos el enemigo de la escena y del array de enemigos (enemies)
                    enemies[i]->remove();
                    for(unsigned int j = 0; j < collideables.size();j++){
                        if(collideables[j] == enemies[i]){
                            collideables.erase(collideables.begin() + j);
                            break;
                        }
                    }
                    enemies.erase(enemies.begin() + i);
                    break;
                }
            }

            // Comprobamos si colisiona con algún muro u objeto (siempre y cuando no sea NULL por haber colisionado con un enemigo)
            if(smgr->getSceneNodeFromName("arrow") != NULL && collider.checkCollisionCollideables(smgr, smgr->getSceneNodeFromName("arrow"), collideables)){
                // Si colisiona borramos la flecha
                smgr->getSceneNodeFromName("arrow")->remove();
            }
        }
            
 
        //Comprobamos si el cube_player (jugador) colisiona con la key_01 (objeto llave) y así poder cogerlo si colisiona
        if (smgr->getSceneNodeFromName("key_01")!=NULL){
            if(collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), smgr->getSceneNodeFromName("key_01")) && input.IsKeyDown(irr::KEY_KEY_Q)){
                for(unsigned int i = 0; i < collideables.size();i++){
                    if(collideables[i] == smgr->getSceneNodeFromName("key_01")){
                        collideables.erase(collideables.begin() + i);
                        smgr->getSceneNodeFromName("key_01")->remove();
                        key_gotcha = true;
                        break;
                    }
                }
            }
        }
        

        //Comprobamos si el cube_player (jugador) colisiona con la pocion y así poder cogerla si colisiona
        if (smgr->getSceneNodeFromName("pocion_01")!=NULL){
            if(collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), smgr->getSceneNodeFromName("pocion_01")) && input.IsKeyDown(irr::KEY_KEY_C)){
                for(unsigned int i = 0; i < collideables.size();i++){
                    if(collideables[i] == smgr->getSceneNodeFromName("pocion_01")){
                        collideables.erase(collideables.begin() + i);
                        smgr->getSceneNodeFromName("pocion_01")->remove();
                        pocion_gotcha = true;
                        break;
                    }
                }
            }
        }

        //Beber pocion
        if(pocion_gotcha && input.IsKeyDown(irr::KEY_KEY_B)){
            if(hit_points<3){
                std::cout<<hit_points <<std::endl;
                //sumado = true;
                hit_points ++;
                win = guienv->addWindow(core::rect<int>(200,90,490,290), true, L"Congratulations!");
                win->getCloseButton()->setVisible(false);
                guienv->addStaticText(L"You have now one more point",core::rect<int>(20,40,250,120), true, true, win);
                const core::rect<int> rect(110,140,170, 180);
                btn = guienv->addButton( rect, win,1 , L"Ok", L"Ok"); 
                open = true;
                pocion_gotcha = false;
            }else if(!open){
                win = guienv->addWindow(core::rect<int>(200,90,490,290), true, L"Advertance!", 0, 2);
                win->getCloseButton()->setVisible(false);
                guienv->addStaticText(L"You have the maxium of your hit point",core::rect<int>(20,40,250,120), true, true, win);
                open = true;
                const core::rect<int> rect(110,140,170, 180);
                btn = guienv->addButton( rect, win, 1, L"Continue", L"Continue");
                std::cout<<"entro en las 3 vidas" <<std::endl;
            }
        }
        if(open){
                if(btn->isPressed()){
                    open = false;  
                    win->remove();
                }
            }
        

        // Comprobamos si el cube_player (jugador) colisiona con el cube_second (fin del nivel) y así poder pasar de nivel si colisiona
        /*if(collider.checkCollision(smgr,smgr->getSceneNodeFromName("cube_player"),cube_second)){
        //Colisionan
            smgr->getSceneNodeFromName("cube_player")->setPosition(irr::core::vector3df(4,0,-30));
            cube_second->setPosition(irr::core::vector3df(90,0,10));
            cube_second->setMaterialTexture(0, driver->getTexture("media/color_player.jpg"));
            cube_second->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        }*/

        // Comprobamos si el cube_player (jugador) colisiona con el door(puerta del nivel) y así poder pasar
        if(smgr->getSceneNodeFromName("door_01") != NULL){
            if(collider.checkCollisionObject(smgr, smgr->getSceneNodeFromName("cube_player"), smgr->getSceneNodeFromName("door_01")) && key_gotcha == true && input.IsKeyDown(irr::KEY_KEY_Q)){
                for(unsigned int i = 0; i < collideables.size();i++){
                    if(collideables[i] == smgr->getSceneNodeFromName("door_01")){
                        collideables.erase(collideables.begin() + i);
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

        // Comprobamos si sigue pulsada la L para controlar la bomba
        isPressed = input.IsKeyDown(irr::KEY_KEY_L);
    }
}

void RavenGraphics::drop(){
	device->drop();
}

void RavenGraphics::comproveHP(irr::core::vector3df cubePosition){
    irr::core::vector3df playerPositionNew;

    if(hit_points!=0){
        died = 1; // Estado golpeado
        // Guardamos la posición actual (que será la antigua)
        //playerPositionOld = cubePosition;

        // Creamos el array de posiciones para la animación
        //irr::core::array<irr::core::vector3df> points;

        // Creamos una variable de posición y cambiamos su valor para añadirlo al array de la animación (Tenemos que comprobar la dirección)
        playerPositionNew = cubePosition;

        /*if(input.IsKeyDown(irr::KEY_KEY_D)){
            for (unsigned int i = 0; i < 6; i++){
                playerPositionNew.X = playerPositionNew.X - 1;
                points.push_back(playerPositionNew);
            }
        }

        else if(input.IsKeyDown(irr::KEY_KEY_A)){
            for (unsigned int i = 0; i < 6; i++){
                playerPositionNew.X = playerPositionNew.X + 1;
                points.push_back(playerPositionNew);
            }
        }

        if(input.IsKeyDown(irr::KEY_KEY_W)){
            for (unsigned int i = 0; i < 6; i++){
                playerPositionNew.Z = playerPositionNew.Z - 1;
                points.push_back(playerPositionNew);
            }
        }

        else if(input.IsKeyDown(irr::KEY_KEY_S)){
            for (unsigned int i = 0; i < 6; i++){
                playerPositionNew.Z = playerPositionNew.Z + 1;
                points.push_back(playerPositionNew);
            }
        }*/

        if(direction == 1)
            playerPositionNew.X -= 2;

        else if(direction == 2)
            playerPositionNew.X += 2;

        else if(direction == 3)
            playerPositionNew.Z -= 2;

        else if(direction == 4)
            playerPositionNew.Z += 2;

        else if(direction == 5){
            playerPositionNew.X -= 2;
            playerPositionNew.Z -= 2;
        }
        else if(direction == 6){
            playerPositionNew.X += 2;
            playerPositionNew.Z -= 2;
        }
        else if(direction == 7){
            playerPositionNew.X -= 2;
            playerPositionNew.Z += 2;
        }
        else if(direction == 8){
            playerPositionNew.X += 2;
            playerPositionNew.Z += 2;
        }
        // Actualizamos la posición del jugador      
        smgr->getSceneNodeFromName("cube_player")->setPosition(playerPositionNew);

        // Cambiamos el color en el choque para que se note la detección de la colisión
        smgr->getSceneNodeFromName("cube_player")->setMaterialTexture(0, driver->getTexture("media/color_collision.jpg"));
        smgr->getSceneNodeFromName("cube_player")->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        
        // Creamos la animación y se la añadimos al jugador
        //anim = smgr->createFollowSplineAnimator(0, points, 10.f, 0.3f, true, false);
        //smgr->getSceneNodeFromName("cube_player")->addAnimator(anim);
    }
    else{
        smgr->getSceneNodeFromName("cube_player")->setPosition(irr::core::vector3df(-15,0,-83));
        win = guienv->addWindow(core::rect<int>(200,90,490,290), true, L"Game Over", 0, 5);
        win->getCloseButton()->setVisible(false);
        guienv->addStaticText(L"You died. \n Press the button to continue.",core::rect<int>(20,40,250,120), true, true, win);
        died = 2; // Estado muerto
        const core::rect<int> rect(110,140,170, 180);
        btn = guienv->addButton( rect, win, 1, L"Continue", L"Continue");
    }
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
    for(unsigned int i = 0; i < collideables.size();i++){
        collideables[i]->setMaterialTexture(0, driver->getTexture("media/color_pared.jpg"));
        collideables[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < enemies.size();i++){
        enemies[i]->setMaterialTexture(0, driver->getTexture("media/color_enemy.jpg"));
        enemies[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < barriles.size();i++){
        barriles[i]->setMaterialTexture(0, driver->getTexture("media/color_barril.jpg"));
        barriles[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < draggables.size();i++){
        draggables[i]->setMaterialTexture(0, driver->getTexture("media/color_draggable.jpg"));
        draggables[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < buttons.size();i++){
        buttons[i]->setMaterialTexture(0, driver->getTexture("media/color_button.jpg"));
        buttons[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    smgr->getSceneNodeFromName("cube_player")->setMaterialTexture(0, driver->getTexture("media/color_player.jpg"));
    smgr->getSceneNodeFromName("cube_player")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    smgr->getSceneNodeFromName("key_01")->setMaterialTexture(0, driver->getTexture("media/color_object.jpg"));
    smgr->getSceneNodeFromName("key_01")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    smgr->getSceneNodeFromName("door_01")->setMaterialTexture(0, driver->getTexture("media/color_door.jpg"));
    smgr->getSceneNodeFromName("door_01")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    smgr->getSceneNodeFromName("door_02")->setMaterialTexture(0, driver->getTexture("media/color_door.jpg"));
    smgr->getSceneNodeFromName("door_02")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

    smgr->getSceneNodeFromName("npc_01")->setMaterialTexture(0, driver->getTexture("media/color_npc.jpg"));
    smgr->getSceneNodeFromName("npc_01")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

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
