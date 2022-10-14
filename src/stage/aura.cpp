#include "aura.h"
#include "../application_context.h"

namespace stage {

Aura::Aura(int id)
: sprite_(ApplicationContext::Get()->GetTexture(id), SDL_Rect {0, 0, 192, 192}, 20, 100) {

}

} // namespace stage
