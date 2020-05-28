#include <stdio.h>
#include "chip8.h"
#include "chip8memory.h"

int main(int argc, char *argv[]) 
{
    /* init chip8 */
    struct chip8 chip8;
    init_chip8(&chip8);

    //test memory functions 
    chip8_memory_set(&chip8, 0x400, 'Z');
    printf("%c\n",chip8_memory_get(&chip8, 0x400));
    printf("%d\n",chip8_memory_get(&chip8, 0x402));

    printf("%x\n",chip8_memory_get(&chip8, 0x000));
    printf("%x\n",chip8_memory_get(&chip8, 0x001));
    printf("%x\n",chip8_memory_get(&chip8, 0x002));
    printf("%x\n",chip8_memory_get(&chip8, 0x003));
    printf("%x\n",chip8_memory_get(&chip8, 0x004));

    /* load rom */

    /* Emulation loop */
    // execute opcode 
    // draw to screen
    // read keypresses 

    return 0;
}