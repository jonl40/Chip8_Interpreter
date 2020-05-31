#ifndef CHIP8KEYBOARD_H
#define CHIP8KEYBOARD_H

#include "config.h"
#include "chip8.h"
#include "SDL2/SDL.h"
#include "hashtable.h"

void chip8_keyboard_set_ht(struct chip8 *chip8, ht_t *hashtable);

#endif 