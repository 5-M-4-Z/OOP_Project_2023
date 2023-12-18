#include "Bullet.hpp"
#include <iostream>

Bullet::Bullet(int x, int y){
    src = {1296, 472, 18, 45};
    mover = {x+34, y, 25, 35};
    damage = 1;
    bullet_state = 0;
    // destroyed = 0;
}

void Bullet::move_bullet(){
    mover.y-=5;
}
void Bullet::move_bullet(int dummy){
    //This dummy argument only adds an overload function to identify between enemy bullet and players bullet
    mover.y+=7;
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
    Object::display(renderer, assets);
    // SDL_RenderCopy(renderer, assets, &src, &mover);
}

void Bullet::display(SDL_Renderer* renderer, SDL_Texture* assets, int x){
    // int x is only dummy vaariable to identify enemy bullets 
    name = "Enemy";
    Object::display(renderer, assets);
    // SDL_RenderCopyEx(renderer, assets, &src, &mover, 0, NULL, SDL_FLIP_VERTICAL);
}

SDL_Rect Bullet::get_mover(){
    return mover;
}

// void EnemyPlane1::explode(SDL_Renderer* renderer, SDL_Texture* assets){
//     if (destroyed == 0){
//         explosion.set_values(mover.x, mover.y, mover.w, mover.h);
//     }
//     int x = 0;
//     for (int i=0; i<10; i++){
//         x++;
//     }
//     // std::cout << "delay ended\n";
//     if (!(explosion.is_finished())){
//         destroyed = 1;
//         explosion.update();
//         explosion.display(renderer, assets);
//     }
// }