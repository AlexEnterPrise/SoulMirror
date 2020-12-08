#pragma once


#include <cstdint>
#include <vector>
#include <string>



struct Entity_t {
	explicit Entity_t (int32_t ax,int32_t ay,int32_t az) : x{ax},y{ay},z{az} {};
	int32_t x 	{0}, y 	{0}, z 	{0}; //posicion en x,y,z
	int32_t w 	{1}, h 	{1}, d 	{1}; //dimensiones
	int32_t rx {0}, ry {0}, rz {0}; //rotacion en x,y,z
	std::size_t entityID { ++nextID };
	inline static std::size_t nextID {0};
	std::string ModelPath; 
};


struct EntityManager_t{
	static constexpr std::size_t kMAXENTITIES {1000};

	explicit EntityManager_t();
	void createEntity(int32_t ax,int32_t ay,int32_t az);
	void createEntitiesNode();
	const std::vector<Entity_t>& getEntities() const {return m_Entities;}
private:
	std::vector<Entity_t> m_Entities{};
};


