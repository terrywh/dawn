#include "application_context.h"
#include "util/sprite.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

ApplicationContext* ApplicationContext::self_ = nullptr;

ApplicationContext* ApplicationContext::Get() {
    return self_;
}

ApplicationContext::ApplicationContext()
: event_render(SDL_RegisterEvents(1))
, event_action(SDL_RegisterEvents(1)) {
    self_ = this;
    texture_.emplace_back("res/fire.png");
    texture_.emplace_back("res/halo.jpg");
}

ApplicationContext::~ApplicationContext() {
   
}
