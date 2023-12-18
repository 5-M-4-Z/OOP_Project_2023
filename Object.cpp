#include "Object.hpp"
#include <iostream>

void Object::display(SDL_Renderer* renderer, SDL_Texture* assets){
    
    if (name == "Enemy"){
        // SDL_RenderCopy(renderer, assets, &src, &mover);
        SDL_RenderCopyEx(renderer, assets, &src, &mover, 0, NULL, SDL_FLIP_VERTICAL);
    }
    else {
        SDL_RenderCopy(renderer, assets, &src, &mover);
    }
}
// void Object::move(){};
void Object::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){};

SDL_Rect Object::get_mover(){
    return mover;
}
