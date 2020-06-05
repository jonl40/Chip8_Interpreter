#include <memory.h>
#include "chip8.h"
#include "config.h"

const char chip8_default_character_set[] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0,           //0 
    0x20, 0x60, 0x20, 0x20, 0x70,           //1
    0xF0, 0x10, 0xF0, 0x80, 0xF0,           //2
    0xF0, 0x10, 0xF0, 0x10, 0xF0,           //3
    0x90, 0x90, 0xF0, 0x10, 0x10,           //4
    0xF0, 0x80, 0xF0, 0x10, 0xF0,           //5
    0xF0, 0x80, 0xF0, 0x90, 0xF0,           //6
    0xF0, 0x10, 0x20, 0x40, 0x40,           //7
    0xF0, 0x90, 0xF0, 0x90, 0xF0,           //8
    0xF0, 0x90, 0xF0, 0x10, 0xF0,           //9
    0xF0, 0x90, 0xF0, 0x90, 0x90,           //A
    0xE0, 0x90, 0xE0, 0x90, 0xE0,           //B
    0xF0, 0x80, 0x80, 0x80, 0xF0,           //C
    0xE0, 0x90, 0x90, 0x90, 0xE0,           //D
    0xF0, 0x80, 0xF0, 0x80, 0xF0,           //E
    0xF0, 0x80, 0xF0, 0x80, 0x80            //F
};

/* Initalize all chip8 memory to zero */
/* Load character set into memory starting at 0x000 */
/* Initalize stack pointer to -1 */
void init_chip8(struct chip8 *chip8)
{
    memset(chip8, 0, sizeof(struct chip8)); //initialize all chip8 memory to zero 
    memcpy(&chip8->Memory, chip8_default_character_set, sizeof(chip8_default_character_set));  //load character set into memory
    chip8->SP = -1;
}

