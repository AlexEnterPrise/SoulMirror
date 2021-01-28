#pragma once
#include <util/typealias.hpp>

struct GameContext_t{
    virtual ~GameContext_t() = default;
    virtual VecEntities_t& getEntities() = 0;
    virtual const VecEntities_t& getEntities() const = 0;
   
};