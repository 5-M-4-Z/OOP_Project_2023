#include "Object.hpp"
#include <iostream>

void Object::draw(SDL_Renderer* renderer, SDL_Texture* assets){              // Drawing the object on the screen.
    SDL_RenderCopyEx(renderer, assets, &src, &mover, 0, NULL, SDL_FLIP_VERTICAL); 
}
void Object::move(){};

void Object::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){};

SDL_Rect Object::get_mover(){
    return mover;
}

void Object::collision(SDL_Rect player_mover){}

void Object::collision_player_bullet(Player player){}