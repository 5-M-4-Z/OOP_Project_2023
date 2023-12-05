#include "Player.hpp"
#include <iostream>

Player::Player(int x, int y){
    src = {111,44,149,182};    mover = {x, y, 75, 75};
    delay = 0;
    health.set_mvr(x, y, 75);
    health.set_src();
}

void Player::gainExp(){
    exp++;
}

void Player::gainPow(){
    power*=2;
}

void Player::move(int width, int height){
    const Uint8* state = SDL_GetKeyboardState(NULL);

    if ((state[SDL_SCANCODE_W] || state[SDL_SCANCODE_UP]) && mover.y > height/2){
        if (mover.y-5 >0){
            mover.y-=5;
            health.move(0,-5);
        }
    }
    if (state[SDL_SCANCODE_S] || state[SDL_SCANCODE_DOWN]){
        if (mover.y+5<height-75){
            mover.y+=5;
            health.move(0,+5);
        }
    }
    if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT]){
        if (mover.x+5<width-75){
            mover.x+=5;
            health.move(+5, 0);
        }
    }
    if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT]){
        if (mover.x-5>0){
            mover.x-=5;
            health.move(-5,0);
        }
    }
}

void Player::shoot(){
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_F]){
        f_pressed = 1;
    }

    // std::cout << delay << '\n';
    if (f_pressed && delay == 0){
        Bullet bullet(mover.x, mover.y);
        bullets_array.push_back(bullet);
        delay = -7;
        f_pressed = 0;
    }
    else if (f_pressed) {delay++;}
}

void Player::display(SDL_Renderer* renderer, SDL_Texture* assets){
    SDL_RenderCopy(renderer, assets, &src, &mover);
    this->health.display(renderer, assets);
}

void Player::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){
    for (int i=0; i<bullets_array.size(); i++){
        bullets_array[i].display(renderer, assets);
    }
}

void Player::move_bullet(){
    int x;
    for (int i=0; i<bullets_array.size(); i++){
       bullets_array[i].move_bullet();
        int h = (bullets_array[i].get_mover()).y;
        
        if (h < -10){
            bullets_array.erase(bullets_array.begin() + i);
            std::cout << "bullet destroyed\n";
            x += 1;
        }
    }
}

        

void Player::set_delay(int x){delay = x;}

int Player::get_f_pressed(){return f_pressed;}

SDL_Rect Player::get_mover(){
    return mover;
}