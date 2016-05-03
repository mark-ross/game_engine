#include "../includes/ResourceManager.h"

#include <stdio.h>

ResourceManager::~ResourceManager() {
    //while there are things in the vector
    for(int i = 0; i < rlist.size(); i++) {
        SDL_FreeSurface(rlist[i]);
    }

    delete &flist;
    delete &rlist;

}

SDL_Surface* ResourceManager::add_resource(std::string fname) {
    for(int i = 0; i < flist.size(); i++) {
        //if the strings are equal
        //return the pointer to the texture
        if(flist[i] == fname)
            return rlist[i];
    }

    //if there is no entry, pop the name on the flist
    //and load the new texture, returning the pointer
    SDL_Surface* tmp = SDL_LoadBMP(fname.c_str());
    //check if everything is okay
    if(!tmp)    printf ("error loading sprite from%s\n", fname.c_str());
    //add it to the resource list
    else {
        flist.push_back(fname);
        rlist.push_back(tmp);
    }

    //return the address
    return tmp;
}
