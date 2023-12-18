#include <SDL.h>
#include <vector>
#include <iostream>
#include "Bullet.hpp"
#include "Object.hpp"
#include "Health.hpp"
#include "Score.hpp"
#include "Explosion.hpp"

#pragma once

class Aircraft : public Object{
    protected:
        bool destroyed=0;
        std::vector<Bullet> bullets_array;
        Health health;
        Explosion explosion;
    public:
        virtual void display(SDL_Renderer* renderer, SDL_Texture* assets);
        virtual void move();
        virtual void display_bullet(SDL_Renderer* renderer, SDL_Texture* assets);
        SDL_Rect get_mover();
        // virtual void shoot();  
        virtual void move(int x, int y);
        virtual void shoot();
        virtual void move_bullet();
        virtual void move_bullet(int height);
        
        virtual void set_delay(int x);

        bool collision_current_opponent_bullet(Aircraft* opponent);
        void collision_player_enemy_bullet(Aircraft* opponent);

        virtual void add();
        virtual void explode(SDL_Renderer* renderer, SDL_Texture* assets);

        bool get_destroyed();

        void delete_bullet(int i);
        virtual void reduce_health(int power);
        virtual int get_power();
        virtual int get_health();
        virtual bool is_completely_destroyed();
};