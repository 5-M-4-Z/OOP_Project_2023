#include "EnemyPlane2.hpp"
#include <iostream>

EnemyPlane2::EnemyPlane2(){
    src = {860, 280, 256, 187};
    mover = {250, 50, 75, 75};
}
EnemyPlane2::EnemyPlane2(int x, int y)
{
    src = {860, 280, 256, 187};
    mover = {x, y, 75, 75};
    shootTimer = 0;
}

void EnemyPlane2::move(){
    mover.y += 3;
}

void EnemyPlane2::shoot(){
    if (shootTimer == 50) { 
        bullets_array.push_back(Bullet(mover.x,mover.y)); // Pass -1 for downwards direction
        shootTimer = 0;
    } else {
        shootTimer++;
    }
}

void EnemyPlane2::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].display(renderer, assets);
    }
}

void EnemyPlane2::move_bullet(){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].move_bullet();
    }
}