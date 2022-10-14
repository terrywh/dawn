#pragma once
#include "util/resource.h"
#include <vector>

namespace util {
template <class T>
class Resource;
}

class ApplicationContext {
    static ApplicationContext* self_;

    std::vector<util::ResourceTexture>    texture_;
    std::vector<util::Resource<TTF_Font>>    font_;
    std::vector<util::Resource<Mix_Music>>  music_;
    std::vector<util::Resource<Mix_Chunk>>  chunk_;
    int status_ = 0;
    
public:
    const int event_render;
    const int event_action;
    
    static ApplicationContext* Get();
    ApplicationContext();
    ~ApplicationContext();
    
    util::ResourceTexture& GetTexture(int id) { return texture_.at(id); }
    

private:

};
