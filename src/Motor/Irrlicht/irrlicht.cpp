#include <Motor/Irrlicht/irrlicht.hpp>
//enum{
//   ID_IsNotPickable        = 0,
//   IDFlag_IsPickable       = 1 << 0,
//   IDFlag_IsHighlightable  = 1 << 1
//};
void Irrlicht_t::createWindow(uint32_t w, uint32_t h){ 
    //si es false significa que la camara es lejana, si es true pasamos a FP (primera persona)
    SwitchCam = false;

    // Primer bool a true = fullscreen
	device = irr::createDevice( irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(w,h), 16, false, false, true, &input);
    
    if(device){
    	device->setWindowCaption(L"SoulMirror");
    	driver = device->getVideoDriver();
    	smgr = device->getSceneManager();
    	guienv = device->getGUIEnvironment();

        irr::core::vector3df save_pos;
	    // Creamos el array de posiciones para la animación
        irr::core::array<irr::core::vector3df> points;

        // Llenamos el vector de nombres

        //----------- Enemigos -----------
        //--------------------------------
        names.push_back("enemy_");
        names.push_back("enemy_shoot_");
        //--------------------------------
        //--------------------------------

        names.push_back("potion_");
        names.push_back("key_");
        names.push_back("door_");
        names.push_back("gate_");
        names.push_back("barril_");
        names.push_back("draggable_");
        names.push_back("button_");
        names.push_back("zone_");
        names.push_back("range_");
        names.push_back("npc_");
        names.push_back("chest_");
        //names.push_back("pared_");

        // Comprobamos si hay un archivo de guardado
        if(loadGame()){
            //died = 0;       // Estado normal
            catched = 0;   // Sin coger
            bomb = 0;   // Bomba sin poner
            isPressed = false; // Tecla sin presionar
        }
        
        else{
            //----------------------------------------------------  PRIMERA ZONA  ----------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            mesh = smgr->getMesh("media/z1_p1.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_1");

            mesh = smgr->getMesh("media/z1_p2.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_2");

            mesh = smgr->getMesh("media/z1_p3.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_3");

            mesh = smgr->getMesh("media/z1_p4.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_4");

            mesh = smgr->getMesh("media/z1_p5.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_5");

            mesh = smgr->getMesh("media/z1_p6.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_6");

            mesh = smgr->getMesh("media/z1_p7.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_7");

            mesh = smgr->getMesh("media/suelo1.stl");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("suelo");

            /*mesh = smgr->getMesh("media/p1_z1.obj");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            //node->setName("pared_1");

            mesh = smgr->getMesh("media/p2_z1.obj");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            //node->setName("pared_2");

            mesh = smgr->getMesh("media/p3_z1.obj");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            //node->setName("pared_3");

            mesh = smgr->getMesh("media/p4_z1.obj");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            //node->setName("pared_4");

            mesh = smgr->getMesh("media/p5_z1.obj");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            //node->setName("pared_5");

            mesh = smgr->getMesh("media/p6_z1.obj");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            //node->setName("pared_6");

            mesh = smgr->getMesh("media/p7_z1.obj");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            //node->setName("pared_7");

            mesh = smgr->getMesh("media/suelo_z1.obj");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("suelo");*/

            object = smgr->addCubeSceneNode(4);
            object->setName("cube_player");
            object->setPosition(irr::core::vector3df(120,0,-86));

            camera = smgr->addCameraSceneNode(0, irr::core::vector3df(object->getPosition().X,40,object->getPosition().Z - 20), object->getPosition());

            object = smgr->addCubeSceneNode(4);
            object->setName("enemy_1");
            object->setPosition(irr::core::vector3df(99,0,-67));
            
            object = smgr->addCubeSceneNode(35);
            object->setName("range_1");
            object->setPosition(irr::core::vector3df(99,0,-67));
            object->setVisible(false);

            /*object = smgr->addCubeSceneNode(4);
            object->setName("enemy_2");
            object->setPosition(irr::core::vector3df(110,0,-42));
            
            object = smgr->addCubeSceneNode(40);
            object->setName("range_2");
            object->setPosition(irr::core::vector3df(110,0,-42));
            object->setVisible(false);*/

            object = smgr->addCubeSceneNode(4);
            object->setName("enemy_shoot_2");
            object->setPosition(irr::core::vector3df(110,0,-42));
            
            object = smgr->addCubeSceneNode(40);
            object->setName("range_2");
            object->setPosition(irr::core::vector3df(110,0,-42));
            object->setVisible(false);

            object = smgr->addCubeSceneNode(4);
            object->setName("npc_1");
            object->setPosition(irr::core::vector3df(77,0,-86));

            object = smgr->addCubeSceneNode(3);
            object->setName("chest_1");
            object->setScale(irr::core::vector3df(2.f,1.f,1.f));
            object->setPosition(irr::core::vector3df(71,1,-22));

            object = smgr->addSphereSceneNode(1);
            object->setName("key_1");
            object->setPosition(irr::core::vector3df(71,1,-22));

            object = smgr->addCubeSceneNode(1);
            object->setName("door_1");
            object->setScale(irr::core::vector3df(20.f,3.f,2.f));
            object->setPosition(irr::core::vector3df(83,0,-9));
            
            object = smgr->addCubeSceneNode(1);
            object->setName("zone_2");
            object->setScale(irr::core::vector3df(20.f,3.f,2.f));
            object->setPosition(irr::core::vector3df(83,0,0));

            object = smgr->addSphereSceneNode(1);
            object->setName("potion_1");
            object->setPosition(irr::core::vector3df(129,1,-17));

            // Texturizamos los objetos
            fillVectors();
            NodeLoadMaterial();

            // Guardamos la zona número 1
            smgr->saveScene("zone_1.irr");

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            // Borramos la escena
            smgr->clear();

            //----------------------------------------------------  SEGUNDA ZONA  ----------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            mesh = smgr->getMesh("media/z2_p1.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_1");

            mesh = smgr->getMesh("media/z2_p2.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_2");

            mesh = smgr->getMesh("media/z2_p3.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_3");

            mesh = smgr->getMesh("media/z2_p4.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_4");

            mesh = smgr->getMesh("media/z2_p5.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_5");

            mesh = smgr->getMesh("media/z2_p6.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_6");

            mesh = smgr->getMesh("media/z2_p7.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_7");

            mesh = smgr->getMesh("media/z2_p8.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_8");

            mesh = smgr->getMesh("media/z2_p9.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_9");

            mesh = smgr->getMesh("media/z2_p10.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_10");

            mesh = smgr->getMesh("media/z2_p11.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_11");

            mesh = smgr->getMesh("media/z2_p12.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_12");

            mesh = smgr->getMesh("media/z2_p13.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_13");

            mesh = smgr->getMesh("media/z2_p14.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_14");

            mesh = smgr->getMesh("media/suelo2.stl");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("suelo");

            object = smgr->addCubeSceneNode(4);
            object->setName("cube_player");
            object->setPosition(irr::core::vector3df(83,0,8));

            camera = smgr->addCameraSceneNode(0, irr::core::vector3df(object->getPosition().X,40,object->getPosition().Z - 20), object->getPosition());

            object = smgr->addCubeSceneNode(1);
            object->setName("zone_1");
            object->setScale(irr::core::vector3df(20.f,3.f,2.f));
            object->setPosition(irr::core::vector3df(83,0,1));

            object = smgr->addCubeSceneNode(4);
            object->setName("zone_3");
            object->setScale(irr::core::vector3df(0.5f,1.f,4.f));
            object->setPosition(irr::core::vector3df(54,0,79));

            object = smgr->addCubeSceneNode(4);
            object->setName("zone_4");
            object->setScale(irr::core::vector3df(0.5f,1.f,4.f));
            object->setPosition(irr::core::vector3df(146,0,78));

            object = smgr->addCubeSceneNode(4);
            object->setName("door_1");
            object->setScale(irr::core::vector3df(0.5f,1.f,4.f));
            object->setPosition(irr::core::vector3df(140,0,78));

            mesh = smgr->getMesh("media/barril.3DS");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("barril_1");
            node->setPosition(irr::core::vector3df(136,0,29));

            mesh = smgr->getMesh("media/barril.3DS");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("barril_2");
            node->setPosition(irr::core::vector3df(136,0, 37));

            mesh = smgr->getMesh("media/barril.3DS");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("barril_3");
            node->setPosition(irr::core::vector3df(136,0, 47));

            /*object = smgr->addCubeSceneNode(3);
            object->setName("barril_1");
            object->setPosition(irr::core::vector3df(136,0,29));

            object = smgr->addCubeSceneNode(3);
            object->setName("barril_2");
            object->setPosition(irr::core::vector3df(136,0, 37));

            object = smgr->addCubeSceneNode(3);
            object->setName("barril_3");
            object->setPosition(irr::core::vector3df(136,0, 47));*/
            
            object = smgr->addCubeSceneNode(4);
            object->setName("enemy_1");
            object->setPosition(irr::core::vector3df(89,0,30));
            
            object = smgr->addCubeSceneNode(4);
            object->setName("range_1");
            object->setScale(irr::core::vector3df(12.f,1.f,4.f));
            object->setPosition(irr::core::vector3df(89,0,30));
            object->setVisible(false);

            object = smgr->addCubeSceneNode(4);
            object->setName("enemy_2");
            object->setPosition(irr::core::vector3df(110,0,66));
            
            object = smgr->addCubeSceneNode(42);
            object->setName("range_2");
            object->setPosition(irr::core::vector3df(110,0,66));
            object->setVisible(false);

            object = smgr->addCubeSceneNode(4);
            object->setName("npc_2");
            object->setPosition(irr::core::vector3df(126,0,103));

            
            // Texturizamos los objetos
            fillVectors();
            NodeLoadMaterial();

            // Guardamos la zona número 2
            smgr->saveScene("zone_2.irr");

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            // Borramos la escena
            smgr->clear();
            
            //----------------------------------------------------  TERCERA ZONA  ----------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            mesh = smgr->getMesh("media/z3_p1.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_1");

            mesh = smgr->getMesh("media/z3_p2.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_2");

            mesh = smgr->getMesh("media/z3_p3.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_3");

            mesh = smgr->getMesh("media/z3_p4.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_4");

            mesh = smgr->getMesh("media/z3_p5.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_5");

            mesh = smgr->getMesh("media/z3_p6.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_6");

            mesh = smgr->getMesh("media/z3_p7.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_7");

            mesh = smgr->getMesh("media/suelo3.stl");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("suelo");

            object = smgr->addCubeSceneNode(4);
            object->setName("cube_player");
            object->setPosition(irr::core::vector3df(45,0,78));

            object = smgr->addCubeSceneNode(4);
            object->setName("enemy_1");
            object->setPosition(irr::core::vector3df(10,0,77));
            
            object = smgr->addCubeSceneNode(30);
            object->setName("range_1");
            object->setPosition(irr::core::vector3df(10,0,77));
            object->setVisible(false);

            object = smgr->addCubeSceneNode(3);
            object->setName("draggable_1");
            object->setPosition(irr::core::vector3df(-20,0,64));

            object = smgr->addCubeSceneNode(2);
            object->setName("button_1");
            object->setScale(irr::core::vector3df(1.0f,0.5f,1.0f));
            object->setPosition(irr::core::vector3df(-20,0,92));
            
            object = smgr->addCubeSceneNode(4);
            object->setName("gate_1");
            object->setScale(irr::core::vector3df(1.f,1.f,12.f));
            object->setPosition(irr::core::vector3df(-31,0,77));
            
            camera = smgr->addCameraSceneNode(0, irr::core::vector3df(object->getPosition().X,40,object->getPosition().Z - 20), object->getPosition());

            object = smgr->addSphereSceneNode(1);
            object->setName("key_1");
            object->setPosition(irr::core::vector3df(-47,1,75));
            
            object = smgr->addCubeSceneNode(1);
            object->setName("zone_2");
            object->setScale(irr::core::vector3df(2.f,3.f,20.f));
            object->setPosition(irr::core::vector3df(52,0,78));

            // Texturizamos los objetos
            fillVectors();
            NodeLoadMaterial();

            // Guardamos la zona número 3
            smgr->saveScene("zone_3.irr");

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            
            // Borramos la escena
            smgr->clear();

            //----------------------------------------------------  CUARTA ZONA  -----------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            mesh = smgr->getMesh("media/z4_p1.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_1");

            mesh = smgr->getMesh("media/z4_p2.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_2");

            mesh = smgr->getMesh("media/z4_p3.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_3");

            mesh = smgr->getMesh("media/z4_p4.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_4");

            mesh = smgr->getMesh("media/z4_p5.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_5");

            mesh = smgr->getMesh("media/z4_p6.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_6");

            mesh = smgr->getMesh("media/z4_p7.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_7");

            mesh = smgr->getMesh("media/z4_p8.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_8");

            mesh = smgr->getMesh("media/z4_p9.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_9");

            mesh = smgr->getMesh("media/z4_p10.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("pared_10");

            mesh = smgr->getMesh("media/z4_p11fin.STL");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("final");

            mesh = smgr->getMesh("media/suelo4.stl");
            node = smgr->addAnimatedMeshSceneNode( mesh );
            node->setName("suelo");

            object = smgr->addCubeSceneNode(4);
            object->setName("cube_player");
            object->setPosition(irr::core::vector3df(154,0,78));

            camera = smgr->addCameraSceneNode(0, irr::core::vector3df(object->getPosition().X,40,object->getPosition().Z - 20), object->getPosition());

            object = smgr->addCubeSceneNode(1);
            object->setName("zone_2");
            object->setScale(irr::core::vector3df(2.f,3.f,20.f));
            object->setPosition(irr::core::vector3df(148,0,78));

            object = smgr->addCubeSceneNode(4);
            object->setName("enemy_1");
            object->setPosition(irr::core::vector3df(198,0,76));
            
            object = smgr->addCubeSceneNode(40);
            object->setName("range_1");
            object->setScale(irr::core::vector3df(0.5f,1.f,6.f));
            object->setPosition(irr::core::vector3df(198,0,76));
            object->setVisible(false);

            // Texturizamos los objetos
            fillVectors();
            NodeLoadMaterial();

            // Guardamos la zona número 4
            smgr->saveScene("zone_4.irr");

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            
            // Borramos la escena
            smgr->clear();

            //colisiona = false;
            weapon = 1;     // Espada
            shield = 0;     // No se protege
            died = 0;       // Estado normal
            hit_points = 3;
            max_hp = 3;     // Puntos de salud (HP) máximos
            direction = 3; // Dirección hacia arriba
            throw_direction = 3;    // Dirección hacia arriba
            catched = 0;   // Sin coger
            bomb = 0;   // Bomba sin poner
            isPressed = false; // Tecla sin presionar
            arrows = 30;    // Número de flechas
            potion_gotcha = 0; // Número de pociones
            key_gotcha = 0; // Número de llaves
            zone = 1;   // Zona en la que nos encontramos
            
            // Borramos la animación
            //anim->drop();
        }

        //Ahora procedemos a cargar los sonidos
        sound.loadBanks("media/FMODR/Master.bank");
        sound.loadBanks("media/FMODR/Master.strings.bank");
        sound.loadEvent("event:/Ambientes/Bosque");
        sound.loadEvent("event:/Ambientes/Desierto");
        sound.loadEvent("event:/Ambientes/industrial");
        sound.loadEvent("event:/Ambientes/Nieve");
        sound.loadEvent("event:/Efectos/ataque/Espada_sin_colision");
        sound.loadEvent("event:/Efectos/ataque/beber");
        sound.loadEvent("event:/Efectos/cambio_arma/desenfundar");
        sound.loadEvent("event:/Efectos/ataque/explosion");
        sound.loadEvent("event:/Efectos/ataque/soltar_flecha");
        sound.loadEvent("event:/Efectos/colisiones/corte");
        sound.loadEvent("event:/Efectos/colisiones/escudo");
        sound.loadEvent("event:/Efectos/ataque/soltar_objeto");
        sound.loadEvent("event:/Efectos/colisiones/muerte");
        sound.loadEvent("event:/Efectos/colisiones/objeto");
        sound.loadEvent("event:/Efectos/abrir_puerta");
        sound.loadEvent("event:/Efectos/mecanismo");
        
        sound.loadEvent("event:/Efectos/colisiones/herida");
        
        sound.playEvent("event:/Ambientes/Nieve");

    }
}



void Irrlicht_t::physicsInit(){
    
    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    then = device->getTimer()->getTime();

    // This is the movement speed in units per second.
    MOVEMENT_SPEED = 20.f;
}

void Irrlicht_t::renderInit(){
    font = guienv->getFont("media/myfont.xml");
    if (font)
        guienv->getSkin()->setFont(font);
    //irr::gui::IGUIButton *btn;
    //irr::<çgui::IGUIWindow* win;
    //irr::scene::ISceneNodeAnimator *anim;
    //irr::core::vector3df playerPositionOld;
    //irr::core::vector3df playerPositionNew;
    
    zoneAux = "zone_" + std::to_string(zone) + ".irr";
    zoneToChange = zoneAux.c_str();

    // Cargamos la escena por primera vez
    smgr->loadScene(zoneToChange);
}

void Irrlicht_t::run(){
	
    int btn_check = 0; // Botón seleccionado en el menú; 0 --> resume; 1 --> load; 2 --> exit 
    int change_btn_check = btn_check; // Variable auxiliar para comprobar si en el menú se cambia de botón

    //Aqui irá el bucle en el main
    while(device->run()){
		const irr::u32 now = device->getTimer()->getTime();
        const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f; // Time in seconds
        then = now;
        //video::ITexture* irrlichtBack = driver->getTexture("media/color_enemy.jpg");

        if(menu == 0){
            //tabctrl = guienv->addTabControl(irr::core::rect<int>(60,10,602,374), 0, true, true);
            tabctrl = guienv->addTabControl(irr::core::rect<int>(0,0,1920,1080), 0, true, true);
            irr::gui::IGUITab* optContr = tabctrl->addTab(L"  Game  ");
            irr::gui::IGUITab* aboutTab = tabctrl->addTab(L"  Info  ");   

            //startButton = guienv->addButton(irr::core::rect<int>(100,900,300,950), optContr, 2, L"Start game");

            menu = 1;
            died = 2;

            // Añadimos a la pestaña de info el contenido
            text =  L"This is the first prototype of our game.\n"\
                    L"The purpose of the game is to show the mechanics and reach the end of the map.";
            guienv->addStaticText(text, irr::core::rect<int>(650, 200, 1250, 600), false, true, aboutTab);
            img = driver->getTexture("media/title_info.png");
            if(img) guienv->addImage(img, irr::core::position2di(855, 100), true, aboutTab, -1, L"Title info");
            img = driver->getTexture("media/start_game.png");
            if(img) guienv->addImage(img, irr::core::position2di(480, 820), true, aboutTab, -1, L"Start game");

            // Añadimos a la pestaña de game el contenido
            img = driver->getTexture("media/controls.png");
            if(img) guienv->addImage(img, irr::core::position2di(330, 100), true, optContr, -1, L"Controls");
            img = driver->getTexture("media/start_game.png");
            if(img) guienv->addImage(img, irr::core::position2di(480, 820), true, optContr, -1, L"Start game");

            /*text =  L"\n"\
                                    L"MOVEMENTS\n"\
                                    L"W-> Move up\n"\
                                    L"A-> Move left\n"\
                                    L"S-> Move down\n"\
                                    L"D-> Move right\n"\
                                    L"\n"\
                                    L"\n"\
                                    L"ACTIONS\n"\
                                    L"Space-> Action button\n"\
                                    L"Left/Rigth Shift-> Run\n"\
                                    L"1-> Use sword\n"\
                                    L"2-> Use shield\n"\
                                    L"3-> Use bow\n"\
                                    L"4-> Use bomb\n"\
                                    L"5-> Use potion\n"\
                                    L"Left click-> Use weapon\n"\
                                    L"Enter-> Close messages\n";
                                    

            //guienv->addStaticText(text, irr::core::rect<int>(10, 10, 430, 280), false, true, optContr);
            guienv->addStaticText(text, irr::core::rect<int>(10, 10, 1920, 800), false, true, optContr);*/
                
        }
        
        if(menu == 1 && (/*startButton->isPressed() ||*/ input.IsKeyDown(irr::KEY_RETURN))){
            died = 0;
            menu = 2;
            tabctrl->remove();
        }

        if(menu == 2){

            //std::cout << "Frame delta time = ";
            //std::cout << frameDeltaTime << std::endl;

            // Comprobamos si se produce un cambio de zona
            if(zoneChange){
                // Llenamos la escena y dibujamos la zona
                drawZone(zoneToChange, pos_object);
                zoneChange = false;
            }
            //std::cout << zones[0]->getName() << std::endl;

            // Comprobamos si el jugador corre para cambiar la velocidad
            if(catched == 0 && (input.IsKeyDown(irr::KEY_LSHIFT) || input.IsKeyDown(irr::KEY_RSHIFT))){
                MOVEMENT_SPEED = 30.f;
            }

            if (catched != 0 || (!input.IsKeyDown(irr::KEY_LSHIFT) && !input.IsKeyDown(irr::KEY_RSHIFT))){
                MOVEMENT_SPEED = 20.f;
            }

            if(MOVEMENT_SPEED > 20.f){
                sound.playEvent("event:/Efectos/correr");
                sound.stopEvent("event:/Efectos/caminar");
            }else if(MOVEMENT_SPEED > 0.f){
                sound.stopEvent("event:/Efectos/correr");
                sound.playEvent("event:/Efectos/caminar");
            }else{
                sound.stopEvent("event:/Efectos/correr");
                sound.stopEvent("event:/Efectos/caminar");
            }


            // Comprobamos el movimiento del jugador y lo movemos
            irr::core::vector3df cubePosition = irr::core::vector3df(0);
            cubePosition = input.comproveMovement(smgr, MOVEMENT_SPEED, frameDeltaTime, smgr->getSceneNodeFromName("cube_player"), collideables, died, driver);
            smgr->getSceneNodeFromName("cube_player")->setPosition(cubePosition);

            // Comprobamos a que dirección se dirige el jugador
            if(input.IsKeyDown(irr::KEY_KEY_D)){
                direction = 1; // Dirección hacia derecha
                
            }
            else if(input.IsKeyDown(irr::KEY_KEY_A)){
                direction = 2; // Dirección hacia izquierda

            }
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
            
            driver->beginScene(true, true, irr::video::SColor(100,20,101,140));

            addCamera();

            //---------------------------------------------------- Comprobar estados died --------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            //Comprobamos si el cube_player (jugador) es golpeado para volver a ponerle su textura original
            if (died == 1){
                contFPS++;
                if(contFPS == 50){
                    contFPS = 0;
                    died = 0;
                    smgr->getSceneNodeFromName("cube_player")->setMaterialTexture(0, driver->getTexture("media/color_player.jpg"));
                    smgr->getSceneNodeFromName("cube_player")->setMaterialFlag(irr::video::EMF_LIGHTING, false);
                }
            }

            //Comprobamos si el cube_player (jugador) está bebiendo una poción para que pueda volver a moverse tras pasar 30 frames (0,5 s)
            if (died == 3){
                contFPS++;
                if(contFPS == 30){
                    contFPS = 0;
                    died = 0;
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------- Cambiar arma (weapon)----------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            if(input.IsKeyDown(irr::KEY_KEY_1)){
                weapon = 1; // Espada
                sound.playEvent("event:/Efectos/cambio_arma/desenfundar","Arma",0);
            }

            if(input.IsKeyDown(irr::KEY_KEY_2)){
                weapon = 2; // Escudo
                sound.playEvent("event:/Efectos/cambio_arma/desenfundar","Arma",3);
            }

            if(input.IsKeyDown(irr::KEY_KEY_3)){
                weapon = 3; // Arco
                sound.playEvent("event:/Efectos/cambio_arma/desenfundar","Arma",1);
            }

            if(input.IsKeyDown(irr::KEY_KEY_4)){
                weapon = 4; // Bomba
                sound.playEvent("event:/Efectos/cambio_arma/desenfundar","Arma",2);
            }

            if(input.IsKeyDown(irr::KEY_KEY_5)){
                weapon = 5; // Poción
                sound.playEvent("event:/Efectos/cambio_arma/desenfundar","Arma",4);
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------- Fin del prototipo -------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            if(smgr->getSceneNodeFromName("final")){
                if(!fin && Irrlicht_t::checkCollisionObject(smgr->getSceneNodeFromName("cube_player"), smgr->getSceneNodeFromName("final"))){
                    fin = true;
                    died = 2; // Para que no se pueda mover hasta que se cierre el mensaje
                    //win = guienv->addWindow(irr::core::rect<int>(200,90,490,290), true, L"Final", 0, 5);
                    //win->getCloseButton()->setVisible(false);
                    //guienv->addStaticText(L"To be continued...",irr::core::rect<int>(20,40,250,120), true, true, win);
                    //const irr::core::rect<int> rect(100,140,170, 180);
                    //btn = guienv->addButton( rect, win, 1, L"Press Enter", L"Continue");
                    treeWindow = guienv->addTreeView(irr::core::rect<int>(400,200,1500,900), 0, -1, false, false, false);
                    img = driver->getTexture("media/end.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, treeWindow, -1, L"End");
                }
            }

            if(fin){
                if(input.IsKeyDown(irr::KEY_RETURN)){
                    treeWindow->remove();
                    fin = false;
                    died = 0; 
                    device->closeDevice();
                }
            }


            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------- Cambiar de zona ---------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            for(unsigned int i = 0; i < zones.size();i++){
                int aux = Irrlicht_t::checkCollisionZone(smgr->getSceneNodeFromName("cube_player"), zones[i]);
                if(aux != 0){
                    //Colisionan
                    // Miramos las direcciones para cambiar la posición del jugador (cube_player)
                    posPlayer = cubePosition;

                    if(aux == 1)
                        posPlayer.X -= 4;
                    else if(aux == 2)
                        posPlayer.X += 4;
                    else if(aux == 3)
                        posPlayer.Z -= 4;
                    else if(aux == 4)
                        posPlayer.Z += 4;

                    smgr->getSceneNodeFromName("cube_player")->setPosition(posPlayer);

                    // Guardamos la zona a la que vamos a cambiar
                    //std::cout << zoneToChange << std::endl;
                    zoneAux = zones[i]->getName();
                    zoneAux += ".irr";
                    zoneToChange = zoneAux.c_str();
                    //std::cout << zoneToChange << std::endl;
                    zoneChange = true;
                    break;
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------------- IA ENEMIGOS -------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            std::string name;
            for(unsigned int i=0; i<ranges.size(); i++){
                // Enemigos normales
                name = "enemy_" + std::to_string(i+1);
                if(enemies[i]->getName() == name){
                    if(Irrlicht_t::checkCollisionEnemiesPlayer(ranges[i], smgr->getSceneNodeFromName("cube_player"))){
                        posPlayer = smgr->getSceneNodeFromName("cube_player")->getPosition();
                        //std::cout << "Entro colision" << std::endl;
                        input.moveEnemy(died, enemies[i], posPlayer, MOVEMENT_SPEED_ENEMY, frameDeltaTime, collideables);
                    }
                    else if (posIniEnemies[i] != enemies[i]->getAbsolutePosition()){
                        // Lo movemos a la posición inicial
                        input.moveEnemy(died, enemies[i], posIniEnemies[i], MOVEMENT_SPEED_ENEMY, frameDeltaTime, collideables);
                    }
                }

                // Enemigos shooters
                name = "enemy_shoot_" + std::to_string(i+1);
                if(enemies[i]->getName() == name){
                    if(Irrlicht_t::checkCollisionEnemiesPlayer(ranges[i], smgr->getSceneNodeFromName("cube_player"))){
                        
                    }
                }
            }

            //----------------------------------------------------------------------------------------------------------------------
            //----------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------- Protegerse con el escudo-------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            if(weapon == 2 && catched == 0 && input.IsLeftClickDown() && died != 2){
                shield = 1;

                posPlayer = cubePosition;
                scale.X = 1.f;
                scale.Y = 1.f;
                scale.Z = 1.f;
                rotation.X = 0.f;
                rotation.Y = 0.f;
                rotation.Z = 0.f;

                // Comprobamos la dirección para establecer la posición de la espada
                if(direction == 1){
                    posPlayer.X += 3.2f;
                    scale.X = 1.f;
                    scale.Z = 4.5f;
                }
                else if(direction == 2){
                    posPlayer.X -= 3.2f;
                    scale.X = 1.f;
                    scale.Z = 4.5f;
                }
                else if(direction == 3 || direction == 5 || direction == 6){
                    posPlayer.Z += 3.2f;
                    scale.X = 4.5f;
                    scale.Z = 1.f;
                }
                else if(direction == 4 || direction == 7 || direction == 8){
                    posPlayer.Z -= 3.2f;
                    scale.X = 4.5f;
                    scale.Z = 1.f;
                }
                else if(direction == 5){
                    posPlayer.X += 4.5f;
                    posPlayer.Z += 4.5f;
                    scale.X = 1.f;
                    scale.Z = 4.5f;
                    rotation.Y = -45.f;
                }
                else if(direction == 6){
                    posPlayer.X -= 4.5f;
                    posPlayer.Z += 4.5f;
                    scale.X = 1.f;
                    scale.Z = 4.5f;
                    rotation.Y = 45.f;
                }
                else if(direction == 7){
                    posPlayer.X += 4.5f;
                    posPlayer.Z -= 4.5f;
                    scale.X = 1.f;
                    scale.Z = 4.5f;
                    rotation.Y = 45.f;
                }
                else if(direction == 8){
                    posPlayer.X -= 4.5f;
                    posPlayer.Z -= 4.5f;
                    scale.X = 1.f;
                    scale.Z = 4.5f;
                    rotation.Y = -45.f;
                }

                if(!smgr->getSceneNodeFromName("shield")){
                    object = smgr->addCubeSceneNode(1);
                    object->setName("shield");
                    //object->setVisible(false);
                    collideables.push_back(object);
                }

                irr::core::vector3df oldPos = smgr->getSceneNodeFromName("shield")->getPosition();
                smgr->getSceneNodeFromName("shield")->setPosition(posPlayer);
                smgr->getSceneNodeFromName("shield")->setScale(scale);
                smgr->getSceneNodeFromName("shield")->setRotation(rotation);

                if(Irrlicht_t::checkCollisionCollideables(smgr->getSceneNodeFromName("shield"), collideables))
                    smgr->getSceneNodeFromName("shield")->setPosition(oldPos);
            }

            // Comprobamos si tiene algún objeto cogido, si cambia de arma o si deja de clickar para dejar de protegerse
            if(weapon != 2 || catched != 0 || !input.IsLeftClickDown()){
                shield = 0;

                if(smgr->getSceneNodeFromName("shield")){
                    for(unsigned int i = 0; i < collideables.size();i++){
                        if(collideables[i] == smgr->getSceneNodeFromName("shield")){
                            collideables.erase(collideables.begin() + i);
                            break;
                        }
                    }
                    smgr->getSceneNodeFromName("shield")->remove();
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------- Colisión con el barril (coger/lanzar)------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            // Comprobamos si el cube_player (jugador) colisiona con algún objeto (BARRIL) en el vector collideables, si colisiona lo cogerá
            if (catched == 0 && input.IsKeyDown(irr::KEY_SPACE)){
                for(unsigned int i = 0; i < barriles.size();i++){
                    if(Irrlicht_t::checkCollisionObject(smgr->getSceneNodeFromName("cube_player"), barriles[i])){
                        catched = 1;
                        pos_object = i;
                        for(unsigned int j = 0; j < collideables.size();j++){
                            if(collideables[j] == barriles[i]){
                                collideables.erase(collideables.begin() + j);
                                /*irr::core::vector3df pos = smgr->getSceneNodeFromName("cube_player")->getPosition();
                                pos.Y = pos.Y + 4;
                                smgr->getSceneNodeFromName("barril_1")->setPosition(pos);*/
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
            if(catched==1 && input.IsLeftClickDown()){
                sound.playEvent("event:/Efectos/ataque/soltar_objeto");
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
                    if(Irrlicht_t::checkCollisionOneEnemy(barriles[pos_object], enemies[i])){
                        sound.playEvent("event:/Efectos/colisiones/objeto");

                        //std::cout << "Entro colision" << std::endl;
                        // Si colisiona borramos el barril y el enemigo
                        barriles[pos_object]->remove();
                        barriles.erase(barriles.begin() + pos_object);
                        // Borramos el enemigo de la escena y del array de enemigos (enemies)
                        enemies[i]->remove();
                        ranges[i]->remove();
                        for(unsigned int j = 0; j < collideables.size();j++){
                            if(collideables[j] == enemies[i]){
                                collideables.erase(collideables.begin() + j);
                                break;
                            }
                        }
                        enemies.erase(enemies.begin() + i);
                        ranges.erase(ranges.begin() + i);
                        posIniEnemies.erase(posIniEnemies.begin() + i);
                        catched = 0;
                        break;
                    }
                }
                // Comprobamos si colisiona con algún muro u objeto (siempre y cuando no sea NULL por haber colisionado con un enemigo)
                if(catched == 2 && Irrlicht_t::checkCollisionCollideables(barriles[pos_object], collideables)){
                    sound.playEvent("event:/Efectos/colisiones/objeto");

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
                    if(Irrlicht_t::checkCollisionObject( smgr->getSceneNodeFromName("cube_player"), draggables[i])){
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
                if(Irrlicht_t::checkPressedButton(smgr->getSceneNodeFromName("cube_player"), draggables[pos_object], buttons)){
                    sound.playEvent("event:/Efectos/mecanismo");

                    catched = 0;
                    gates[pos_object]->remove();
                    for(unsigned int i = 0; i < collideables.size();i++){
                        if(collideables[i] == gates[pos_object]){
                            collideables.erase(collideables.begin() + i);
                            break;
                        }
                    }
                    draggables.erase(draggables.begin() + pos_object);
                    gates.erase(gates.begin() + pos_object);
                }
                // Comprobamos si se deja de presionar la tecla de acción, si se deja de presioanr se suelta el objeto 
                if(!input.IsKeyDown(irr::KEY_SPACE))
                    catched = 0;
            }
            
            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //-----------------------------------PONER Y EXPLOTAR BOMBA REMOTA--------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            if(weapon == 4 && catched == 0 && input.IsLeftClickDown() && isPressed == false && died != 2){
                if(bomb ==1){
                    bomb = 0;
                    sound.playEvent("event:/Efectos/ataque/explosion");
                    for(unsigned int i=0; i<enemies.size() && !colBomba; i++){
                        colBomba = Irrlicht_t::checkCollisionBomba(smgr->getSceneNodeFromName("bomba"), enemies[i]);
                        //std::cout << "colBomb: " << colBomba << std::endl;
                        if(colBomba){
                            enemies[i]->remove();
                            ranges[i]->remove();
                            for(unsigned int j = 0; j < collideables.size();j++){
                                if(collideables[j] == enemies[i]){
                                    collideables.erase(collideables.begin() + j);
                                    break;
                                }
                            }
                            enemies.erase(enemies.begin() + i);
                            ranges.erase(ranges.begin() + i);
                            posIniEnemies.erase(posIniEnemies.begin() + i);
                        }
                    }
                    if(Irrlicht_t::checkCollisionPlayerBomb(smgr->getSceneNodeFromName("bomba"), smgr->getSceneNodeFromName("cube_player"))){
                        if(shield == 0){
                            sound.playEvent("event:/Efectos/colisiones/herida");

                            hit_points -= 1;
                            updateHearts = true;
                            comproveHP(cubePosition, true);
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
            
            //---------------------------------------------------- Colisión enemigo-espada -------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            
            // Comprobamos si el cube_player (jugador) usa la espada y si colisiona con el enemigo lo mata
            if(weapon == 1 && catched == 0 && input.IsLeftClickDown() && died != 2){
                sound.playEvent("event:/Efectos/ataque/Espada_sin_colision");
                posPlayer = cubePosition;

                // Comprobamos la dirección para establecer la posición de la espada
                if(direction == 1)
                    posPlayer.X += 3;
                else if(direction == 2)
                    posPlayer.X -= 3;
                else if(direction == 3)
                    posPlayer.Z += 3;
                else if(direction == 4)
                    posPlayer.Z -= 3;
                else if(direction == 5){
                    posPlayer.X += 3;
                    posPlayer.Z += 3;
                }
                else if(direction == 6){
                    posPlayer.X -= 3;
                    posPlayer.Z += 3;
                }
                else if(direction == 7){
                    posPlayer.X += 3;
                    posPlayer.Z -= 3;
                }
                else if(direction == 8){
                    posPlayer.X -= 3;
                    posPlayer.Z -= 3;
                }

                if(!smgr->getSceneNodeFromName("sword")){
                    object = smgr->addCubeSceneNode(3);
                    object->setName("sword");
                }

                smgr->getSceneNodeFromName("sword")->setPosition(posPlayer);
                // Comprobamos si la espada (sword) colisiona con algún enemigo en el vector enemies, si colisiona morirá
                for(unsigned int i = 0; i < enemies.size();i++){
                    if(smgr->getSceneNodeFromName("sword") && Irrlicht_t::checkCollisionEspada(object, enemies[i], direction)){
                        sound.playEvent("event:/Efectos/colisiones/corte");
                        enemies[i]->remove();
                        ranges[i]->remove();
                        for(unsigned int j = 0; j < collideables.size();j++){
                            if(collideables[j] == enemies[i]){
                                collideables.erase(collideables.begin() + j);
                                break;
                            }
                        }
                        enemies.erase(enemies.begin() + i);
                        ranges.erase(ranges.begin() + i);
                        posIniEnemies.erase(posIniEnemies.begin() + i);
                    }
                }
            }

            // Comprobamos si deja de presionar el ratón para eliminar la espada
            if(smgr->getSceneNodeFromName("sword") && !input.IsLeftClickDown()){
                //std::cout << "Entro" << std::endl;
                smgr->getSceneNodeFromName("sword")->remove();
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------- Colisión jugador-enemigo ------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            // Comprobamos si el cube_player (jugador) colisiona con algún enemigo en el vector enemies, si colisiona morirá
            for(unsigned int i = 0; i < enemies.size();i++){
                if(died != 1 && Irrlicht_t::checkCollisionObject(smgr->getSceneNodeFromName("cube_player"), enemies[i])){
                    //Colisionan
                    if(shield == 0){
                        hit_points -= 1;
                        updateHearts = true;
                        sound.playEvent("event:/Efectos/colisiones/herida");

                        comproveHP(cubePosition, false);
                    } 
                }
            }

            // Comprobamos si está muerto para cerrar la ventana si pulsa el botón
            if (hit_points == 0){
                //sound.playEvent("event:/Efectos/colisiones/muerte");

                smgr->getSceneNodeFromName("cube_player")->setMaterialTexture(0, driver->getTexture("media/color_player.jpg"));
                smgr->getSceneNodeFromName("cube_player")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

                // Borramos el escenario y lo cargamos desde el último checkpoint
                smgr->clear();
                smgr->loadScene(zoneToChange);
                fillVectors();
                
                if (input.IsKeyDown(irr::KEY_RETURN)){
                    died = 0;
                    //hit_points = 3;
                    loadGame();
                    updateHearts = true;
                    catched = 0;   // Sin coger
                    bomb = 0;   // Bomba sin poner
                    treeWindow->remove();
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
        
            //---------------------------------------------------- Interactuar con un NPC --------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            // Comprobamos si el cube_player (jugador) colisiona con algún bot en el vector npc, si colisiona hablará
            for(unsigned int i = 0; i < npcs.size();i++){
                if(!open && Irrlicht_t::checkCollisionObject(smgr->getSceneNodeFromName("cube_player"), npcs[i]) && input.IsKeyDown(irr::KEY_SPACE)){
                    if(npcs[i] == smgr->getSceneNodeFromName("npc_1")){
                        /*win = guienv->addWindow(irr::core::rect<int>(200,90,490,290), true, L"Hello", 0, 5);
                        win->getCloseButton()->setVisible(false);
                        guienv->addStaticText(L"Hello my name is Tom.\nYou need to get the yellow key to open the door.",irr::core::rect<int>(20,40,250,120), true, true, win);
                        const irr::core::rect<int> rect(100,140,170, 180);
                        btn = guienv->addButton( rect, win, 1, L"Press Enter", L"Continue");*/

                        died = 2; // Para que no se pueda mover hasta que se cierre el mensaje
                        open=true;

                        treeWindow = guienv->addTreeView(irr::core::rect<int>(20,760,1900,1060), 0, -1, false, false, false);
                        img = driver->getTexture("media/dialogue_npc.png");
                        if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, treeWindow, -1, L"Dialogue");
                        text =  L"Hello my name is Tom.\n"\
                                L"You need to get the yellow key to open the door.";
                        guienv->addStaticText(text, irr::core::rect<int>(50,50,1850,250), false, true, treeWindow);

                        break;
                    }
                    else if(npcs[i] == smgr->getSceneNodeFromName("npc_2")){
                        /*win = guienv->addWindow(irr::core::rect<int>(200,90,490,290), true, L"Hello", 0, 5);
                        win->getCloseButton()->setVisible(false);
                        guienv->addStaticText(L"Hello again!\nYou have to go to the left zone to get the key and then you will be able to open the door of the right zone.",irr::core::rect<int>(20,40,250,120), true, true, win);
                        const irr::core::rect<int> rect(100,140,170, 180);
                        btn = guienv->addButton( rect, win, 1, L"Press Enter", L"Continue");*/

                        died = 2; // Para que no se pueda mover hasta que se cierre el mensaje
                        open=true;

                        treeWindow = guienv->addTreeView(irr::core::rect<int>(20,760,1900,1060), 0, -1, false, false, false);
                        img = driver->getTexture("media/dialogue_npc.png");
                        if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, treeWindow, -1, L"Dialogue");
                        text =  L"Hello again!\n"\
                                L"You have to go to the left zone to get the key and then you will be able to open the door of the right zone.";
                        guienv->addStaticText(text, irr::core::rect<int>(50,50,1850,250), false, true, treeWindow);

                        break;
                    }
                }
            }
            
            if(open){
                if(input.IsKeyDown(irr::KEY_RETURN)){
                    open = false;
                    died = 0;  
                    //win->remove();
                    treeWindow->remove();
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            
            //--------------------------------------------------------- Disparo de una flecha ----------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            // Comprobamos si el jugador (cube_player) tiene flechas y si pulsa el espacio para dispararla y la creamos
            if (weapon == 3 && catched == 0 && arrows != 0 && input.IsLeftClickDown() && !smgr->getSceneNodeFromName("arrow") && died != 2){
                //std::cout << arrows << std::endl;
                sound.playEvent("event:/Efectos/ataque/soltar_flecha");
                arrows--;
                catched = 4;
                object = smgr->addSphereSceneNode(0.8);
                object->setName("arrow");
                irr::core::vector3df arrowPosition = cubePosition;

                // Comprobamos la dirección para establecer la posición inicial de la flecha
                if(direction == 1)
                    arrowPosition.X += 2;
                else if(direction == 2)
                    arrowPosition.X -= 2;
                else if(direction == 3)
                    arrowPosition.Z += 2;
                else if(direction == 4)
                    arrowPosition.Z -= 2;
                else if(direction == 5){
                    arrowPosition.X += 2;
                    arrowPosition.Z += 2;
                }
                else if(direction == 6){
                    arrowPosition.X -= 2;
                    arrowPosition.Z += 2;
                }
                else if(direction == 7){
                    arrowPosition.X += 2;
                    arrowPosition.Z -= 2;
                }
                else if(direction == 8){
                    arrowPosition.X -= 2;
                    arrowPosition.Z -= 2;
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
            if(smgr->getSceneNodeFromName("arrow")){
                // Le ponemos velocidad y la movemos
                irr::f32 arrowSpeed = 75.f;
                input.moveObject (smgr->getSceneNodeFromName("arrow"), arrowSpeed, frameDeltaTime, throw_direction);
                
                // Comprobamos si colisiona con algún enemigo
                for(unsigned int i = 0; i < enemies.size();i++){
                    if(Irrlicht_t::checkCollisionOneEnemy(smgr->getSceneNodeFromName("arrow"), enemies[i])){
                        sound.playEvent("event:/Efectos/colisiones/flecha");
                        // Si colisiona borramos la flecha y el enemigo
                        smgr->getSceneNodeFromName("arrow")->remove();
                        // Borramos el enemigo de la escena y del array de enemigos (enemies)
                        enemies[i]->remove();
                        ranges[i]->remove();
                        for(unsigned int j = 0; j < collideables.size();j++){
                            if(collideables[j] == enemies[i]){
                                collideables.erase(collideables.begin() + j);
                                break;
                            }
                        }
                        enemies.erase(enemies.begin() + i);
                        ranges.erase(ranges.begin() + i);
                        posIniEnemies.erase(posIniEnemies.begin() + i);
                        break;
                    }
                }

                // Comprobamos si colisiona con algún muro u objeto (siempre y cuando no sea NULL por haber colisionado con un enemigo)
                if(smgr->getSceneNodeFromName("arrow") && Irrlicht_t::checkCollisionCollideables(smgr->getSceneNodeFromName("arrow"), collideables)){
                    // Si colisiona borramos la flecha
                    sound.playEvent("event:/Efectos/colisiones/flecha");
                    smgr->getSceneNodeFromName("arrow")->remove();
                }

                catched = 0;
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
                
            //--------------------------------------------------------- Coger la llave (key) -----------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            //Comprobamos si el cube_player (jugador) colisiona con la key_1 (objeto llave) y así poder cogerlo si colisiona
            for(unsigned int i = 0; i < keys.size();i++){
                if(Irrlicht_t::checkCollisionObject(smgr->getSceneNodeFromName("cube_player"), keys[i])){
                    keys[i]->remove();
                    for(unsigned int j = 0; j < collideables.size();j++){
                        if(collideables[j] == keys[i]){
                            collideables.erase(collideables.begin() + j);
                            break;
                        }
                    }
                    keys.erase(keys.begin() + i);
                    key_gotcha++;
                    break;
                }
            }
            
            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //--------------------------------------------------------- Abrir el cofre (chest) -----------------------------------------------------------------
            //--------------------------------------------------------------------------------------------------------------------------------------------------

            // Si se está abriendo un cofre contamos frames para que no se pueda mover al instante
            if(died == 4){
                contFPS++;
                if(contFPS == 15){
                    contFPS = 0;
                    died = 0;
                }
            }

            //Comprobamos si el cube_player (jugador) colisiona con algún cofre (chest) y así poder cogerlo si colisiona
            for(unsigned int i = 0; i < chests.size();i++){
                if(catched == 0 && Irrlicht_t::checkCollisionObject(smgr->getSceneNodeFromName("cube_player"), chests[i]) && input.IsKeyDown(irr::KEY_SPACE)){
                    died = 4; // Cambiamos al estado a abriendo un cofre
                    chests[i]->remove();
                    for(unsigned int j = 0; j < collideables.size();j++){
                        if(collideables[j] == chests[i]){
                            collideables.erase(collideables.begin() + j);
                            break;
                        }
                    }
                    chests.erase(chests.begin() + i);
                    break;
                }
            }
            
            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //----------------------------------------------------- Coger y beber la poción (potion) ---------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            //Comprobamos si el cube_player (jugador) colisiona con la pocion y así poder cogerla si colisiona
            for(unsigned int i = 0; i < potions.size();i++){
                if(Irrlicht_t::checkCollisionObject(smgr->getSceneNodeFromName("cube_player"), potions[i])){
                    potions[i]->remove();
                    for(unsigned int j = 0; j < collideables.size();j++){
                        if(collideables[j] == potions[i]){
                            collideables.erase(collideables.begin() + j);
                            break;
                        }
                    }
                    potions.erase(potions.begin() + i);
                    potion_gotcha++;
                    break;
                }
            }

            //Beber pocion
            if(catched == 0 && weapon == 5 && potion_gotcha != 0 && input.IsLeftClickDown() && died != 4 && pause == false){
                if(hit_points < max_hp){
                    hit_points ++;
                    potion_gotcha--;
                    updateHearts = true; // Lo ponemos a true para actualizar el número de corazones
                    died = 3; // Para que no se mueva y no pueda beber las pociones seguidas
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------- Abrir puerta (door) -----------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            // Comprobamos si el cube_player (jugador) colisiona con el door(puerta del nivel) y así poder pasar
            for(unsigned int i = 0; i < doors.size();i++){
                if(Irrlicht_t::checkCollisionObject(smgr->getSceneNodeFromName("cube_player"), doors[i]) && key_gotcha != 0){
                    sound.playEvent("event:/Efectos/abrir_puerta");
                    doors[i]->remove();
                    for(unsigned int j = 0; j < collideables.size();j++){
                        if(collideables[j] == doors[i]){
                            collideables.erase(collideables.begin() + j);
                            break;
                        }
                    }
                    doors.erase(doors.begin() + i);
                    key_gotcha--;
                    break;
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            // Comprobamos si sigue pulsada la L para controlar la bomba
            isPressed = input.IsLeftClickDown();
            sound.studioUpdate();

            //-----------------------------------------------------------------------------------------------
            //-----------------------------------------MENU-PAUSE----------------------------------------------
            //-----------------------------------------------------------------------------------------------

            //std::cout << "died = ";
            //std::cout << died << std::endl;
            
            if(input.IsKeyDown(irr::KEY_ESCAPE) && !pause && died == 0){
                //win = guienv->addWindow(core::rect<int>(200,90,490,290), true, L"Menu", 0, 8);
                //win->setDrawBackground(true);
                pause = true;
                died = 2;
                //win = guienv->addWindow(irr::core::rect<int>(400,200,1500,900), false, 0, 0, 9);
                //win = guienv->addWindow(irr::core::rect<int>(0,0,0,0), false, 0, 0, 9);      
                //win->getCloseButton()->setVisible(false);
                treeWindow = guienv->addTreeView(irr::core::rect<int>(400,200,1500,900), 0, -1, false, false, false);
                img = driver->getTexture("media/pause.png");
                if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, treeWindow, -1, L"Pause");
                
                resumeButton = guienv->addButton(irr::core::rect<int>(400,200,700,300), treeWindow, 11, L"");
                img = driver->getTexture("media/btn_resume.png");
                if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, resumeButton, -1, L"Resume");

                loadButton = guienv->addButton(irr::core::rect<int>(400,350,700,450), treeWindow, 12, L"");
                img = driver->getTexture("media/btn_load.png");
                if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, loadButton, -1, L"Load");

                exitButton = guienv->addButton(irr::core::rect<int>(400,500,700,600), treeWindow, 13, L"");
                img = driver->getTexture("media/btn_exit.png");
                if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, exitButton, -1, L"Exit");

                //saveButton = guienv->addButton(irr::core::rect<int>(22,150,200,180),win,12, L"Save");
                //exitButton = guienv->addButton(irr::core::rect<int>(22,270,200,300),win,12, L"Exit");
            
            }

            if(pause){
                
                // Comprobamos si se ha cambiado btn_check para evitar que pulsando la tecla se pueda cambiar muy rápidamente en el menú
                if(btn_check != change_btn_check){
                    contFPS++;
                    if(contFPS == 8){
                        contFPS = 0;
                        // Actulizamos la variable auxiliar del cambio de botón
                        change_btn_check = btn_check;
                    }
                }

                else{
                    // Comprobamos si W o S para moverse por el menú
                    if(input.IsKeyDown(irr::KEY_KEY_S)){
                        btn_check++;
                        if(btn_check == 3) btn_check = 0;
                    }
                    else if(input.IsKeyDown(irr::KEY_KEY_W)){
                        btn_check--;
                        if(btn_check == -1) btn_check = 2;
                    }
                }

                // Comprobamos el botón seleccionado para cambiarle el color y reestablecer los colores
                if(btn_check == 0) {
                    img = driver->getTexture("media/btn_resume_check.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, resumeButton, -1, L"Resume");
                    img = driver->getTexture("media/btn_load.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, loadButton, -1, L"Load");
                    img = driver->getTexture("media/btn_exit.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, exitButton, -1, L"Exit");
                }
                else if(btn_check == 1) {
                    img = driver->getTexture("media/btn_resume.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, resumeButton, -1, L"Resume");
                    img = driver->getTexture("media/btn_load_check.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, loadButton, -1, L"Load");
                    img = driver->getTexture("media/btn_exit.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, exitButton, -1, L"Exit");
                }
                else if(btn_check == 2) {
                    img = driver->getTexture("media/btn_resume.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, resumeButton, -1, L"Resume");
                    img = driver->getTexture("media/btn_load.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, loadButton, -1, L"Load");
                    img = driver->getTexture("media/btn_exit_check.png");
                    if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, exitButton, -1, L"Exit");
                }

                // Comprobamos si pulsa enter y en que botón lo hace para realizar esa acción
                if(btn_check == 0 && input.IsKeyDown(irr::KEY_RETURN)){
                    treeWindow->remove();
                    pause = false;
                    died = 0;
                }
                /*else if(saveButton->isPressed()){
                    win->remove();
                    pause = false;
                    died = 0;
                    saveGame();
                }*/
                else if(btn_check == 1 && input.IsKeyDown(irr::KEY_RETURN)){
                    treeWindow->remove();
                    pause = false;
                    died = 0;
                    if(loadGame()) loadZone();
                    updateHearts = true;
                }
                else if(btn_check == 2 && input.IsKeyDown(irr::KEY_RETURN)){
                    treeWindow->remove();
                    device->closeDevice();
                    pause = false;
                    died = 0;
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //---------------------------------------------------- Mostrar corazones del jugador -------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            if(updateHearts){   // No haría falta este if ya que no pasa nada porque se actualice la imagen todo el rato
                for (int i = 0; i < max_hp+1; i++){
                    if(i == hit_points){
                        // Guardamos la ruta necesaria de la imagen en un string
                        std::string path = "media/salud/hp_" + std::to_string(i) + "_" + std::to_string(max_hp) + ".png";
                        const char* path2char = path.c_str();

                        // Cogemos la imagen y la añadimos
                        img = driver->getTexture(path2char);
                        if(img) guienv->addImage(img, irr::core::position2di(20, 20), true, 0, -1, L"HP");
                        updateHearts = false;
                        break;
                    }
                }
            }

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------

            //-------------------------------------------- Mostrar arma seleccionada del jugador -------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
            //if(updateHearts){   // No haría falta este if ya que no pasa nada porque se actualice la imagen todo el rato
                for (int i = 0; i < 6; i++){
                    if(i == weapon){
                        // Guardamos la ruta necesaria de la imagen en un string
                        std::string path = "media/weapons/weapon_" + std::to_string(i) + ".png";
                        const char* path2char = path.c_str();

                        // Cogemos la imagen y la añadimos
                        img = driver->getTexture(path2char);
                        if(img) guienv->addImage(img, irr::core::position2di(1700, 20), true, 0, -1, L"Weapon");
                        updateHearts = false;
                        break;
                    }
                }
            //}

            //------------------------------------------------------------------------------------------------------------------------------------------------
            //------------------------------------------------------------------------------------------------------------------------------------------------
        }

        //driver->draw2DImage(irrlichtBack,irr::core::position2d<int>(0,0));
        Irrlicht_t::render();
        driver->endScene();
		int fps = driver->getFPS();

        if (lastFPS != fps)
        {
            irr::core::stringw tmp(L"Prototype - SoulMirror [");
            tmp += driver->getName();
            tmp += L"] fps: ";
            tmp += fps;

            device->setWindowCaption(tmp.c_str());
            lastFPS = fps;
        }
    }
}

void Irrlicht_t::drop(){
	device->drop();
}

void Irrlicht_t::saveGame(){
    std::ofstream myfile ("soulMirror.dat");
    if (myfile.is_open()){
        myfile << weapon << '\n';
        myfile << hit_points << '\n';
        myfile << max_hp << '\n';
        myfile << direction << '\n';
        myfile << throw_direction << '\n';
        myfile << arrows << '\n';
        myfile << potion_gotcha << '\n';
        myfile << key_gotcha << '\n';
        myfile << zone << '\n';
        myfile << died << '\n';

        /*std::string name = "zone_" + std::to_string(zone) + ".irr";
        const char* nameToChar = name.c_str();

        // Guardamos la zona en el archivo
        smgr->saveScene(nameToChar);*/

        myfile.close();
    }
    else std::cout << "Unable to open file" << std::endl;
}

bool Irrlicht_t::loadGame(){
    bool open = false;
    int aux = 0;
    std::string line;
    std::ifstream myfile ("soulMirror.dat");
    if (myfile.is_open()){
        while (getline (myfile,line) ){
            std::cout << line << '\n';

            if(aux == 0) weapon = stoi(line);
            else if (aux == 1) hit_points = stoi(line);
            else if (aux == 2) max_hp = stoi(line);
            else if (aux == 3) direction = stoi(line);
            else if (aux == 4) throw_direction = stoi(line);
            else if (aux == 5) arrows = stoi(line);
            else if (aux == 6) potion_gotcha = stoi(line);
            else if (aux == 7) key_gotcha = stoi(line);
            else if (aux == 8) zone = stoi(line);
            else if (aux == 9) died = stoi(line);

            aux++;
        }
        myfile.close();
        open = true;
    }

    else std::cout << "Unable to open file" << std::endl;

    return open; 
}

void Irrlicht_t::loadZone(){
    // Borramos los objetos que no queremos guardar
    if (smgr->getSceneNodeFromName("sword"))
        smgr->getSceneNodeFromName("sword")->remove();
    
    if (smgr->getSceneNodeFromName("arrow"))
        smgr->getSceneNodeFromName("arrow")->remove();

    if (smgr->getSceneNodeFromName("bomba")){
        bomb = 0;
        smgr->getSceneNodeFromName("bomba")->remove();
    }

    if (smgr->getSceneNodeFromName("shield"))
        smgr->getSceneNodeFromName("shield")->remove();
    
    // Borramos el barril si lo tiene encima o está en el aire
    if (catched == 1 && barriles[pos_object]){
        barriles[pos_object]->remove();
        barriles.erase(barriles.begin() + pos_object);
    }

    else if (catched == 2 && barriles[pos_object]){
        barriles[pos_object]->remove();
        barriles.erase(barriles.begin() + pos_object);
    }

    // Ponemos a 0 la variable de coger para decir que no tiene ningún objeto cogido
    catched = 0;
    // Ponemos a 0 la variable del escudo para desprotegerlo
    shield = 0;

    std::string name = "zone_" + std::to_string(zone) + ".irr";
    const char* nameToChar = name.c_str();

    // Borramos la escena actual
    smgr->clear();

    // Cargamos el archivo de la zona correspondiente y llenamos los vectores
    smgr->loadScene(nameToChar);
    fillVectors();
}

void Irrlicht_t::fillVectors(){
    std::string name;
    const char* nameToChar;

    // Primero vaciamos los vectores
    collideables.clear();
    enemies.clear();
    ranges.clear();
    posIniEnemies.clear();
    keys.clear();
    doors.clear();
    gates.clear();
    potions.clear();
    barriles.clear();
    draggables.clear();
    buttons.clear();
    zones.clear();
    npcs.clear();
    chests.clear();


    // Metemos al jugador (cube_player) en el vector de collideables
    collideables.push_back(smgr->getSceneNodeFromName("cube_player"));

    // Inicializamos la posición inicial del jugador
    posInicio = smgr->getSceneNodeFromName("cube_player")->getPosition();

    for (unsigned int j = 0; j < names.size(); j++){
        for (unsigned int i = 1; i < 20; i++){
            name = names[j]; 
            name += std::to_string(i);
            nameToChar = name.c_str();
            object = smgr->getSceneNodeFromName(nameToChar);
            // Comprobamos si existe el objeto en la escena si no seguimos el for
            if(object){
                //std::cout << nameToChar << std::endl;
                // Añadimos el objeto a su vector correspondiente
                if(!(names[j] == "button_") && names[j] != "range_")
                    collideables.push_back(object);
                if(names[j] == "enemy_" || names[j] == "enemy_shoot_"){
                    enemies.push_back(object);
                    posIniEnemies.push_back(object->getPosition());
                }
                else if(names[j] == "range_")
                    ranges.push_back(object);
                else if(names[j] == "key_")
                    keys.push_back(object);
                else if(names[j] == "door_")
                    doors.push_back(object);
                else if(names[j] == "gate_")
                    gates.push_back(object);
                else if(names[j] == "potion_")
                    potions.push_back(object);
                else if(names[j] == "barril_")
                    barriles.push_back(object);
                else if(names[j] == "draggable_")
                    draggables.push_back(object);
                else if(names[j] == "button_")
                    buttons.push_back(object);
                else if(names[j] == "zone_")
                    zones.push_back(object);
                else if(names[j] == "npc_")
                    npcs.push_back(object);
                else if(names[j] == "chest_")
                    chests.push_back(object);
                
            } 
        }
    }

    for (unsigned int i = 1; i < 1000; i++){
        name = "pared_" + std::to_string(i); 
        nameToChar = name.c_str();
        object = smgr->getSceneNodeFromName(nameToChar);
        // Comprobamos si existe el objeto en la escena si no salimos del for
        if(!object)
            break;
        // Añadimos la pared a su vector correspondiente
        collideables.push_back(object);
    }
    
}

void Irrlicht_t::drawZone(const char* z, int pos_object){
    // Borramos los objetos que no queremos guardar
    if (smgr->getSceneNodeFromName("sword"))
        smgr->getSceneNodeFromName("sword")->remove();
    
    if (smgr->getSceneNodeFromName("arrow"))
        smgr->getSceneNodeFromName("arrow")->remove();

    if (smgr->getSceneNodeFromName("bomba")){
        bomb = 0;
        smgr->getSceneNodeFromName("bomba")->remove();
    }

    if (smgr->getSceneNodeFromName("shield"))
        smgr->getSceneNodeFromName("shield")->remove();
    
    // Borramos el barril si lo tiene encima o está en el aire
    if (catched == 1 && barriles[pos_object]){
        barriles[pos_object]->remove();
        barriles.erase(barriles.begin() + pos_object);
    }

    else if (catched == 2 && barriles[pos_object]){
        barriles[pos_object]->remove();
        barriles.erase(barriles.begin() + pos_object);
    }

    // Ponemos a 0 la variable de coger para decir que no tiene ningún objeto cogido
    catched = 0;
    // Ponemos a 0 la variable del escudo para desprotegerlo
    shield = 0;


    std::string name = "zone_" + std::to_string(zone) + ".irr";
    const char* nameToChar = name.c_str();

    // Guardamos la zona en el archivo
    smgr->saveScene(nameToChar);

    // Actualizamos la zona en la que estamos
    name = z;
    name = name.substr(name.find("_") + 1);
    name = name.substr(0, name.find("."));
    //std::cout << name << std::endl;
    zone = std::stoi(name);
    //std::cout << zone << std::endl;

    // Guardar la partida
    saveGame();

    // Borramos la escena actual
    smgr->clear();

    //std::cout << z << std::endl;

    // Cargamos el archivo de la zona correspondiente y llenamos los vectores
    smgr->loadScene(z);
    fillVectors();

}

void Irrlicht_t::comproveHP(irr::core::vector3df cubePosition, bool colBomba){
    irr::core::vector3df playerPositionNew;

    if(hit_points!=0){
        died = 1; // Estado golpeado
        
        /*playerPositionNew = cubePosition;

        if (!colBomba){
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
        }

        // Actualizamos la posición del jugador      
        smgr->getSceneNodeFromName("cube_player")->setPosition(playerPositionNew);*/

        // Cambiamos el color en el choque para que se note la detección de la colisión
        smgr->getSceneNodeFromName("cube_player")->setMaterialTexture(0, driver->getTexture("media/color_collision.jpg"));
        smgr->getSceneNodeFromName("cube_player")->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        
    }
    else{
        died = 2; // Estado muerto
        //smgr->getSceneNodeFromName("cube_player")->setPosition(posInicio);
        //win = guienv->addWindow(irr::core::rect<int>(200,90,490,290), true, L"Game Over", 0, 5);
        //win->getCloseButton()->setVisible(false);

        treeWindow = guienv->addTreeView(irr::core::rect<int>(400,200,1500,900), 0, -1, false, false, false);
        img = driver->getTexture("media/game_over.png");
        if(img) guienv->addImage(img, irr::core::position2di(0, 0), true, treeWindow, -1, L"Game over");
        
        //guienv->addStaticText(L"You died. \n Press enter to continue.",irr::core::rect<int>(20,40,250,120), true, true, win);
        
        //const irr::core::rect<int> rect(100,140,170, 180);
        //btn = guienv->addButton( rect, win, 1, L"Press Enter", L"Continue");
    }
}

void Irrlicht_t::endScene(){
	driver->endScene();
}

void Irrlicht_t::NodeLoadMaterial(){

    for(unsigned int i = 0; i < collideables.size();i++){
        collideables[i]->setMaterialTexture(0, driver->getTexture("media/color_pared.jpg"));
        collideables[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    smgr->getSceneNodeFromName("cube_player")->setMaterialTexture(0, driver->getTexture("media/color_player.jpg"));
    smgr->getSceneNodeFromName("cube_player")->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    
    for(unsigned int i = 0; i < enemies.size();i++){
        enemies[i]->setMaterialTexture(0, driver->getTexture("media/color_enemy.jpg"));
        enemies[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < barriles.size();i++){
        barriles[i]->setMaterialTexture(0, driver->getTexture("media/barril.jpg"));
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

    for(unsigned int i = 0; i < zones.size();i++){
        zones[i]->setMaterialTexture(0, driver->getTexture("media/color_zone.jpg"));
        zones[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < keys.size();i++){
        keys[i]->setMaterialTexture(0, driver->getTexture("media/color_key.jpg"));
        keys[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < doors.size();i++){
        doors[i]->setMaterialTexture(0, driver->getTexture("media/color_door.jpg"));
        doors[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < gates.size();i++){
        gates[i]->setMaterialTexture(0, driver->getTexture("media/color_gate.jpg"));
        gates[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < potions.size();i++){
        potions[i]->setMaterialTexture(0, driver->getTexture("media/color_potion.jpg"));
        potions[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < npcs.size();i++){
        npcs[i]->setMaterialTexture(0, driver->getTexture("media/color_npc.jpg"));
        npcs[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    for(unsigned int i = 0; i < chests.size();i++){
        chests[i]->setMaterialTexture(0, driver->getTexture("media/color_chest.jpg"));
        chests[i]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    smgr->getSceneNodeFromName("suelo")->setMaterialTexture(0, driver->getTexture("media/color_suelo.jpg"));
    smgr->getSceneNodeFromName("suelo")->setMaterialFlag(irr::video::EMF_LIGHTING, false);

}

void Irrlicht_t::addCamera(){

	//smgr->addCameraSceneNode(0, vector3df(0,30,-40), cube_player->getPosition());
    //ICameraSceneNode *camera = smgr->getActiveCamera();
    irr::core::vector3df camaraPosition;
    camaraPosition.X = smgr->getSceneNodeFromName("cube_player")->getPosition().X;
    camaraPosition.Y = 40; // 40 default
    camaraPosition.Z = smgr->getSceneNodeFromName("cube_player")->getPosition().Z - 15;
    
    if(!SwitchCam){
        smgr->getActiveCamera()->setPosition(camaraPosition);
        smgr->getActiveCamera()->setTarget(smgr->getSceneNodeFromName("cube_player")->getPosition());
    }
    else
        camera->setPosition(smgr->getSceneNodeFromName("cube_player")->getPosition());
    //camera->bindTargetAndRotation(true);
    //if(camera != NULL)
      //  cout<<"siuuu";
    //ICameraSceneNode camera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

    //scamera = smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));

}

//irr::core::vector3df spherePosition = input.moveSphere(time, MOVEMENT_SPEED, cube_player,sphere);

bool Irrlicht_t::getDeviceRun() const{
    return device->run();
}

irr::IrrlichtDevice* Irrlicht_t::getDevice(){
	return device;
}

irr::scene::IAnimatedMesh* Irrlicht_t::getMesh(){
	return mesh;
}

irr::scene::IAnimatedMeshSceneNode* Irrlicht_t::getNode(){
	return node;
}

irr::scene::ISceneNode* Irrlicht_t::getCube(){
	return smgr->getSceneNodeFromName("cube_player");
}

//FUNCIONES DE LAS COLISIONES

bool Irrlicht_t::checkCollision(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two){
   irr::core::aabbox3d<irr::f32> b1, b2, b3;
   
   b1 = one->getBoundingBox ();

   b2 = two->getBoundingBox ();

   
   one->getRelativeTransformation().transformBoxEx( b1 );
   two->getRelativeTransformation().transformBoxEx( b2 );
   return b1.intersectsWithBox( b2 );
}


bool Irrlicht_t::checkCollisionCollideables(irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> collideables){
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = one->getBoundingBox ();

   //b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   //two->getRelativeTransformation().transformBoxEx( b2 );
   for(unsigned int i = 0; i < collideables.size();i++){
      if(collideables[i] != one){
         b2 = collideables[i]->getBoundingBox();
         collideables[i]->getRelativeTransformation().transformBoxEx(b2);
         if(b1.intersectsWithBox(b2)){
            return true;
         }
      }
   }
   return false;
}


bool Irrlicht_t::checkCollisionOneEnemy(irr::scene::ISceneNode* one, irr::scene::ISceneNode* enemy){
   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = one->getBoundingBox ();
   b2 = enemy->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   enemy->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }

   return col;
}

bool Irrlicht_t::checkCollisionObject(irr::scene::ISceneNode* cube_player, irr::scene::ISceneNode* object){
    irr::core::vector3df posCube = cube_player->getPosition();
    bool col = false;

    irr::core::vector3df posCubeM = irr::core::vector3df(posCube.X+0.5,posCube.Y,posCube.Z);
    cube_player->setPosition(posCubeM);
    if(checkCollision(cube_player,object))
        col = true;

    posCubeM = irr::core::vector3df(posCube.X-0.5,posCube.Y,posCube.Z);
    cube_player->setPosition(posCubeM);
    if(checkCollision(cube_player,object))
        col = true;

    posCubeM = irr::core::vector3df(posCube.X,posCube.Y,posCube.Z+0.5);
    cube_player->setPosition(posCubeM);
    if(checkCollision(cube_player,object))
        col = true;

    posCubeM = irr::core::vector3df(posCube.X,posCube.Y,posCube.Z-0.5);
    cube_player->setPosition(posCubeM);
    if(checkCollision(cube_player,object))
        col = true;

    cube_player->setPosition(posCube);
    return col;
}

int Irrlicht_t::checkCollisionZone(irr::scene::ISceneNode* cube_player, irr::scene::ISceneNode* zone){
    irr::core::vector3df posCube = cube_player->getPosition();
    int col = 0;

    irr::core::vector3df posCubeM = irr::core::vector3df(posCube.X+0.5,posCube.Y,posCube.Z);
    cube_player->setPosition(posCubeM);
    if(checkCollision(cube_player,zone))
        col = 1;

    posCubeM = irr::core::vector3df(posCube.X-0.5,posCube.Y,posCube.Z);
    cube_player->setPosition(posCubeM);
    if(checkCollision(cube_player,zone))
        col = 2;

    posCubeM = irr::core::vector3df(posCube.X,posCube.Y,posCube.Z+0.5);
    cube_player->setPosition(posCubeM);
    if(checkCollision(cube_player,zone))
        col = 3;

    posCubeM = irr::core::vector3df(posCube.X,posCube.Y,posCube.Z-0.5);
    cube_player->setPosition(posCubeM);
    if(checkCollision(cube_player,zone))
        col = 4;

    cube_player->setPosition(posCube);
    return col;
}

bool Irrlicht_t::checkCollisionEspada(irr::scene::ISceneNode* sword, irr::scene::ISceneNode* enemy, int direction){
   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = sword->getBoundingBox ();
   b2 = enemy->getBoundingBox ();

   sword->getRelativeTransformation().transformBoxEx( b1 );
   enemy->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }
   
   return col;
}

bool Irrlicht_t::checkPressedButton(irr::scene::ISceneNode* player, irr::scene::ISceneNode* draggable, std::vector<irr::scene::ISceneNode*> buttons){
    bool col = false;
    irr::core::vector3df posButton, posDraggable;
    irr::core::aabbox3d<irr::f32> b1, b2, b3;

    posDraggable = draggable->getPosition();

    b1 = draggable->getBoundingBox ();
    b3 = player->getBoundingBox ();

    draggable->getRelativeTransformation().transformBoxEx( b1 );
    player->getRelativeTransformation().transformBoxEx( b3 );
    
    for(unsigned int i = 0; i < buttons.size();i++){
        posButton = buttons[i]->getPosition();
        b2 = buttons[i]->getBoundingBox ();
        buttons[i]->getRelativeTransformation().transformBoxEx( b2 );
        if(b1.intersectsWithBox(b2)){
            draggable->setPosition(posButton);

            // Volvemos a calcular el bounding box en la posición nueva para compararla con el jugador
            b1 = draggable->getBoundingBox ();
            draggable->getRelativeTransformation().transformBoxEx( b1 );

            if(b1.intersectsWithBox(b3)){
                col = false;
                draggable->setPosition(posDraggable);
                break;
            }
            else{
                col = true;
                break;
            }
        }
    }
    return col;
}

bool Irrlicht_t::checkCollisionBomba(irr::scene::ISceneNode* bomba, irr::scene::ISceneNode* enemy){
   bomba->setScale(irr::core::vector3df(6.0f,6.0f,6.0f));
   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = bomba->getBoundingBox ();
   b2 = enemy->getBoundingBox ();

   bomba->getRelativeTransformation().transformBoxEx( b1 );
   enemy->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }
   return col;
}

bool Irrlicht_t::checkCollisionPlayerBomb(irr::scene::ISceneNode* bomba, irr::scene::ISceneNode* cube_player){
   bomba->setScale(irr::core::vector3df(6.0f,6.0f,6.0f));

   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = bomba->getBoundingBox ();
   b2 = cube_player->getBoundingBox ();

   bomba->getRelativeTransformation().transformBoxEx( b1 );
   cube_player->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }
   return col;
}



bool Irrlicht_t::checkCollisionEnemiesPlayer(irr::scene::ISceneNode* range, irr::scene::ISceneNode* cube_player){
   
   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = range->getBoundingBox ();
   b2 = cube_player->getBoundingBox ();

   range->getRelativeTransformation().transformBoxEx( b1 );
   cube_player->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }
   //enemy->setScale(irr::core::vector3df(-8.0f, -8.0f, -8.0f));
   return col;
}


void Irrlicht_t::render(){
    smgr->drawAll();
    guienv->drawAll();
}


//Funciones INPUT
Input::Input(){
	for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
    LeftClickDown = false;
}

bool Input::OnEvent(const irr::SEvent& event){
    bool press = false;
	// Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    // Remember the mouse state
    if (event.EventType == irr::EET_MOUSE_INPUT_EVENT){
        /*switch(event.MouseInput.Event)
        {
            case EMIE_LMOUSE_PRESSED_DOWN:
                press = true;
                //std::cout<<"Entro en el click" <<std::endl;
                break;

            case EMIE_LMOUSE_LEFT_UP:
                press = false;
                break;

            default:
				// We won't use the wheel
				break;
        }*/
        LeftClickDown = event.MouseInput.isLeftPressed();
    }

    return press;
}

// This is used to check whether a key is being held down
bool Input::IsKeyDown(irr::EKEY_CODE keyCode) const {
    return KeyIsDown[keyCode];
}

// This is used to check the left clck (mouse)
bool Input::IsLeftClickDown() const{
    return LeftClickDown;
}

irr::core::vector3df Input::comproveMovement(irr::scene::ISceneManager* smgr, irr::f32 MOVEMENT_SPEED, irr::f32 frameDeltaTime,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> collideables, int died, irr::video::IVideoDriver* driver){
    
    bool colisiona;
    irr::core::vector3df cubePosition = smgr->getSceneNodeFromName("cube_player")->getPosition();
    float posAux = 0.0;

    if (died == 0 || died == 1){
        irr::core::vector3df posicionActualX = irr::core::vector3df(cubePosition.X+0.5,cubePosition.Y,cubePosition.Z);
        one->setPosition(posicionActualX);
        

        if(IsKeyDown(irr::KEY_KEY_D)){
            colisiona = Irrlicht_t::checkCollisionCollideables(one,collideables);
            if(!colisiona){
            //std::cout<<"ha entrado en d solo" <<std::endl;
                one->setRotation(irr::core::vector3df(0,90,0));
                posAux = cubePosition.X; 
                posAux += MOVEMENT_SPEED * frameDeltaTime;
                //posAux = round(posAux * 10);
                posAux = trunc(posAux * 10);
                posAux = posAux/10;
                cubePosition.X = posAux;
            }
        }

        posicionActualX = irr::core::vector3df(cubePosition.X-0.5,cubePosition.Y,cubePosition.Z);
        one->setPosition(posicionActualX);

        if(IsKeyDown(irr::KEY_KEY_A)){
            colisiona = Irrlicht_t::checkCollisionCollideables(one,collideables);
            if(!colisiona){
                one->setRotation(irr::core::vector3df(0,-90,0));
                posAux = cubePosition.X; 
                posAux -= MOVEMENT_SPEED * frameDeltaTime;
                //posAux = round(posAux * 10);
                posAux = trunc(posAux * 10);
                posAux = posAux/10;
                cubePosition.X = posAux;
            }
        }

        irr::core::vector3df posicionActualZ = irr::core::vector3df(cubePosition.X,cubePosition.Y,cubePosition.Z+0.5);
        one->setPosition(posicionActualZ);

        if(IsKeyDown(irr::KEY_KEY_W)){
            colisiona = Irrlicht_t::checkCollisionCollideables(one,collideables);
            if(!colisiona){
                one->setRotation(irr::core::vector3df(0,0,0));
                posAux = cubePosition.Z; 
                posAux += MOVEMENT_SPEED * frameDeltaTime;
                //posAux = round(posAux * 10);
                posAux = trunc(posAux * 10);
                posAux = posAux/10;
                cubePosition.Z = posAux;
            }
        }

        posicionActualZ = irr::core::vector3df(cubePosition.X,cubePosition.Y,cubePosition.Z-0.5);
        one->setPosition(posicionActualZ);

        if(IsKeyDown(irr::KEY_KEY_S)){
            colisiona = Irrlicht_t::checkCollisionCollideables(one,collideables);
            if(!colisiona){
                one->setRotation(irr::core::vector3df(0,180,0));              
                posAux = cubePosition.Z; 
                posAux -= MOVEMENT_SPEED * frameDeltaTime;
                //posAux = round(posAux * 10);
                posAux = trunc(posAux * 10);
                posAux = posAux/10;
                cubePosition.Z = posAux;
            }
        }

        /*if(IsKeyDown(irr::KEY_KEY_D) && IsKeyDown(irr::KEY_KEY_W)){ //diagonal derecha arriba
            colisiona = RavenGraphics::checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
            std::cout<<"ha entrado en d y w" <<std::endl;
                one->setRotation(core::vector3df(0,45,0));              
            }
        }

        if(IsKeyDown(irr::KEY_KEY_D) && IsKeyDown(irr::KEY_KEY_S)){ //diagonal derecha abajo
            colisiona = RavenGraphics::checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,135,0));              
            }
        }

        if(IsKeyDown(irr::KEY_KEY_A) && IsKeyDown(irr::KEY_KEY_W)){ //diagonal izquierda arriba
            colisiona = RavenGraphics::checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,315,0));              
            }
        }

        if(IsKeyDown(irr::KEY_KEY_A) && IsKeyDown(irr::KEY_KEY_S)){ //diagonal izquierda abajo
            colisiona = RavenGraphics::checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,225,0));              
            }
        }*/

        /*bool espadaF = false;
        if(IsKeyDown(irr::KEY_SPACE)){
            colisiona = RavenGraphics::checkCollisionEnemies(smgr,one,p);
            if(colisiona){
            scene::ISceneNode* espada = smgr->addCubeSceneNode(); 
            const irr::core::vector3df pos = one->getPosition();
            espada->setPosition(pos);    
            espadaF = true;
            }
            if(espadaF){

            }

        }*/
    }
    
    return cubePosition;
}

//bool Input::moveCam(bool SwitchCam, irr::scene::ISceneNode *map){
//    if(IsKeyDown(irr::KEY_KEY_P)){
//        if(SwitchCam)
//            SwitchCam = false;
//        else
//            SwitchCam = true;
//    }
//
//    return SwitchCam;
//}

void Input::moveDraggable(irr::scene::ISceneManager* smgr, irr::scene::ISceneNode* draggable, irr::f32 MOVEMENT_SPEED, irr::f32 frameDeltaTime, std::vector<irr::scene::ISceneNode*> collideables){
    irr::core::vector3df pos = draggable->getPosition();
    bool colisiona;

    irr::core::vector3df posicionActualZ = pos;
    irr::core::vector3df posicionActualX = pos;

    if(IsKeyDown(irr::KEY_KEY_W)){
        // Actualizamos la posición para ver si colisiona en una posición adelantada
        posicionActualZ.Z += 0.5;
        draggable->setPosition(posicionActualZ);
        // Comprobamos la colisión
        colisiona = Irrlicht_t::checkCollisionCollideables(draggable, collideables);
        if (!colisiona)
            pos.Z += MOVEMENT_SPEED * frameDeltaTime;   
    }

    else if(IsKeyDown(irr::KEY_KEY_S)){
        // Actualizamos la posición para ver si colisiona en una posición adelantada
        posicionActualZ.Z -= 0.5;
        draggable->setPosition(posicionActualZ);
        // Comprobamos la colisión
        colisiona = Irrlicht_t::checkCollisionCollideables(draggable, collideables);
        if (!colisiona)
            pos.Z -= MOVEMENT_SPEED * frameDeltaTime;
    }

    if(IsKeyDown(irr::KEY_KEY_A)){
        // Actualizamos la posición para ver si colisiona en una posición adelantada
        posicionActualX.X -= 0.5;
        draggable->setPosition(posicionActualX);
        // Comprobamos la colisión
        colisiona = Irrlicht_t::checkCollisionCollideables(draggable, collideables);
        if (!colisiona)
            pos.X -= MOVEMENT_SPEED * frameDeltaTime;
    }

    else if(IsKeyDown(irr::KEY_KEY_D)){
        // Actualizamos la posición para ver si colisiona en una posición adelantada
        posicionActualX.X += 0.5;
        draggable->setPosition(posicionActualX);
        // Comprobamos la colisión
        colisiona = Irrlicht_t::checkCollisionCollideables(draggable, collideables);
        if (!colisiona)
            pos.X += MOVEMENT_SPEED * frameDeltaTime;
        //else
        //    std::cout << "Colisiono" << std::endl;
    }

    draggable->setPosition(pos);
}

void Input::moveObject (irr::scene::ISceneNode* object, irr::f32 MOVEMENT_SPEED, irr::f32 frameDeltaTime, int direction){
    irr::core::vector3df pos = object->getPosition();
    
    //std::cout<<"ha entrado en moveObject solo" <<std::endl;

    // Comprobamos la dirección para establecer la posición siguiente del objeto (object)
    if(direction == 1)
        pos.X += MOVEMENT_SPEED * frameDeltaTime;
    else if(direction == 2)
        pos.X -= MOVEMENT_SPEED * frameDeltaTime;
    else if(direction == 3)
        pos.Z += MOVEMENT_SPEED * frameDeltaTime;
    else if(direction == 4)
        pos.Z -= MOVEMENT_SPEED * frameDeltaTime;
    else if(direction == 5){
        pos.X += MOVEMENT_SPEED * frameDeltaTime;
        pos.Z += MOVEMENT_SPEED * frameDeltaTime;
    }
    else if(direction == 6){
        pos.X -= MOVEMENT_SPEED * frameDeltaTime;
        pos.Z += MOVEMENT_SPEED * frameDeltaTime;
    }
    else if(direction == 7){
        pos.X += MOVEMENT_SPEED * frameDeltaTime;
        pos.Z -= MOVEMENT_SPEED * frameDeltaTime;
    }
    else if(direction == 8){
        pos.X -= MOVEMENT_SPEED * frameDeltaTime;
        pos.Z -= MOVEMENT_SPEED * frameDeltaTime;
    }

    // Actualizamos la posición de la felcha (arrow)
    object->setPosition(pos); 
}
//void Input::printXYZ(scene::ISceneNode *cube){
//    int x,y,z;
//    if(IsKeyDown(irr::KEY_KEY_C)){
//        x = cube->getPosition().X;
//        y = cube->getPosition().Y;
//        z = cube->getPosition().Z;
//    }
//    std::cout<<"COOR X = " << x << "COOR Y = " << y << "COOR Z = " << z<<std::endl;
//}
void Input::moveEnemy(int died, irr::scene::ISceneNode* enemy, irr::core::vector3df pos, irr::f32 MOVEMENT_SPEED_ENEMY, irr::f32 frameDeltaTime, std::vector<irr::scene::ISceneNode*> collideables){
    irr::core::vector3df posEnemy = enemy->getPosition();
    irr::core::vector3df posicionActualX;
    irr::core::vector3df posicionActualZ;
    float posAux = 0.0;

    if (died == 0){
        posicionActualX = irr::core::vector3df(posEnemy.X-0.5,posEnemy.Y,posEnemy.Z);
        enemy->setPosition(posicionActualX);
        bool colisionaX1 = Irrlicht_t::checkCollisionCollideables(enemy, collideables);

        posicionActualX = irr::core::vector3df(posEnemy.X+0.5,posEnemy.Y,posEnemy.Z);
        enemy->setPosition(posicionActualX);
        bool colisionaX2 = Irrlicht_t::checkCollisionCollideables(enemy, collideables);

        posicionActualZ = irr::core::vector3df(posEnemy.X,posEnemy.Y,posEnemy.Z-0.5);
        enemy->setPosition(posicionActualZ);
        bool colisionaZ1 = Irrlicht_t::checkCollisionCollideables(enemy, collideables);

        posicionActualZ = irr::core::vector3df(posEnemy.X,posEnemy.Y,posEnemy.Z+0.5);
        enemy->setPosition(posicionActualZ);
        bool colisionaZ2 = Irrlicht_t::checkCollisionCollideables(enemy, collideables);
        //bool choca = false;
        
        /*if(pos.X != posEnemy.X && pos.Z != posEnemy.Z &&  colisionaX2 && colisionaZ2){
            std::cout << "Entro en el primer if" << std::endl;
            posEnemy.Z -= MOVEMENT_SPEED_ENEMY * frameDeltaTime;

        }*/

        //if(pos.Z <= posEnemy.Z || colisionaX1 || colisionaX2){
        if(pos.Z < posEnemy.Z){
            if (!colisionaZ1){
                posAux = posEnemy.Z; 
                posAux -= MOVEMENT_SPEED_ENEMY * frameDeltaTime;
                //posAux = round(posAux * 10);
                posAux = trunc(posAux * 10);
                posAux = posAux/10;
                posEnemy.Z = posAux;
            }
        }
        else if(pos.Z > posEnemy.Z ){
            if (!colisionaZ2){
                posAux = posEnemy.Z; 
                posAux += MOVEMENT_SPEED_ENEMY * frameDeltaTime;
                //posAux = round(posAux * 10);
                posAux = trunc(posAux * 10);
                posAux = posAux/10;
                posEnemy.Z = posAux;
            }
        }

        //if(pos.X <= posEnemy.X || colisionaZ1 || colisionaZ2){
        if(pos.X < posEnemy.X){
            if (!colisionaX1){
                posAux = posEnemy.X; 
                posAux -= MOVEMENT_SPEED_ENEMY * frameDeltaTime;
                //posAux = round(posAux * 10);
                posAux = trunc(posAux * 10);
                posAux = posAux/10;
                posEnemy.X = posAux;
            }
        }
        else if(pos.X > posEnemy.X){
            if (!colisionaX2){
                posAux = posEnemy.X; 
                posAux += MOVEMENT_SPEED_ENEMY * frameDeltaTime;
                //posAux = round(posAux * 10);
                posAux = trunc(posAux * 10);
                posAux = posAux/10;
                posEnemy.X = posAux;
            }

        }
    }

    enemy->setPosition(posEnemy);
}

/*void Input::moveEnemyPosIni(int died, irr::scene::ISceneNode* enemy, irr::core::vector3df posIni, irr::f32 MOVEMENT_SPEED_ENEMY, irr::f32 frameDeltaTime, std::vector<irr::scene::ISceneNode*> collideables){
    
    irr::core::vector3df posEnemy = enemy->getPosition();

    if(died == 0){
        if(!Irrlicht_t::checkCollisionCollideables(enemy, collideables)){
            if(posIni.X != posEnemy.X){
                if(posIni.X < posEnemy.X){
                    posEnemy.X -= MOVEMENT_SPEED_ENEMY * frameDeltaTime;
                }
                else{
                    posEnemy.X += MOVEMENT_SPEED_ENEMY * frameDeltaTime;
                }
            }
            if(posIni.Z != posEnemy.Z){
                if(posIni.Z < posEnemy.Z){
                    posEnemy.Z -= MOVEMENT_SPEED_ENEMY * frameDeltaTime;
                }
                else{
                    posEnemy.Z += MOVEMENT_SPEED_ENEMY * frameDeltaTime;
                }
            }
        }
    }
    
    enemy->setPosition(posEnemy);
}*/
