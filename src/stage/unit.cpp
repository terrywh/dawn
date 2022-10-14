#include "unit.h"
#include "../application_context.h"

namespace stage {

Unit::Unit(int id)
: sprite_(ApplicationContext::Get()->GetTexture(id), SDL_Rect {0, 0, 128, 126}, 30, 100)
, tick_(SDL_GetTicks64()) {

}

void Unit::AddAura(Aura&& aura) {
    auras_.emplace_back(std::move(aura));
}

void Unit::Move(int dx, int dy) {
    sprite_.GetTarget().x = dx;
    sprite_.GetTarget().y = dy;
}

void Unit::Render(SDL_Renderer *r, std::uint64_t tick) {
    for(auto& aura : auras_) {
        aura.Render(r, tick);
    }
    Move((tick - tick_) / 25, 0);
    sprite_.Render(r, tick);
}


} // namespace stage
