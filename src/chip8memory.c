#include <assert.h>
#include "chip8memory.h"

static void chip8_memory_in_bounds(int index)
{
    assert(index >= 0 && index <= CHIP8_TOTAL_MEMORY);
}

void chip8_memory_set(struct chip8 *chip8, int index, uint8_t val)
{
    chip8_memory_in_bounds(index);
    chip8->Memory[index] = val;
}

uint8_t chip8_memory_get(struct chip8 *chip8, int index)
{
    chip8_memory_in_bounds(index);
    uint8_t val;
    val = chip8->Memory[index];
    return val;
}
