#include "EnemyPlane4.hpp"
#include <iostream>

EnemyPlane4::EnemyPlane4(){
    src =  {877, 520, 248, 99};
    mover = {250, 50, 75, 75};
}
EnemyPlane4::EnemyPlane4(int x, int y)
{
    src =  {877, 520, 248, 99};
    mover = {x, y, 75, 75};
    shootTimer = 0;
}

void EnemyPlane4::move(){
    mover.y += 3;
}

void EnemyPlane4::shoot(){
    if (shootTimer == 50) { 
        bullets_array.push_back(Bullet(mover.x,mover.y)); // Pass -1 for downwards direction
        shootTimer = 0;
    } else {
        shootTimer++;
    }
}

void EnemyPlane4::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].display(renderer, assets);
    }
}

void EnemyPlane4::move_bullet(){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].move_bullet();
    }
}