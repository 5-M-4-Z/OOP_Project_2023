#include <SDL.h>
#include <vector>
#include <iostream>
#include "Object.hpp"
#pragma once

struct Pair{
    SDL_Rect src, mvr;
};

class Score: public Object{
    private:
        std::vector<int> score_vector;
        std::vector<Pair> score_src_mvr_vector;
        int gap_x, gap_y;
    public:
        Score();
        void display(SDL_Renderer* renderer, SDL_Texture* assets);
        void increment();
        void set_mvr_src();
};