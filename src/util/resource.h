#pragma once
#include "../application.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <memory>

namespace util {

template <class T>
class Resource {
    T*       res_ = nullptr;
public:
    Resource(const char* file, void* arg);
    Resource(const Resource& res) = delete;
    Resource(Resource&& res) {
        std::swap(res.res_, res_);
    }
    ~Resource();
    operator T*() { return res_; };
};

template <>
Resource<SDL_Texture>::Resource(const char* file, void* arg);
template <>
Resource<SDL_Texture>::~Resource();

template <>
Resource<Mix_Music>::Resource(const char* file, void* arg);
template <>
Resource<Mix_Music>::~Resource();

template <>
Resource<Mix_Chunk>::Resource(const char* file, void* arg);
template <>
Resource<Mix_Chunk>::~Resource();

template <>
Resource<TTF_Font>::Resource(const char* file, void* arg);
template <>
Resource<TTF_Font>::~Resource();


class ResourceTexture: public Resource<SDL_Texture> {
    SDL_Rect bounding_;
public:
    ResourceTexture(const char* file)
    : Resource<SDL_Texture>(file, &bounding_) {}

    const SDL_Rect& GetBoundingRect() const {
        return bounding_;
    }
};

} // namespace util