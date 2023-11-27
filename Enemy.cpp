#include "Enemy.hpp"
#include <iostream>


Enemy::Enemy(int x, int y){
    src = {328, 55, 145, 169}; // Set the source rectangle parameters
    mover = {x, y, 75, 75}; // Set the width and height of the enemy
    // isActive = true;
    shootTimer = 0;
}

void Enemy::move() {
    // Set the downward movement speed of the enemy
    mover.y += 2;
}

void Enemy::display(SDL_Renderer* renderer, SDL_Texture* assets){
    SDL_RenderCopyEx(renderer, assets, &src, &mover, 0, NULL, SDL_FLIP_VERTICAL);
}

void Enemy::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].display(renderer, assets);
    }
}

void Enemy::move_bullet(){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].move_bullet();
    }
}

void Enemy::shoot(){
    // if (shootTimer == 2){
    //     bullets_array.push_back(Bullet(mover.x + mover.w / 2, mover.y + mover.h));
    //     shootTimer = 0;
    // }
    // else{
    //     shootTimer++;
    // }
}