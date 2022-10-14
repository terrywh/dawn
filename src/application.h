#pragma once
#include <vector>

struct SDL_Window;
struct SDL_Renderer;

class Application {
    static Application* self_;
    SDL_Window*   window_ = nullptr;
    SDL_Renderer* renderer_ = nullptr;
    int status_ = 0;
    
public:
    enum status_t {
        STATUS_QUIT = 0x01,
    };
    static Application* Get();
    Application();
    ~Application();

    SDL_Window*     GetWindow() { return window_; }
    SDL_Renderer* GetRenderer() { return renderer_; }

    void Init();
    void Run();
    void Stop();

private:
    
    inline bool IsStopped() { return status_ & STATUS_QUIT; }
};
