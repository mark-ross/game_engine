#include "../includes/CharacterManager.h"

#include <algorithm>

CharacterManager::CharacterManager(SDL_Surface* s) {
    //set the drawing screen
    screen = s;
}

CharacterManager::~CharacterManager() {
    delete &characters;
}

void CharacterManager::add_sprite(Character *c) {
    characters.push_back(c);
}

void CharacterManager::events() {
    for(int i = 0; i < characters.size(); i++) {
        //do the event stuff here
        //characters[i]->events();
    }
}

void CharacterManager::draw_sprites() {
    //sort by priority
    std::sort(characters.begin(), characters.end());
    //draw them all on the screen
    for(int i = 0; i < characters.size(); i++) {
        if(characters[i]->get_visibility()) {
            SDL_BlitSurface(characters[i]->get_sprite(), NULL,
                            screen, characters[i]->get_offset());
        }
    }
}
