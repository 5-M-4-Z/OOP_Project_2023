#include "Aircraft.hpp"
#include <iostream>

/*Functios that do not have any body*/

void Aircraft::move(){};
void Aircraft::display_bullet(SDL_Renderer* renderer, SDL_Texture* assets){};
void Aircraft::move(int x, int y){}
void Aircraft::shoot(){}
void Aircraft::move_bullet(){}
void Aircraft::move_bullet(int height){}
void Aircraft::set_delay(int x){}
void Aircraft::add(){}
void Aircraft::explode(SDL_Renderer* renderer, SDL_Texture* assets){}
void Aircraft::reduce_health(int power){}
int Aircraft::get_power(){};
int Aircraft::get_health(){};
bool Aircraft::is_completely_destroyed(){}

/*Functions that have some kind of body inside*/

bool Aircraft::get_destroyed(){return destroyed;}

void Aircraft::display(SDL_Renderer* renderer, SDL_Texture* assets){
    Object::display(renderer, assets);
}

bool Aircraft::collision_current_opponent_bullet(Aircraft* opponent){
    for (int i=0; i<bullets_array.size(); i++){
        Bullet bullet = bullets_array[i];
        SDL_Rect bullet_mvr = bullet.get_mover(), opponent_mover = opponent->get_mover();
        if (SDL_HasIntersection(&opponent_mover, &bullet_mvr)){
            // bullet.explode(renderer, assets);
            bullets_array.erase(bullets_array.begin() + i);
            
            opponent->reduce_health(this->get_power());
            return 1;
        }
    }
    return 0;
}

void Aircraft::collision_player_enemy_bullet(Aircraft* opponent){
    int size = opponent->bullets_array.size();
    for (int i=0; i<bullets_array.size(); i++){
        SDL_Rect p_bullet_mvr = (bullets_array[i]).get_mover();

        for (int j=0; j<size; j++){
            SDL_Rect e_bullet_mvr = (opponent->bullets_array[j]).get_mover();

            if (SDL_HasIntersection(&p_bullet_mvr, &e_bullet_mvr)){
                std::cout << "Bullet to bullet collision\n";
                bullets_array.erase(bullets_array.begin() + i);
                opponent->delete_bullet(i);
            }
        }
    }
}

SDL_Rect Aircraft::get_mover(){
    return Object::get_mover();
}

void Aircraft::delete_bullet(int i){
    this->bullets_array.erase(bullets_array.begin() + i);
}