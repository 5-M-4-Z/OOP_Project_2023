#include "Object.hpp"
#include <SDL.h>
#include <vector>
#include <iostream>
#pragma once

class Explosion: public Object{
    private:
        int current_frame, next_frame;
        std::vector<SDL_Rect> src_frame;

    public:
        void set_values(int x, int y, int w, int h);
        bool is_finished();
        void update();
        void display(SDL_Renderer* renderer, SDL_Texture* assets);
};