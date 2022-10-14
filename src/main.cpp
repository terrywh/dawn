#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "application_context.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    Application app;
    ApplicationContext context;

    app.Run();

    IMG_Quit();
    SDL_Quit();
}