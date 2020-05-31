#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

unsigned int hash(int key) {
    unsigned long int value = 0;
    // make sure value is 0 <= value < TABLE_SIZE
    value = key % TABLE_SIZE;
    return value;
}

entry_t *ht_pair(int key, int value) {
    // allocate the entry
    entry_t *entry = malloc(sizeof(entry_t) * 1);

    // copy the key and value in place
    entry->key = key;
    entry->value = value;

    // next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}

ht_t *internal_ht_create(int size) {
    // allocate table
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);

    // allocate table entries
    hashtable->size = size;
    hashtable->entries = malloc(sizeof(entry_t*) * hashtable->size);

    // set each to null (needed for proper operation)
    int i = 0;
    for (; i < size; ++i) {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

ht_t *ht_create(void)
{
    return internal_ht_create(TABLE_SIZE);
}

void ht_set(ht_t *hashtable, int key, int value) {
    unsigned int slot = hash(key);

    // try to look up an entry set
    entry_t *entry = hashtable->entries[slot];

    // no entry means slot empty, insert immediately
    if (entry == NULL) {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    entry_t *prev;

    // walk through each entry until either the end is
    // reached or a matching key is found
    while (entry != NULL) {
        // check key
        if (entry->key == key) {
            // match found, return
            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;
    }

    // end of chain reached without a match, add new
    prev->next = ht_pair(key, value);
}

int ht_get(ht_t *hashtable, int key) {
    unsigned int slot = hash(key);

    // try to find a valid slot
    entry_t *entry = hashtable->entries[slot];

    // no slot means no entry
    if (entry == NULL) {
        return NULL;
    }

    // walk through each entry in the slot, which could just be a single thing
    while (entry != NULL) {
        // return value if found
        if (entry->key == key) {
            return entry->value;
        }

        // proceed to next key if available
        entry = entry->next;
    }

    // reaching here means there were >= 1 entries but no key match
    return NULL;
}

void ht_dump(ht_t *hashtable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        entry_t *entry = hashtable->entries[i];

        if (entry == NULL) {
            continue;
        }

        printf("slot[%4d]: ", i);

        for(;;) {
            printf("%d=%x ", entry->key, entry->value);

            if (entry->next == NULL) {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}


void ht_destroy(ht_t *hashtable)
{
    int i;
    entry_t *cur;
    entry_t *next;

    for(i = 0; i < hashtable->size; i++) {
        for(cur = hashtable->entries[i]; cur != 0; cur = next) {
            next = cur->next;
            free(cur);
        }
    }

    free(hashtable->entries);
    free(hashtable);
}
