#include "EnemyPlane3.hpp"
#include <iostream>

EnemyPlane3::EnemyPlane3(){
    src =  {105, 455, 179, 138};
    mover = {250, 50, 75, 75};
}
EnemyPlane3::EnemyPlane3(int x, int y)
{
    src =  {105, 455, 179, 138};
    mover = {x, y, 75, 75};
    shootTimer = 0;
}

void EnemyPlane3::move(){
    mover.y += 3;
}

void EnemyPlane3::shoot(){
    if (shootTimer == 50) { 
        bullets_array.push_back(Bullet(mover.x + mover.w / 2, mover.y + mover.h, -1)); // Pass -1 for downwards direction
        shootTimer = 0;
    } else {
        shootTimer++;
    }
}

void EnemyPlane3::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].display(renderer, assets);
    }
}

void EnemyPlane3::move_bullet(){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].move_bullet();
    }
}