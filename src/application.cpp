#include "application.h"
#include "application_context.h"
#include "util/resource.h"
#include "util/sprite.h"
#include "stage/unit.h"
#include <SDL2/SDL.h>

Application* Application::self_ = nullptr;
Application* Application::Get() { return self_; }

Application::Application() {
    self_ = this;
    window_ = SDL_CreateWindow("Hello", 0, 0, 1024, 768, SDL_WINDOW_SHOWN);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

Application::~Application() {
    if (window_) SDL_DestroyWindow(window_);
    if (renderer_) SDL_DestroyRenderer(renderer_);
}

void Application::Init() {

}

void Application::Run() {
    SDL_Event event;
    uint64_t begin, end;

    std::vector<stage::Unit> heros;
    for (int i=0;i<1;++i) {
        stage::Unit& u = heros.emplace_back(0);
        // u.AddAura(stage::Aura(0));
        u.Move(0, 300);
    }
    // // heros[0].AddAura(stage::Aura(1));
    
    // util::Sprite s1 { ApplicationContext::Get()->GetTexture(0), SDL_Rect {0, 0, 128, 126}, 30, 100 };
    util::Sprite s2 { ApplicationContext::Get()->GetTexture(0), SDL_Rect {0, 0, 128, 126}, 30, 500 };

    while( !IsStopped() ) {
        begin = SDL_GetTicks64();
        while( SDL_PollEvent( &event ) ) {
            switch (event.type) {
            case SDL_QUIT:
                Stop();
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer_, 0x00, 0x00, 0x00, 0xff);
        SDL_RenderClear(renderer_); // 全画面重绘？ 

        for (auto& u : heros) {
            u.Render(renderer_, begin);
        }
        // s1.Render(renderer_, begin);
        s2.Render(renderer_, begin);
       
        SDL_RenderPresent(renderer_);
        
        end = SDL_GetTicks64(); // 保证帧率
        if (end - begin < 25) SDL_Delay(begin + 25 - end);
    }
}

void Application::Stop() {
    status_ |= STATUS_QUIT;
}