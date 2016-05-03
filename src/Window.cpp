
#include "../includes/Window.h"
#include <stdio.h>

Window::Window(std::string title, int width, int height) {
    //Create window
	win = SDL_CreateWindow( title.c_str(),
                            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                            width, height,
                            SDL_WINDOW_SHOWN );
	//if there is a problem with the window
	if( win == NULL )
		//print a statement about it
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
	//apply the surface to the window screen
    screenSurface = SDL_GetWindowSurface( win );
}

Window::~Window() {
	//delete everything and NULLify pointers
	SDL_FreeSurface( screenSurface );
	screenSurface = NULL;
    SDL_DestroyWindow( win );
    win = NULL;
}

SDL_Window* Window::get_win() {
    return win;
}

SDL_Surface* Window::get_win_surface() {
	return screenSurface;
}


void Window::change_background_color( uint16_t r, uint16_t g, uint16_t b ) {
	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, r, g, b ) );
}

void Window::update_win() {
	//call this to flip the buffer and show the current window_screen
    SDL_UpdateWindowSurface( win );
}
