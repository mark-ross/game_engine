#ifndef __WINDOW__H__
#define __WINDOW__H__

#include <SDL.h>
#include <string>

class Window {
    private:
        SDL_Window *win;
        SDL_Surface *screenSurface;

    public:
        Window(std::string title, int width, int height);
        ~Window();

        //returns a pointer to the window itself
        SDL_Window* get_win();
        //returns a pointer to the screen surface object
        SDL_Surface* get_win_surface();

        //change the background color to whatever
        void change_background_color( uint16_t, uint16_t, uint16_t );
        //update the window to display all the changes
        void update_win();
};

#endif //__WINDOW__H__
