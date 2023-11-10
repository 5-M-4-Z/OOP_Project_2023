#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Game{
    private:
        //Creating variables that will store size of our whole game
        const int screen_width = 700;
        const int screen_height = 800;

        //variable that will store game state
        /*
        0 = Start
        */
        unsigned state = 0;

        //Creating window that we will be modifying for our game
        SDL_Window* window = NULL;

        //The renderer
        SDL_Renderer* renderer = NULL;

        //Texture to display
        SDL_Texture* Texture = NULL;
        
        //texture for assets
        SDL_Texture* assets = NULL;

        //Music that we fill figure out for later;
        // Mix_Music *bg_music = NULL;

    public:
        void run(); //to run the game
        void close(); //to close the game
        bool load_media();  //this loads the desired media files
        bool init();
        SDL_Texture* loadTexture( std::string path );
        void game_start(SDL_Renderer* render, SDL_Texture* asset, SDL_Keycode key);
        void game_start_motion(SDL_Texture* asset);

};