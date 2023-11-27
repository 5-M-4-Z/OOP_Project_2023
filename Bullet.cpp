#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet(int x, int y){
    src = {1296, 472, 18, 45};
    mover = {x+34, y, 25, 35};
    damage = 1;
    bullet_state = 0;
}

void Bullet::move_bullet(){
    mover.y-=5;
}

void Bullet::destroy(){
    if (bullet_state == 1){
    src = {1719, 658, 18, 17};
    mover = {mover.x, mover.y, mover.w, mover.h};
    }
    if (bullet_state == 2){
    src = {1716, 630, 24, 25};
    mover = {mover.x+2, mover.y+2, mover.w+2, mover.h+2};
    }
    if (bullet_state == 3){
    src = {1713, 595, 30, 34};
    mover = {mover.x+2, mover.y+2, mover.w+2, mover.h+2};
    }
    if (bullet_state == 4){
    src = {1713, 558, 30, 35};
    mover = {mover.x+2, mover.y+2, mover.w+2, mover.h+2};
    }
    if (bullet_state == 5){
    src = {1713, 521, 30, 32};
    mover = {mover.x+2, mover.y+2, mover.w+2, mover.h+2};
    }
    if (bullet_state == 6){
    src = {1715, 490, 26, 26};
    mover = {mover.x, mover.y, mover.w, mover.h};
    }
}

void Bullet::display(SDL_Renderer* renderer, SDL_Texture* assets){
    SDL_RenderCopy(renderer, assets, &src, &mover);
}