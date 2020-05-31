#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "config.h"
#define TABLE_SIZE 30

typedef struct entry_t {
    int key;
    int value;
    struct entry_t *next;
} entry_t;

typedef struct {
    int size;
    entry_t **entries;
} ht_t;

unsigned int hash(int key);
entry_t *ht_pair(int key, int value);
ht_t *internal_ht_create(int size);
ht_t *ht_create(void);
void ht_set(ht_t *hashtable, int key, int value);
int ht_get(ht_t *hashtable, int key);
void ht_dump(ht_t *hashtable);
void ht_destroy(ht_t *hashtable);

#endif 