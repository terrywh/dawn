#include "sprite.h"

namespace util {

void Sprite::Render(SDL_Renderer* r, std::uint64_t tick) {
    int frame = (tick - render_) / rate_ % frames_;
    const SDL_Rect& bounding = texture_.GetBoundingRect();
    source_.y = (frame * source_.w) / bounding.w * source_.h;
    source_.x = (frame * source_.w) % bounding.w;
    SDL_RenderCopy(r, texture_, &source_, &target_);
    // render_ = tick;
}

} // namespace util
