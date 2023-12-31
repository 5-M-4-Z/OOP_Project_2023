#include "Health.hpp"

void Health::set_mvr(int x, int y, int value){
    mover = { x + value - (value*0.25), y+10, 50, 5};
}

void Health::display(SDL_Renderer* renderer, SDL_Texture* assets){
    Object::display(renderer, assets);
}

void Health::set_src(){
    src = {1199, 786, 300, 45};
}

void Health::move(int x, int y){
    mover.x += x;
    mover.y += y;
}

void Health::reduce_health(int value){
    mover.w -= value/2;
}

int Health::get_health(){return mover.w;}