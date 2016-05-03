#include "../includes/Character.h"

#include <stdio.h>

Character::Character(SDL_Surface* image, int nx, int ny, int nvx, int nvy) {
    //sprite = SDL_LoadBMP(fname.c_str());
    sprite = image;
    if(sprite == NULL)
        printf("Error locating the image");
    pos.x = nx;
    pos.y = ny;
    visible = true;
    priority = 10;
    xvel = nvx;
    yvel = nvy;
}

Character::~Character() {
    printf("Deleted!");
}

SDL_Surface* Character::get_sprite() {
    return sprite;
}

int Character::get_x() {
    return pos.x;
}

int Character::get_y() {
    return pos.y;
}

bool Character::get_visibility() {
    return visible;
}

int Character::get_priority() {
    return priority;
}

SDL_Rect* Character::get_offset() {
    return &pos;
}

void Character::set_visibility(bool p) {
    visible = p;
}

void Character::set_priority(int p) {
    priority = p;
}

void Character::set_x(int nx) {
    pos.x = nx;
}

void Character::set_y(int ny) {
    pos.y = ny;
}

void Character::set_xvel(int nxv) {
    xvel = nxv;
}

void Character::set_yvel(int nxy) {
    yvel = nxy;
}

void Character::move_x(int p) {
    pos.x += p;
}

void Character::move_y(int p) {
    pos.y += p;
}

void Character::move_x_vel() {
    pos.x += xvel;
}

void Character::move_y_vel() {
    pos.y += yvel;
}
