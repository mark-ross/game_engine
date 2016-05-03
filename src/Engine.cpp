#include "../includes/Engine.h"
#include "../includes/constants.h"
#include "../includes/Start.h"
#include <stdio.h>

Engine::Engine() {

    //this if for the main loop
    running = true;

    //initialize the video stuff
    if( SDL_Init( SDL_INIT_VIDEO ) < 0)
        //print an error otherise
        printf("Error initializing SDL Video: %s\n", SDL_GetError());
    else {
        //create the window ----- SEE CONSTANTS.H
        window = new Window(GAME_TITLE.c_str(), SCREEN_WIDTH, SCREEN_HEIGHT);
        //if there was an error creating the window
        if(window->get_win() == NULL)
            //print the error message
            printf("Error creating window: %s\n", SDL_GetError());
        //otherwise set the background color
        else window->change_background_color(255,255,255);
        //initialize to starting state
        current_state, next_state = 0;
        change_state();
    }
}

Engine::~Engine() {
    //release the resources
    //and set pointers to NULL
    delete state; state = NULL;
    delete window; window = NULL;

    //quit out of SDL
    SDL_Quit();
}

void Engine::run_loop() {
    state->events( &events );
    state->update( &next_state );
    change_state();
    state->draw( window );
}

void Engine::update_buffer() {
    window->update_win();
}

/*********************************
Update new states in this function
*********************************/
void Engine::change_state() {
    if(current_state != next_state) {
        current_state = next_state;
        switch(current_state) {
            case -1:
                running = false;
                break;
            case 0:
                state = new Start(window->get_win_surface());
                break;
        }
    }
}
