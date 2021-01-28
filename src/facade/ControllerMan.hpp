#pragma once

#include <facade/Controller.hpp>
 struct Controller_t;
 enum class TControllerMan {irrlichtGraphics,RavenGraphics};

 class ControllerMan
 {
public:
    ControllerMan(); 
    ~ControllerMan();
    static ControllerMan& p();
    Controller_t& controller();

    void switchMotor();
private:
    //Constructor por defecto privado
    Controller_t*     m_motor = nullptr;
    TControllerMan  m_seleccionado = TControllerMan::irrlichtGraphics; //El que ponemos seleccionado por defecto 
 };
 