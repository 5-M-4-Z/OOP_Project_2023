#include "EnemyPlane1.hpp"
#include <iostream>

EnemyPlane1::EnemyPlane1(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    src = {563, 92, 244,  139};

    // it will display plane on x = 250, y = 50 location, the size of plane is 75 width, 75 height
    mover = {250, 50, 75, 75};
}
EnemyPlane1::EnemyPlane1(int x, int y, int random)
{
    if (random == 0){
        src = {563, 92, 244,  139};
        mover = {x, y, 75, 75};
    }
    else if (random == 1){
        src = {860, 280, 256, 187};
        mover = {x, y, 75, 75};
    }
    else if (random == 2){
        src =  {105, 455, 179, 138};
        mover = {x, y, 75, 75};
    }
    else if (random == 3){
        src =  {877, 520, 248, 99};
        mover = {x, y, 75, 75};
    }
    shootTimer = 0;
}

void EnemyPlane1::move(){
    mover.y += 3;
}

void EnemyPlane1::shoot(){
    if (shootTimer == 30) { // Adjust the frequency of shooting
        bullets_array.push_back(Bullet(mover.x-6,mover.y+55)); 
        // -6 only makes the bullet to be fired from the centre of the plane 
        // +55 moves the bullet a little down for it may generate at centre of plane otherwise
        shootTimer = 0;
    } else {
        shootTimer++;
    }
}

void EnemyPlane1::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){
    this->shoot();
    //This function needs to be overloaded specifically for thhe enemy so that bullet is faster than the enemy plane speed
    this->move_bullet();
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].display(renderer, assets, 1); // passing dummy 1 to flip the bullet for the enemy
    }
}

void EnemyPlane1::move_bullet(){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].move_bullet(0);
    }
}

void EnemyPlane1::collision(SDL_Rect enmy_mover){
    for (auto bullet : bullets_array){
        SDL_Rect bullet_mover = bullet.get_mover();
        
        if (SDL_HasIntersection(&bullet_mover, &enmy_mover)){
            std::cout << "enemy bullet to player\n";
        }
    }
}

void EnemyPlane1::collision_player_bullet(Player player){

    for(auto bullet : bullets_array){
        player.collision_enemy_bullet(bullet);
    }
}