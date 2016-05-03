#ifndef __ENGINE__H__
#define __ENGINE__H__

#include <SDL.h>
#include "Window.h"
#include "State.h"


class Engine {
    private:
        Window *window;
        SDL_Event events;
        State *state;
        int current_state, next_state;
        //check and see if there is a state change necessary
        void change_state();

    public:
        Engine();
        ~Engine();

        //run the 3 functions of a state
        void run_loop();
        //display the buffer
        void update_buffer();
        bool running;
};

#endif  //__ENGINE__H__
