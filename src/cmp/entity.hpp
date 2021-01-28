#pragma once
#include <cstdint>
#include <string>


struct Entity_t {
	explicit Entity_t (int32_t ax,int32_t ay,int32_t az) : x{ax},y{ay},z{az} {};
	int32_t x 	{0}, y 	{0}, z 	{0}; //posicion en x,y,z
	int32_t w 	{1}, h 	{1}, d 	{1}; //dimensiones
	int32_t rx 	{0}, ry {0}, rz {0}; //rotacion en x,y,z
	int32_t vx 	{0}, vz {0};
	std::size_t entityID { ++nextID };
	inline static std::size_t nextID {0};
	std::string ModelPath; 
};