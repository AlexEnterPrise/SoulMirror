#include <man/entitymanager.hpp>
#include <algorithm>


EntityManager_t::EntityManager_t(){
	m_Entities.reserve(kMAXENTITIES);
}

void EntityManager_t::createEntity(){
	//auto& e = m_Entities.emplace_back(type);
	Entity_t e;
	m_Entities.push_back(e);
	

}
