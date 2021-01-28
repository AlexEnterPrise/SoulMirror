#include <sys/physics.hpp>
#include <facade/ControllerMan.hpp>
PhysicsSystem_t::PhysicsSystem_t(ControllerMan& r)
: rginterfaz{r}{

}

void PhysicsSystem_t::physicsInit() const{
    rginterfaz.p().controller().physicsInit();
}

void PhysicsSystem_t::physicsUpdate() const{

}