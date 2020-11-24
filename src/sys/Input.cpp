#include "Input.hpp"

Input::Input(){
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
}

bool Input::OnEvent(const SEvent& event){
	// Remember whether each key is down or up
        if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

        return false;

}

// This is used to check whether a key is being held down
bool Input::IsKeyDown(EKEY_CODE keyCode) const {
    return KeyIsDown[keyCode];
}


core::vector3df Input::comproveMovement(core::vector3df cubePosition, f32 MOVEMENT_SPEED, f32 frameDeltaTime, scene::ISceneNode* one, scene::ISceneNode* two ){
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

bool Input::moveCam(bool SwitchCam, scene::ISceneNode *map){
    if(IsKeyDown(irr::KEY_KEY_P)){
        if(SwitchCam)
            SwitchCam = false;
        else
            SwitchCam = true;
    }

    if(IsKeyDown(irr::KEY_KEY_B)){
        delete map;
        map = NULL;
    }
    return SwitchCam;
}