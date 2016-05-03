#ifndef __START__H__
#define __START__H__

#include <SDL.h>
#include "State.h"
#include "ResourceManager.h"
#include "CharacterManager.h"
#include "Character.h"

class Start : public State {
    private:
        ResourceManager *resources;
        CharacterManager *characters;
        Character *flag;
        int state_flag;

    public:
        Start(SDL_Surface*);
        ~Start();

        void draw();
        void events(SDL_Event*);
        void update(int*);
};

#endif  //__START__H__
