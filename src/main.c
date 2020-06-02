#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "chip8.h"
#include "chip8memory.h"
#include "chip8keyboard.h"
#include "hashtable.h"


int main(int argc, char *argv[]) 
{
    /* init chip8 */
    struct chip8 chip8;
    init_chip8(&chip8);

    //test memory functions 
    //chip8_memory_set(&chip8, 0x400, 'Z');
    //printf("%c\n",chip8_memory_get(&chip8, 0x400));
    //printf("%d\n",chip8_memory_get(&chip8, 0x402));

    //printf("%x\n",chip8_memory_get(&chip8, 0x000));
    //printf("%x\n",chip8_memory_get(&chip8, 0x001));
    //printf("%x\n",chip8_memory_get(&chip8, 0x002));
    //printf("%x\n",chip8_memory_get(&chip8, 0x003));
    //printf("%x\n",chip8_memory_get(&chip8, 0x004));

    //create hashtable 
    ht_t *ht = ht_create();

    chip8_keyboard_set_ht(&chip8, ht);

    ht_dump(&chip8.HashTable);
    printf("SDLK_0: %d = %x\n", SDLK_0,ht_get(&chip8.HashTable, SDLK_0));
    printf("SDLK_1: %d = %x\n", SDLK_1,ht_get(&chip8.HashTable, SDLK_1));
    printf("SDLK_2: %d = %x\n", SDLK_2,ht_get(&chip8.HashTable, SDLK_2));
    printf("SDLK_3: %d = %x\n", SDLK_3,ht_get(&chip8.HashTable, SDLK_3));
    printf("SDLK_4: %d = %x\n", SDLK_4,ht_get(&chip8.HashTable, SDLK_4));
    printf("SDLK_5: %d = %x\n", SDLK_5,ht_get(&chip8.HashTable, SDLK_5));
    printf("SDLK_6: %d = %x\n", SDLK_6,ht_get(&chip8.HashTable, SDLK_6));
    printf("SDLK_7: %d = %x\n", SDLK_7,ht_get(&chip8.HashTable, SDLK_7));
    printf("SDLK_8: %d = %x\n", SDLK_8,ht_get(&chip8.HashTable, SDLK_8));
    printf("SDLK_9: %d = %x\n", SDLK_9,ht_get(&chip8.HashTable, SDLK_9));
    printf("SDLK_a: %d = %x\n", SDLK_a,ht_get(&chip8.HashTable, SDLK_a));
    printf("SDLK_b: %d = %x\n", SDLK_b,ht_get(&chip8.HashTable, SDLK_b));
    printf("SDLK_c: %d = %x\n", SDLK_c,ht_get(&chip8.HashTable, SDLK_c));
    printf("SDLK_d: %d = %x\n", SDLK_d,ht_get(&chip8.HashTable, SDLK_d));
    printf("SDLK_e: %d = %x\n", SDLK_e,ht_get(&chip8.HashTable, SDLK_e));
    printf("SDLK_f: %d = %x\n", SDLK_f,ht_get(&chip8.HashTable, SDLK_f));

    /* load rom */

    /* Emulation loop */

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create SDL window 
    SDL_Window *window = SDL_CreateWindow("Chip8 Interpreter", 
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, CHIP_8_SCREEN_WIDTH * CHIP_8_UPSCALER,
    CHIP_8_SCREEN_HEIGHT * CHIP_8_UPSCALER, SDL_WINDOW_OPENGL);

    // Create a renderere (accelerated and insync with the dispay refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    

    bool running = true;
    SDL_Event event;
    while(running)
    {
        //process events
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYDOWN:
                    {
                        int key = event.key.keysym.sym;
                        int vkey = chip8_keyboard_ht(&chip8, key);
                        if(vkey != -1)
                        {
                            chip8_keyboard_down(&chip8, vkey);
                            printf("key is down %x\n", vkey);
                        }
                    }
                    break;

                case SDL_KEYUP:
                    {
                        int key = event.key.keysym.sym;
                        int vkey = chip8_keyboard_ht(&chip8, key);
                        if(vkey != -1)
                        {
                            chip8_keyboard_up(&chip8, vkey);
                            printf("key is up\n");
                        }
                    }
                    break;
            }

        }

        // Clear screen with black 
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw white pixel
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_Rect rect = {50, 100, 45, 45}; // x, y, width, height 
        SDL_RenderFillRect(renderer, &rect);

        // Display what you drew
        SDL_RenderPresent(renderer);


        // execute opcode 
        // draw to screen
        // read keypresses 
    }

    // destroy the rendering context for a window and free associated textures
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // free hash table from memory 
    ht_destroy(ht);
    ht_destroy(&chip8.HashTable);

    return 0;
}