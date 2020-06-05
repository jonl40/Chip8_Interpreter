#include <assert.h>
#include "chip8screen.h"

static void chip8_screen_in_bounds(int x, int y)
{
    assert(x >= 0 && x < CHIP_8_SCREEN_WIDTH && y >=0 && y < CHIP_8_SCREEN_HEIGHT);
}

/* Set pixel value to true */
void chip8_pixel_set(struct chip8 *chip8, int x, int y)
{
    chip8_screen_in_bounds(x,y);
    chip8->Pixels[x][y] = true;
}

/* Return true if pixel at specified index is set */
/* Return false if pixel at specified index is not set */
bool chip8_pixel_is_set(struct chip8 *chip8, int x, int y)
{
    chip8_screen_in_bounds(x,y);
    return chip8->Pixels[x][y];
}

/* Render sprite to screen */
/* Return true if collision is detected */
bool chip8_render_sprite(struct chip8 *chip8, int x, int y, const char *sprite, int num)
{
    chip8_screen_in_bounds(x,y);
    // VF register set to 0 if no collision is detected
    bool VF_collision = false;

    for(int yi = 0; yi < num; yi++)
    {
        char sprite_row = sprite[yi];
        for(int xi = 0; xi < 8; xi++)
        {
           if((0b10000000 & (sprite_row << xi)) == 0b10000000)
           {
                if(chip8->Pixels[(x + xi) % CHIP_8_SCREEN_WIDTH][(y + yi) % CHIP_8_SCREEN_HEIGHT])
                {
                    //see if pixel you are going to draw to is already set
                    bool VF_collision = true;
                }
                //sprites wrap around screen if outside bounds, xor values
                chip8->Pixels[(x + xi) % CHIP_8_SCREEN_WIDTH][(y + yi) % CHIP_8_SCREEN_HEIGHT] ^= true;
           }
        }
    }

    return VF_collision;
}