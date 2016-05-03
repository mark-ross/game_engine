#ifndef __STATE__H__
#define __STATE__H__

#include <SDL.h>
#include "Window.h"

class State {
    public:
        //show the buffer on the screen
        virtual void draw(Window*) {};
        //handle any button presses
        virtual void events(SDL_Event*) {};
        //update all the data necessary
        virtual void update(int*) {};
};

#endif  //__STATE__H__
