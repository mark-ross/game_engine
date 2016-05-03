#ifndef __CHARACTERMANAGER__H__
#define __CHARACTERMANAGER__H__

#include <SDL.h>
#include "Character.h"
#include <vector>

class CharacterManager {
    private:
        std::vector<Character*> characters;
        SDL_Surface *screen;

    public:
        //Require the surface for which
        //to display the image
        CharacterManager(SDL_Surface*);
        ~CharacterManager();

        //This adds a sprite to the queue
        //It also accepts a priority number
        void add_sprite(Character*);
        //process events for all characters
        void events();
        //draw all the sprites on the screen
        void draw_sprites();
};

#endif //__CHARACTERMANAGER__H__
