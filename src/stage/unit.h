#pragma once
#include "../util/sprite.h"
#include "aura.h"

namespace stage {

class Unit {
    util::Sprite sprite_;
    std::vector<Aura> auras_;
    std::uint64_t tick_;

public:
    Unit(int id);
    void AddAura(Aura&& aura);
    void Move(int dx, int dy);
    void Render(SDL_Renderer *r, std::uint64_t tick);
};

} // namespace stage
