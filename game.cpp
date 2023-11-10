#include "game.hpp"


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
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF );

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

void Game::close(){
    SDL_DestroyTexture(assets);
    assets = NULL;

    SDL_DestroyTexture(Texture);
    Texture = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    IMG_Quit();
    // Mix_Quit();
    SDL_Quit();
}

bool Game::load_media(){
    bool success = true;

    Texture = loadTexture("assets/test.png");
    assets = loadTexture("assets/plane_lists.png");

    if (Texture == NULL|| assets == NULL){
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success = false;
    }

    return success;
}



SDL_Texture* Game::loadTexture( std::string path){
    SDL_Texture* new_texture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL){
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else{

        new_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (new_texture == NULL){
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        SDL_FreeSurface( loadedSurface );
    }

    return new_texture;
}

void Game::run(){
    bool quit_game = false;
    SDL_Event event;

    //Infinite loop untill the user quits the game
    while(!quit_game){
        
        while(SDL_PollEvent(&event) != 0){
            if (event.type == SDL_QUIT){
                quit_game = true;
            }

            if (event.type == SDL_KEYDOWN){
                //Call a function that will affect the game
                game_start(renderer, assets, event.key.keysym.sym);
            }
        }   

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, Texture, NULL, NULL);



        SDL_RenderPresent(renderer);
        SDL_Delay(200);
    }
    Game::close();
}

void Game::game_start_motion(SDL_Texture* asset){
    
}

void Game::game_start(SDL_Renderer* render, SDL_Texture* asset, SDL_Keycode key){
    
    //When enter key is pressed we destroy the background and make new background
    if(key == SDLK_RETURN){
        SDL_DestroyTexture(Texture);
        Texture = loadTexture("assets/start_point.png");
    }
    game_start_motion(asset);

}