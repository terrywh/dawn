#pragma once
#include "resource.h"

namespace util {

class Sprite {
    const int frames_;
    const int rate_;
    
    std::uint64_t render_;
    SDL_Rect source_;
    SDL_Rect target_;

    ResourceTexture& texture_;
    
public:
    Sprite(ResourceTexture& texture, const SDL_Rect& source, const int frames, const int rate)
    : texture_(texture)
    , source_(source)
    , frames_(frames)
    , rate_(rate)
    , render_(SDL_GetTicks64()) {
        target_.x = 0;
        target_.y = 0;
        target_.h = source_.h;
        target_.w = source_.w;
    }

    inline SDL_Rect& GetTarget() { return target_; }
    
    void Render(SDL_Renderer *r, std::uint64_t tick);
};

} // namespace util