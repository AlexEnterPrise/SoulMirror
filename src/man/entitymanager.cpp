#include <man/entitymanager.hpp>
#include <algorithm>



EntityManager_t::EntityManager_t(){
	m_Entities.reserve(kMAXENTITIES);
}


void EntityManager_t::createEntity(uint32_t ax,uint32_t ay,uint32_t az){
	//auto& e = m_Entities.emplace_back(type);
	Entity_t e;
	e.x=ax;
	e.y=ay;
	e.z=az;
	m_Entities.push_back(e);
	
	

}

