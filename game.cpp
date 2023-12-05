#include "game.hpp"
// #include "player->hpp"
// #include "TopGun.hpp"

bool Game::init(){
    //variable that will tell whether the initialization was successful or not
    bool success = true;

    //initializing SDL
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 ){
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else{

        //Texture filtering 
        if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")){
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        //Creating window
        window = SDL_CreateWindow( "TOP GUN CHALLENGE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
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
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
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

    Mix_FreeMusic(bg_music);
	bg_music = NULL;

    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

bool Game::load_media(){
    bool success = true;

    Texture = loadTexture("assets/StartScreen.png");
    assets = loadTexture("assets/plane_lists.png");

    if (Texture == NULL|| assets == NULL){
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success = false;
    }
    bg_music = Mix_LoadMUS( "assets/OOPGame.wav" );
	if(bg_music == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
    if (Mix_PlayMusic(bg_music, -1) == -1) {
    printf("Unable to play music: %s\n", Mix_GetError());
    success = false;
    }
    Mix_VolumeMusic(MIX_MAX_VOLUME / 16);    
    
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

    SDL_Rect Texture_src = {0, 1270, 500, 650}; //This for the background 
    
    // TopGun topgun;

    // int x_coord = rand() % (screen_width);
    // Enemy enemy(x_coord,0);   //This is the enemy's plane
    clock_t lastCreationTime = clock(); // Initialize with current time
    const int creationInterval = CLOCKS_PER_SEC * 5; // 2 seconds

    //Infinite loop untill the user quits the game
    while(!quit_game){
        
        while(SDL_PollEvent(&event) != 0){
            if (event.type == SDL_QUIT){
                quit_game = true;
            }

            //We will need the folowing if statement only when the player starts playing 

            // if (event.type == SDL_KEYDOWN){
            //     //Call a function that will affect the game (This will shw a short animation of plane taking off a place)
            //     game_start(renderer, assets, event.key.keysym.sym);
            // }
            
                // This is just to see the exact co-ordinate that will help in future for placing planes at exact point
            if (event.type == SDL_MOUSEBUTTONDOWN){
                int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
                std::cout << xMouse << " : " << yMouse << '\n';
            }
            if (state == 0 && event.type == SDL_MOUSEBUTTONDOWN) {
                int xMouse, yMouse;
                SDL_GetMouseState(&xMouse, &yMouse);

                if (xMouse >= 187 && xMouse <= 312 && yMouse >= 396 && yMouse <= 438) {
                    // Change the background when the click is within the specified coordinates
                    SDL_DestroyTexture(Texture);
                    Texture = loadTexture("assets/start_point.png");
                    state = 1; // Change the state after the background is changed
                }
                if (xMouse >= 187 && xMouse <= 312 && yMouse >= 548 && yMouse <= 590) {
                    // Close the game when the click is within the specified coordinates
                    quit_game = true;
                }
            }

            if (state == 2){
                const Uint8* state = SDL_GetKeyboardState(NULL);
                if ((state[SDL_SCANCODE_F] == ' ')){
                    player->set_delay(0);
                }
            }
        }   

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, Texture, NULL, NULL);


        // Using if statements since different states would require different delays
        //Future plan: Use switch which would be maybe faster and would look more suitable for this scenerio

        if(state == 1) {
            game_start_motion(renderer, assets);
            SDL_RenderPresent(renderer);
            SDL_Delay(0);   // delay set to 0 for now
        }
        else if (state == 2){
            //Now we need to update the renderer so there is a new background with a plane that will be controlled
            
            //The following code updates the renderer everytime making it look as the background is moving 

            SDL_RenderClear(renderer);
            SDL_DestroyTexture(Texture);
 
            Texture = loadTexture("assets/background.png");            
            if (Texture_src.y > -Texture_src.h){
                SDL_RenderCopy(renderer, Texture, &Texture_src, nullptr);
                
                Texture_src.y -=0.01;
                player->move(screen_width, screen_height);
                player->display(renderer, assets);

                player->shoot();
                player->move_bullet();
                player->display_bullet(renderer, assets);
                

                clock_t currentTime = clock();
                if ((currentTime - lastCreationTime) >= creationInterval) {
                    int x = rand() % (screen_width-75);
                    // Add the new object to vector of enemy plane
                    enemy_vector.push_back(new EnemyPlane1(x, 0, (rand() % 4)));

                    // Update the last creation time
                    lastCreationTime = currentTime;
                }

                // Render and move existing objects in vector of enemy plane
                for (int i=0; i <enemy_vector.size(); i++){
                    Object * enemy = enemy_vector[i];
                    SDL_Rect mover = enemy->get_mover();
                    if (mover.y < screen_height){
                        enemy->display(renderer,assets);
                        enemy->move();
                        enemy->move_bullet(screen_height);
                        enemy->display_bullet(renderer, assets);
                    }
                    else {
                        enemy_vector.erase(enemy_vector.begin() + i);
                        std::cout << "enemy deleted\n";
                    }
                }


                // Checking collision enemy bullet to player 
                SDL_Rect p_mvr = player->get_mover();
                for (auto enemy : enemy_vector){
                    SDL_Rect enmy_mvr = enemy->get_mover();
                    if (SDL_HasIntersection(&p_mvr, &enmy_mvr)){
                        std::cout << "Plane Plane\n";
                    }
                    if (player->collision_current_opponent_bullet(enemy)){
                        std::cout << "Player bullet hit enemy\n";
                    }
                    if (enemy->collision_current_opponent_bullet(player)){
                        std::cout << "enemy bullet hit player\n";
                    }
                    player->collision_player_enemy_bullet(enemy);
                }
                


            }
            SDL_RenderPresent(renderer);
        }
        else{
            SDL_RenderPresent(renderer);
            SDL_Delay(200);
        }
        
    }
    Game::close();
}

void Game::game_start_motion(SDL_Renderer* renderer, SDL_Texture* assets){

    if (start_plane.mover_rect.y < (screen_height/2.0)){        // This statment only increases the x value of the plane giving 3d look
        start_plane.mover_rect.x+=1.5;
    }

    if (start_plane.mover_rect.y > -(start_plane.mover_rect.h)) {
        // Render the plane at its updated position
        SDL_RenderCopy(renderer, assets, &start_plane.src_rect, &start_plane.mover_rect);
        // Move the plane upward
        start_plane.mover_rect.y -= 5;
    } else {
        // if the plane reaches the top of the screen change the state of the game to 2 (where the game start)
        state = 2;
    }
    
    
}

void Game::game_start(SDL_Renderer* renderer, SDL_Texture* assets, SDL_Keycode key){
    //The function will be later modified as a mover for the players plane 
    if (key == SDLK_LEFT) { 
        start_plane.mover_rect.x -= 10;  // Moving the planes with keys
    } else if (key == SDLK_RIGHT) {
        start_plane.mover_rect.x += 10;  
    }
    if (key == SDLK_UP) {
        start_plane.mover_rect.y -= 10;  
    } else if (key == SDLK_DOWN) {
        start_plane.mover_rect.y += 10;  
    }
    
}