#pragma once
#include "../util/sprite.h"

namespace stage {

class Aura {
    util::Sprite sprite_;

public:
    Aura(int id);
    
    inline void Render(SDL_Renderer *r, std::uint64_t tick) {
        sprite_.Render(r, tick);
    }
};

} // namespace stage
