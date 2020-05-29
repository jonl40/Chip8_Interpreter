#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"
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
            if(event.type == SDL_QUIT)
                running = false; 
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

    return 0;
}