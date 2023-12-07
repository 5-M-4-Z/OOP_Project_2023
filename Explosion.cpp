#include "Explosion.hpp"

void Explosion::set_values(int x, int y, int w, int h){
    current_frame = 0;
    next_frame = 7;
    src_frame = {{1719, 658, 18, 17}, {1716, 630, 24, 25}, {1713, 595, 30, 34}, 
                {1713, 558, 30, 35}, {1713, 521, 30, 32}, {1715, 490, 26, 26}, {1719, 469, 18, 15}};
    mover = {x, y, int(w/0.94), int(h/0.94)};
    src = src_frame[current_frame];
}

bool Explosion::is_finished(){
    return current_frame == next_frame;
}

void Explosion::update(){
    if (!(this->is_finished())){
        current_frame ++;
        mover.x++;
        mover.y++;
        mover.w+=2;
        mover.h+=2;
        src = src_frame[current_frame];
        // std::cout << current_frame << " " << next_frame << "\n";
    }
}

void Explosion::display(SDL_Renderer* renderer, SDL_Texture* assets){
    SDL_RenderCopy(renderer, assets, &src, &mover);
}