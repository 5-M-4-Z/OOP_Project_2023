#include "game.hpp"


void Game::run(){
    bool quit_game = false;
    SDL_Event = event;

    //Infinite loop untill the user quits the game
    while(!quit){






    }
}

void Game::close(){

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

    return 0;
}