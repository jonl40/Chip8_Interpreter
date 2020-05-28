#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>
#include <stdbool.h>
#include "config.h"

struct chip8
{
    uint8_t V[NUM_GP_REGISTERS];
    uint16_t I;
    uint8_t Delay_timer;
    uint8_t Sound_timer;
    uint16_t PC;
    uint8_t SP;
    uint8_t Memory[CHIP8_TOTAL_MEMORY];
    uint16_t Stack[CHIP8_STACK_SIZE];
    bool Pixels[CHIP_8_SCREEN_WIDTH][CHIP_8_SCREEN_HEIGHT];
    bool keyboard[CHIP8_TOTAL_KEYS];
    const char *keyboard_map;
};

void init_chip8(struct chip8 *chip8);

#endif 