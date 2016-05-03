#ifndef __CHARACTER__H__
#define __CHARACTER__H__

//include the SDL Libraries if needed
#include <SDL.h>
#include <string>

class Character {
    public:
        Character( SDL_Surface*, int=0, int=0, int=0, int=0 );
        ~Character();

        SDL_Surface* get_sprite();
        SDL_Rect* get_offset();

        //return different from the class
        int get_x();
        int get_y();

        int get_xvel();
        int get_yvel();

        bool get_visibility();
        int get_priority();  //otherwise the Z order

        //this is for directly setting the character's position
        void set_x(int);
        void set_y(int);

        //set the rate of movement for x and y
        void set_xvel(int);
        void set_yvel(int);

        //this dtermines whether a character is visible on screen or not
        void set_visibility(bool);
        //determine the priority of the sprite on the screen
        void set_priority(int);

        //this is for easily moving the character
        void move_x(int);
        void move_y(int);

        //move the x and y by the stated velocity
        void move_x_vel();
        void move_y_vel();

        //allows each of these to
        //detailed per each child
        //virtual void events() {};

        bool operator < (const Character &rhs) const { return priority < rhs.priority; }

    private:
        SDL_Surface* sprite;
        SDL_Rect pos;
        bool visible;
        int priority;
        int xvel, yvel;
};

#endif //__CHARACTER__H__
