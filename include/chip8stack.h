#ifndef CHIP8STACK_H
#define CHIP8STACK_H

#include <stdint.h>
#include "config.h"
#include "chip8.h"

void chip8_stack_push(struct chip8 *chip8, uint16_t val);
uint16_t chip8_stack_pop(struct chip8 *chip8);

#endif 