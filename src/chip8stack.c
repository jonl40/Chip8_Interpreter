#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "chip8.h"
#include "chip8stack.h"

static bool isnotempty(struct chip8 *chip8)
{
    assert(chip8->SP > -1);
}

static bool isnotfull(struct chip8 *chip8)
{
    assert(chip8->SP < CHIP8_STACK_SIZE);
}


void chip8_stack_push(struct chip8 *chip8, uint16_t val)
{
    chip8->SP += 1;
    isnotfull(chip8);
    chip8->Stack[chip8->SP] = val;
}

uint16_t chip8_stack_pop(struct chip8 *chip8)
{
    isnotempty(chip8);
    uint16_t val = chip8->Stack[chip8->SP];
    chip8->SP -= 1;
    return val;
}