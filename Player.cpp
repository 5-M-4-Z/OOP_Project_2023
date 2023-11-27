#include "Player.hpp"
#include <iostream>

Player::Player(int x, int y){
    src = {111,44,149,182};    mover = {x, y, 75, 75};

}

void Player::gainExp(){
    exp++;
}

void Player::gainPow(){
    power*=2;
}

void Player::move(int width, int height){
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]){
        if (mover.y-5 >0)   mover.y-=5;
    }
    if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]){
        if (mover.y+5<height-75)    mover.y+=5;
    }
    if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]){
        if (mover.x+5<width-75) mover.x+=5;
    }
    if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]){
        if (mover.x-5>0)    mover.x-=5;
    }
    //std::cout << mover.x << " " << mover.y << '\n';
}

void Player::shoot(){

}

void Player::display(SDL_Renderer* renderer, SDL_Texture* assets){
    SDL_RenderCopy(renderer, assets, &src, &mover);
}