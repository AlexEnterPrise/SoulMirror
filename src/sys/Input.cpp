#include "Input.hpp"

Input::Input(){
	for (irr::u32 i=0; i<irr::KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
}

bool Input::OnEvent(const irr::SEvent& event){
	// Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

        return false;

}

// This is used to check whether a key is being held down
bool Input::IsKeyDown(irr::EKEY_CODE keyCode) const {
    return KeyIsDown[keyCode];
}


irr::core::vector3df Input::comproveMovement(irr::core::vector3df cubePosition, irr::f32 MOVEMENT_SPEED, irr::f32 frameDeltaTime, irr::scene::ISceneNode* one, irr::scene::ISceneNode* two ){
    if(IsKeyDown(irr::KEY_LSHIFT)){
        MOVEMENT_SPEED = 30.f;
        if(col.checkCollision(one, two)){
            if(IsKeyDown(irr::KEY_KEY_W))
                cubePosition.Z += MOVEMENT_SPEED * frameDeltaTime - 0.5;
            else if(IsKeyDown(irr::KEY_KEY_S))
                cubePosition.Z -= MOVEMENT_SPEED * frameDeltaTime - 0.5;

            if(IsKeyDown(irr::KEY_KEY_A))
                cubePosition.X -= MOVEMENT_SPEED * frameDeltaTime - 0.5;
            else if(IsKeyDown(irr::KEY_KEY_D))
                cubePosition.X += MOVEMENT_SPEED * frameDeltaTime - 0.5;
        
        }else{
            if(IsKeyDown(irr::KEY_KEY_W))
                cubePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
            else if(IsKeyDown(irr::KEY_KEY_S))
                cubePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;

            if(IsKeyDown(irr::KEY_KEY_A))
                cubePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
            else if(IsKeyDown(irr::KEY_KEY_D))
                cubePosition.X += MOVEMENT_SPEED * frameDeltaTime;
        }

    }else{
        if(col.checkCollision(one, two)){

            if(IsKeyDown(irr::KEY_KEY_W))
                cubePosition.Z += MOVEMENT_SPEED * frameDeltaTime - 0.5;
            else if(IsKeyDown(irr::KEY_KEY_S))
            cubePosition.Z -= MOVEMENT_SPEED * frameDeltaTime - 0.5;

            if(IsKeyDown(irr::KEY_KEY_A))
                cubePosition.X -= MOVEMENT_SPEED * frameDeltaTime - 0.5;
            else if(IsKeyDown(irr::KEY_KEY_D))
                cubePosition.X += MOVEMENT_SPEED * frameDeltaTime - 0.5;
        }else{

            if(IsKeyDown(irr::KEY_KEY_W))
                cubePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
            else if(IsKeyDown(irr::KEY_KEY_S))
                cubePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;

            if(IsKeyDown(irr::KEY_KEY_A))
                cubePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
            else if(IsKeyDown(irr::KEY_KEY_D))
                cubePosition.X += MOVEMENT_SPEED * frameDeltaTime;
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

//void Input::printXYZ(scene::ISceneNode *cube){
//    int x,y,z;
//    if(IsKeyDown(irr::KEY_KEY_C)){
//        x = cube->getPosition().X;
//        y = cube->getPosition().Y;
//        z = cube->getPosition().Z;
//    }
//    std::cout<<"COOR X = " << x << "COOR Y = " << y << "COOR Z = " << z<<std::endl;
//}