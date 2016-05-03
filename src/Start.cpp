#include "../includes/Start.h"
#include <string>

Start::Start(SDL_Surface* s) {
    state_flag = 0;

    //make a new resource manager
    resources = new ResourceManager();
    //make a new character manager
    characters = new CharacterManager(s);
    //add the resource
    SDL_Surface* tmp = resources->add_resource(std::string("resources/usa.bmp"));
    //create the character
    flag = new Character(tmp, 0, 0);
    //add character to manager
    characters->add_sprite(flag);
}

Start::~Start() {
    delete resources;
    delete characters;
}

void Start::events(SDL_Event *e) {
    //CODE LARGELY INFLUENCE BY LAZY FOO
    while( SDL_PollEvent( e ) != 0) {
        if( e->type == SDL_QUIT ) {
            state_flag = -1;

        } else if( e->type == SDL_KEYDOWN ) {

            switch(e->key.keysym.sym ) {
                case SDLK_ESCAPE: state_flag = -1; break;
            }

        }
        characters->events();
    }
}

void Start::update(int *next_state) {
    //do logical calculations here
    *next_state = state_flag;
}

void Start::draw() {
    //flag->draw_image( window->get_win_surface() );
    characters->draw_sprites();
}
