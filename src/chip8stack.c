#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include "chip8.h"
#include "chip8stack.h"

/* When SP == -1 stack is empty */
/* Asserts that the stack is not empty */
static bool isnotempty(struct chip8 *chip8)
{
    assert(chip8->SP > -1);
}

/* When SP == CHIP8_STACK_SIZE stack is full */
/* Asserts that the stack is not full */
static bool isnotfull(struct chip8 *chip8)
{
    assert(chip8->SP < CHIP8_STACK_SIZE);
}

/* Push value onto stack */
void chip8_stack_push(struct chip8 *chip8, uint16_t val)
{
    chip8->SP += 1;
    isnotfull(chip8);
    chip8->Stack[chip8->SP] = val;
}

/* Pop value off of stack */
uint16_t chip8_stack_pop(struct chip8 *chip8)
{
    isnotempty(chip8);
    uint16_t val = chip8->Stack[chip8->SP];
    chip8->SP -= 1;
    return val;
}