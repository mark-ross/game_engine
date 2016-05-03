#ifndef __RESOURCEMANAGER__H__
#define __RESOURCEMANAGER__H__

#include <SDL.h>
#include <string>
#include <vector>

class ResourceManager {
    private:
        //create a vector for a resource list
        std::vector<SDL_Surface*> rlist;
        //create a list of the names of files loaded
        std::vector<std::string> flist;
    public:
        //deallocate all the resources
        ~ResourceManager();
        //Add a resource, or return a pointer
        //if the resource already exists
        SDL_Surface* add_resource(std::string);
};

#endif
