#include "resource.h"
#include <iostream>

namespace util {
template <>
Resource<SDL_Texture>::Resource(const char* file, void* arg) {
    std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*> s { IMG_Load(file), SDL_FreeSurface };
    
    auto* rect = static_cast<SDL_Rect*>(arg);
    std::memset(rect, 0, sizeof(SDL_Rect));
    rect->w = s->w;
    rect->h = s->h;

    res_ = SDL_CreateTextureFromSurface(Application::Get()->GetRenderer(), s.get());
}

template <>
Resource<SDL_Texture>::~Resource() {
    if (res_) SDL_DestroyTexture(res_);
}

template <>
Resource<Mix_Music>::Resource(const char* file, void* arg) {
    res_ = Mix_LoadMUS(file);
}

template <>
Resource<Mix_Music>::~Resource() {
    if (res_) Mix_FreeMusic(res_);
}


template <>
Resource<Mix_Chunk>::Resource(const char* file, void* arg) {
    res_ = Mix_LoadWAV(file);
}

template <>
Resource<Mix_Chunk>::~Resource() {
    if (res_) Mix_FreeChunk(res_);
}

template <>
Resource<TTF_Font>::Resource(const char* file, void* arg) {
    res_ = TTF_OpenFont(file, *static_cast<int*>(arg));
}

template <>
Resource<TTF_Font>::~Resource() {
    if (res_) TTF_CloseFont(res_);
}

} // namespace util
