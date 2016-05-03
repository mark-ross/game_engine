/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "includes/Engine.h"

int main( int argc, char* args[] )
{
	Engine game;

	while(game.running == true) {
		game.run_loop();
		game.update_buffer();
	}

	delete &game;
	return 0;
}
