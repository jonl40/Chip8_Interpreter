#include "chip8.h"
#include "SDL2/SDL.h"
#include "hashtable.h"

/* Set hashtable with SDLK key and value pairs */
void chip8_keyboard_set_ht(struct chip8 *chip8, ht_t *hashtable)
{
    // key, value 
    ht_set(hashtable, SDLK_0, 0);
    ht_set(hashtable, SDLK_1, 1);
    ht_set(hashtable, SDLK_2, 2);
    ht_set(hashtable, SDLK_3, 3);
    ht_set(hashtable, SDLK_4, 4);
    ht_set(hashtable, SDLK_5, 5);
    ht_set(hashtable, SDLK_6, 6);
    ht_set(hashtable, SDLK_7, 7);
    ht_set(hashtable, SDLK_8, 8);
    ht_set(hashtable, SDLK_9, 9);
    ht_set(hashtable, SDLK_a, 10);
    ht_set(hashtable, SDLK_b, 11);
    ht_set(hashtable, SDLK_c, 12);
    ht_set(hashtable, SDLK_d, 13);
    ht_set(hashtable, SDLK_e, 14);
    ht_set(hashtable, SDLK_f, 15);
    chip8->HashTable = *hashtable;
}


/* Get value mapped to keyboard key*/
int chip8_keyboard_ht(struct chip8 *chip8, int key)
{
    int vkey = ht_get(&chip8->HashTable, key);
    return vkey;
}

/* Set chip8 keyboard array to true at key index */
/* Key pressed down denoted by true */
void chip8_keyboard_down(struct chip8 *chip8, int key)
{
    chip8->keyboard[key] = true;
}

/* Set chip8 keyboard array to false at key index */
/* Unpressed key denoted by false */
void chip8_keyboard_up(struct chip8 *chip8, int key)
{
    chip8->keyboard[key] = false;
}

/* Return true if specified key is down */
/* Return false if specified key is up */
bool chip8_keyboard_is_down(struct chip8 *chip8, int key)
{
    return chip8->keyboard[key];
}

