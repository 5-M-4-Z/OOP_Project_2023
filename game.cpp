#include "game.hpp"


void Game::run(){
    bool quit_game = false;
    SDL_Event = event;

    //Infinite loop untill the user quits the game
    while(!quit){
        
        while(SDL_PollEvent(&event) != 0){
            if (event.type == SDL_Quit()){
                quit_game = true;
            }

            if (event.type == SDL_KEYDOWN){
                //Call a function that will affect the game
            }
        }
    }
    Game::close();
}

void Game::close(){
    SDL_DestroyTexture(assets);
    assets = NULL;

    SDL_DestroyRenderer(renderer)
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

bool Game::load_media(){
    bool success = true;

    assets = loadTexture("assets/background.png")
    if (assets == NULL){
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success = false;
    }

    return 0;
}

bool Game::init(){
    //variable that will tell whether the initialization was successful or not
    bool success = true;

    //initializing SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0 ){
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else{

        //Texture filtering 
        if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")){
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Creating window
        window = SDL_CreateWindow( "THE GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if (window == NULL){
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
        }
        else{

            //Creating renderer
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == NULL){
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
            }
            else{
                
                //renderer color
                SDL_SetRendererDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //png loading
                int img_flag = IMG_INIT_PNG;
                if (!(IMG_Init(img_flag) & img_flag)){
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
                }
            }
        }
    }
    return success;
}

SDL_Texture* Game::loadTexture( string path){
    SDL_Texture* new_texture = NULL;

    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if (loadedSurface == NULL){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else{

        new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
        if (new_texture == NULL){
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        SDL_FreeSurface( loadedSurface );
    }

    return new_texture;
}