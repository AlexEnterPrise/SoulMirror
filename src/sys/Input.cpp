#include "Input.hpp"

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

irr::core::vector3df Input::comproveMovement(irr::scene::ISceneManager* smgr, irr::f32 MOVEMENT_SPEED, irr::f32 frameDeltaTime,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> collideables, bool died, irr::video::IVideoDriver* driver){
    if(IsKeyDown(irr::KEY_LSHIFT) || IsKeyDown(irr::KEY_RSHIFT)){
        MOVEMENT_SPEED = 40.f;
    }

    bool colisiona;
    irr::core::vector3df cubePosition = smgr->getSceneNodeFromName("cube_player")->getPosition();

    if (died == 0){
        irr::core::vector3df posicionActualX = irr::core::vector3df(cubePosition.X+0.5,cubePosition.Y,cubePosition.Z);
        one->setPosition(posicionActualX);
        

        if(IsKeyDown(irr::KEY_KEY_D)){
            colisiona = col.checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
            //std::cout<<"ha entrado en d solo" <<std::endl;
                one->setRotation(core::vector3df(0,90,0));
                cubePosition.X += MOVEMENT_SPEED * frameDeltaTime;
            }
        }

        posicionActualX = irr::core::vector3df(cubePosition.X-0.5,cubePosition.Y,cubePosition.Z);
        one->setPosition(posicionActualX);

        if(IsKeyDown(irr::KEY_KEY_A)){
            colisiona = col.checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,-90,0));
                cubePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
            }
        }

        irr::core::vector3df posicionActualZ = irr::core::vector3df(cubePosition.X,cubePosition.Y,cubePosition.Z+0.5);
        one->setPosition(posicionActualZ);

        if(IsKeyDown(irr::KEY_KEY_W)){
            colisiona = col.checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,0,0));
                cubePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
            }
        }

        posicionActualZ = irr::core::vector3df(cubePosition.X,cubePosition.Y,cubePosition.Z-0.5);
        one->setPosition(posicionActualZ);

        if(IsKeyDown(irr::KEY_KEY_S)){
            colisiona = col.checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,180,0));              
                cubePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
            }
        }

        /*if(IsKeyDown(irr::KEY_KEY_D) && IsKeyDown(irr::KEY_KEY_W)){ //diagonal derecha arriba
            colisiona = col.checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
            std::cout<<"ha entrado en d y w" <<std::endl;
                one->setRotation(core::vector3df(0,45,0));              
            }
        }

        if(IsKeyDown(irr::KEY_KEY_D) && IsKeyDown(irr::KEY_KEY_S)){ //diagonal derecha abajo
            colisiona = col.checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,135,0));              
            }
        }

        if(IsKeyDown(irr::KEY_KEY_A) && IsKeyDown(irr::KEY_KEY_W)){ //diagonal izquierda arriba
            colisiona = col.checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,315,0));              
            }
        }

        if(IsKeyDown(irr::KEY_KEY_A) && IsKeyDown(irr::KEY_KEY_S)){ //diagonal izquierda abajo
            colisiona = col.checkCollisionCollideables(smgr,one,collideables);
            if(!colisiona){
                one->setRotation(core::vector3df(0,225,0));              
            }
        }*/

        /*bool espadaF = false;
        if(IsKeyDown(irr::KEY_SPACE)){
            colisiona = col.checkCollisionEnemies(smgr,one,p);
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
        colisiona = col.checkCollisionCollideables(smgr,draggable, collideables);
        if (!colisiona)
            pos.Z += MOVEMENT_SPEED * frameDeltaTime;   
    }

    else if(IsKeyDown(irr::KEY_KEY_S)){
        // Actualizamos la posición para ver si colisiona en una posición adelantada
        posicionActualZ.Z -= 0.5;
        draggable->setPosition(posicionActualZ);
        // Comprobamos la colisión
        colisiona = col.checkCollisionCollideables(smgr,draggable, collideables);
        if (!colisiona)
            pos.Z -= MOVEMENT_SPEED * frameDeltaTime;
    }

    if(IsKeyDown(irr::KEY_KEY_A)){
        // Actualizamos la posición para ver si colisiona en una posición adelantada
        posicionActualX.X -= 0.5;
        draggable->setPosition(posicionActualX);
        // Comprobamos la colisión
        colisiona = col.checkCollisionCollideables(smgr,draggable, collideables);
        if (!colisiona)
            pos.X -= MOVEMENT_SPEED * frameDeltaTime;
    }

    else if(IsKeyDown(irr::KEY_KEY_D)){
        // Actualizamos la posición para ver si colisiona en una posición adelantada
        posicionActualX.X += 0.5;
        draggable->setPosition(posicionActualX);
        // Comprobamos la colisión
        colisiona = col.checkCollisionCollideables(smgr,draggable, collideables);
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
