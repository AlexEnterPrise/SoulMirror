#include "Input.hpp"

Input::Input(){
	for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
}

bool Input::OnEvent(const irr::SEvent& event){
	// Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

        else if(event.EventType == irr::EET_GUI_EVENT){
            s32 id = event.GUIEvent.Caller->getID();
            if(event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED){
            //if(irr::EET_GUI_EVENT == irr::gui::EGET_BUTTON_CLICKED )
                std::cout<<"el id del boton es: "<< id <<std::endl;
                if(id == 3){
                    //event.GUIEvent.Caller->setID(-1);
                    event.GUIEvent.Caller->remove();
                    samorio = false;
                }
            }
        }
        
        return false;

}

bool Input::getSamorio(){
    return samorio;
}

void Input::setSamorio(bool x){
    samorio = x;
}

// This is used to check whether a key is being held down
bool Input::IsKeyDown(irr::EKEY_CODE keyCode) const {
    return KeyIsDown[keyCode];
}


irr::core::vector3df Input::comproveMovement(irr::scene::ISceneManager* smgr,irr::core::vector3df cubePosition, irr::f32 MOVEMENT_SPEED, irr::f32 frameDeltaTime,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p, bool died){
    if(IsKeyDown(irr::KEY_LSHIFT)){
        MOVEMENT_SPEED = 30.f;
    }
    
    if (!died){
        irr::core::vector3df posicionActualX = irr::core::vector3df(cubePosition.X+0.5,cubePosition.Y,cubePosition.Z);
        irr::core::vector3df posicionActualZ = irr::core::vector3df(cubePosition.X,cubePosition.Y,cubePosition.Z+0.5);
        one->setPosition(posicionActualX);
        bool colisiona;

        if(IsKeyDown(irr::KEY_KEY_D)){
            colisiona = col.checkCollisionWalls(smgr,one,p);
            if(colisiona == false){
                cubePosition.X += MOVEMENT_SPEED * frameDeltaTime;
            }
        }

        posicionActualX = irr::core::vector3df(cubePosition.X-0.5,cubePosition.Y,cubePosition.Z);
        one->setPosition(posicionActualX);

        if(IsKeyDown(irr::KEY_KEY_A)){
            colisiona = col.checkCollisionWalls(smgr,one,p);
            if(colisiona == false){
                cubePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
            }
        }
        
        one->setPosition(posicionActualZ);

        if(IsKeyDown(irr::KEY_KEY_W)){
            colisiona = col.checkCollisionWalls(smgr,one,p);
            if(colisiona == false){
                cubePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
            }
        }

        posicionActualZ = irr::core::vector3df(cubePosition.X,cubePosition.Y,cubePosition.Z-0.5);
        one->setPosition(posicionActualZ);

        if(IsKeyDown(irr::KEY_KEY_S)){
            colisiona = col.checkCollisionWalls(smgr,one,p);
            if(colisiona == false){
                cubePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
            }
        }

    }
    
    return cubePosition;
}

bool Input::moveCam(bool SwitchCam, irr::scene::ISceneNode *map){
    if(IsKeyDown(irr::KEY_KEY_P)){
        if(SwitchCam)
            SwitchCam = false;
        else
            SwitchCam = true;
    }

    return SwitchCam;
}


void Input::moveSphere(irr::f32 time, irr::f32 speed, irr::scene::ISceneNode* cube_player, irr::scene::ISceneNode* sphere){
    irr::core::vector3df spherePosition;
    spherePosition.X = sphere->getPosition().X;
    spherePosition.Y = sphere->getPosition().Y;
    spherePosition.Z = sphere->getPosition().Z;
    if(IsKeyDown(irr::KEY_KEY_W)){
        if(cube_player->getPosition().Z < sphere->getPosition().Z)
            spherePosition.Z += speed * time + 0.5;    
    }

    else if(IsKeyDown(irr::KEY_KEY_S)){
        if(cube_player->getPosition().Z > sphere->getPosition().Z)
            spherePosition.Z -= speed * time + 0.5;    
    }

    else if(IsKeyDown(irr::KEY_KEY_A)){
        if(cube_player->getPosition().X > sphere->getPosition().X)
            spherePosition.X -= speed * time + 0.5;    
    }

    else if(IsKeyDown(irr::KEY_KEY_D)){
        if(cube_player->getPosition().X < sphere->getPosition().X)
            spherePosition.X += speed * time + 0.5;    
    }

    sphere->setPosition(spherePosition);
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