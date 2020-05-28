#ifndef CHIP8MEMORY_H
#define CHIP8MEMORY_H

#include "chip8.h"

void chip8_memory_set(struct chip8 *chip8, int index, uint8_t val);
uint8_t chip8_memory_get(struct chip8 *chip8, int index);

#endif 