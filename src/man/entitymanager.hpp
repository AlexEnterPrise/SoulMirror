#pragma once


#include <cstdint>
#include <vector>
#include <string>



struct Entity_t {
	explicit Entity_t () {};
	uint32_t x 	{0}, y 	{0}, z 	{0}; //posicion en x,y,z
	uint32_t w 	{0}, h 	{0}, d 	{0}; //dimensiones
	uint32_t rx {0}, ry {0}, rz {0}; //rotacion en x,y,z
	std::size_t entityID { ++nextID };
	inline static std::size_t nextID {0};
	std::string ModelPath; 
};


struct EntityManager_t{
	static constexpr std::size_t kMAXENTITIES {1000};

	explicit EntityManager_t();
	void createEntity();
	const std::vector<Entity_t>& getEntities() const {return m_Entities;}
private:
	std::vector<Entity_t> m_Entities{};
};



