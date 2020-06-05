#ifndef CHIP8SCREEN_H
#define CHIP8SCREEN_H

#include <stdbool.h>
#include "chip8.h"
#include "config.h"

void chip8_pixel_set(struct chip8 *chip8, int x, int y);
bool chip8_pixel_is_set(struct chip8 *chip8, int x, int y);
bool chip8_render_sprite(struct chip8 *chip8, int x, int y, const char *sprite, int num);

#endif