#include "Player.hpp"
using namespace std;

Player::Player(int x, int y){
    src = {111,44,149,182};    mover = {x, y, 75, 75};

}

void Player::gainExp(){
    exp++;
}

void Player::gainPow(){
    power*=2;
}

void Player::move(SDL_Keycode key){
    if (key == SDLK_w){
        mover.y -= 5;
    }

    if (key == SDLK_s){
        mover.y += 5;
    }

    if (key == SDLK_d){
        mover.x += 5;
    }
    if (key == SDLK_a || key == SDLK_LEFT){
        mover.x -= 5;
    }
}

void Player::shoot(){

}

void Player::display(SDL_Renderer* renderer, SDL_Texture* assets){
    SDL_RenderCopy(renderer, assets, &src, &mover);
}