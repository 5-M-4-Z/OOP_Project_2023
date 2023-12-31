#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>
#include <vector>
#include "Object.hpp"
#include "EnemyPlane1.hpp"
#include "Player.hpp"
#include "Aircraft.hpp"


struct Plane{
    SDL_Rect src_rect, mover_rect;
};

class Game{
    private:
        //Creating variables that will store size of our whole game
        const int screen_width = 500;
        const int screen_height = 650;

        //variable that will store game state
        /*
        0 = Start
        1 = Intro (Plane taking off the port making look cool)
        2 = The game now starts
        */
        unsigned state = 0;

        //Start game window plane that willl move
        Plane start_plane = {{111,44,149,182}, {122, 560, 75, 75}};     //the array {122, 560, 75,75} will differ from screen to screen
        
        //This is the player's plane
        Aircraft* player = new Player((screen_width/2) -38, screen_height-75);

        //Enemy Plane vector
        std::vector<Aircraft*> enemy_vector;

        //Creating window that we will be modifying for our game
        SDL_Window* window = NULL;

        //The renderer
        SDL_Renderer* renderer = NULL;

        //Texture to display
        SDL_Texture* Texture = NULL;
        
        //Link Texture
        SDL_Texture* link_Texture = NULL;

        //texture for assets
        SDL_Texture* assets = NULL;

        //Music that we fill figure out for later;
        Mix_Music *bg_music = NULL;


    public:
        void run(); //to run the game
        void close(); //to close the game
        bool load_media();  //this loads the desired media files
        bool init();
        SDL_Texture* loadTexture( std::string path );
        void game_start_motion(SDL_Renderer* renderer, SDL_Texture* assets);
        // void background_mover(SDL_Renderer* renderer, SDL_Texture* Texture, SDL_Rect src, SDL_Rect mover);

};