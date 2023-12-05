#include <SDL.h>
#include <iostream>
#include "Object.hpp"
#pragma once

class Health: public Object{
    private:
        // SDL_Rect border_src, border_mvr;
    public:
        void set_mvr(int x, int y, int plane_size);
        void display(SDL_Renderer* renderer, SDL_Texture* assets);
        void set_src();
        void move(int x, int y);
};