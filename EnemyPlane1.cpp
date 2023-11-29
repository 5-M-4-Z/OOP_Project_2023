#include "EnemyPlane1.hpp"
#include <iostream>

EnemyPlane1::EnemyPlane1(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    src = {563, 92, 244,  139};

    // it will display plane on x = 250, y = 50 location, the size of plane is 75 width, 75 height
    mover = {250, 50, 75, 75};
}
EnemyPlane1::EnemyPlane1(int x, int y)
{
    src = {563, 92, 244,  139};
    mover = {x, y, 75, 75};
    shootTimer = 0;
}

void EnemyPlane1::move(){
    mover.y += 3;
}

void EnemyPlane1::shoot(){
    if (shootTimer == 50) { // Adjust the frequency of shooting
        bullets_array.push_back(Bullet(mover.x,mover.y)); // Pass -1 for downwards direction
        shootTimer = 0;
    } else {
        shootTimer++;
    }
}

void EnemyPlane1::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].display(renderer, assets);
    }
}

void EnemyPlane1::move_bullet(){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].move_bullet();
    }
}