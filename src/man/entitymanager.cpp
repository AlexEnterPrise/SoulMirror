#include <man/entitymanager.hpp>
#include <algorithm>



EntityManager_t::EntityManager_t(){
	m_Entities.reserve(kMAXENTITIES);
}


void EntityManager_t::createEntity(int32_t ax,int32_t ay,int32_t az){
	//auto& e = m_Entities.emplace_back(ax,ay,az);
	Entity_t e {ax,ay,az};
	m_Entities.push_back(e);
}

