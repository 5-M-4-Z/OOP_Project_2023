#include "Player.hpp"

Player::Player(int x, int y){
    SDL_Rect src = {111,44,149,182};    mover = {x, y, 75, 75};
    GameObject::GameObject(src, mover);
}

void Player::gainExp(){
    exp++;
}

void Player::gainPow(){
    power*=2;
}

void Player::move(char c){
    if (c == "N"){
        mover.y -= 2;
    }

    if (c == "S"){
        mover.y += 2;
    }

    if (c == "E"){
        mover.x += 2;
    }
    if (c == "W"){
        mover.x -= 2;
    }
}

void Player::shoot(){

}

void Player::display(SDL_Renderer* renderer, SDL_Texture* assets){
    SDL_RenderCopy(renderer, assets, &src, &mover);
}