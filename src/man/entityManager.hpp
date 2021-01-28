#pragma once


#include <cstdint>
#include <vector>
#include <string>
#include <util/typealias.hpp>
#include <util/gamecontext.hpp>
#include <facade/RavenGraphics.hpp>

struct EntityManager_t : public GameContext_t{
	static constexpr std::size_t kMAXENTITIES {1000};

	explicit EntityManager_t();
	void createEntity(int32_t ax,int32_t ay,int32_t az);
	void createEntities(RavenGraphics&);
	const VecEntities_t& getEntities() const override {return m_Entities;}
	VecEntities_t& getEntities()  override {return m_Entities;}

private:
	std::vector<Entity_t> m_Entities{};
};


