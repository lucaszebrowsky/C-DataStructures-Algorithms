/*
 *  MIT License
 *
 * Copyright (c) 2023 Lu-Die-Milchkuh
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashMap.h"

/**
 *  Initilizes a new HashMap wit the specified capacity
 *
 *  @param capacity The initial capacity of the HashMap
 *  @return A pointer to the newlly created HashMap on success, or NULL
 *  if memory allocation fails or the capacity is zero
 */
struct HashMap* initHashMap(size_t capacity) {
    struct HashMap* map = calloc(1, sizeof(struct HashMap));

    if (NULL == map) {
        return NULL;
    }

    // Don't allow Zero Length Arrays
    if (0 == capacity) {
        return NULL;
    }

    map->array = calloc(capacity, sizeof(struct Entry*));

    if (NULL == map->array) {
        free(map);
        return NULL;
    }

    map->capacity = capacity;
    map->size = 0;

    return map;
}

/**
 * Computes the hash value for a given key in the HashMap.
 *
 * @param map The HashMap structure.
 * @param key The key for which the hash value needs to be computed.
 * @return The hash value of the key.
 */
static size_t getHash(struct HashMap* map, char* key) {
    size_t hash = 0;
    size_t i = 0;
    char c;

    while ((c = key[i]) != '\0') {
        hash = c + (hash << 6) + (hash << 16) - hash;
        i++;
    }

    return hash % map->capacity;
}

/**
 * Resizes the HashMap by creating a new HashMap with double the capacity
 * and rehashing all entries from the old HashMap into the new HashMap.
 *
 * @param map The HashMap structure to be resized.
 */
static void resizeHashMap(struct HashMap* map) {
    if (NULL == map) {
        return;
    }

    struct HashMap* newMap = initHashMap(map->capacity * 2);

    if (NULL == newMap) {
        return;
    }

    for (size_t i = 0; i < map->capacity;i++) {
        struct Entry* currentEntry = map->array[i];

        while (NULL != currentEntry) {
            addEntry(newMap, currentEntry->key, currentEntry->value);
            currentEntry = currentEntry->next;
        }
    }

    map->capacity = newMap->capacity;
    free(map->array);
    map->array = newMap->array;

    free(newMap);
    newMap = NULL;
}

/**
 * Adds an entry with the specified key-value pair to the HashMap.
 * Automatically invokes resizeHashMap if the loadfactor reaches 75%
 *
 * @param map The HashMap structure to be resized.
 * @param key The string that acts as a key for the new Entry
 * @param value The value of the new Entry
 * @return a Pointer to the new Entry on success, or NULL on failure
 */
struct Entry* addEntry(struct HashMap* map, char* key, int value) {
    if (NULL == map) {
        return NULL;
    }

    size_t index = getHash(map, key);

    struct Entry* newEntry = calloc(1, sizeof(struct Entry));

    if (NULL == newEntry) {
        return NULL;
    }

    // Creating a copy of the original key
    size_t keyLen = strlen(key) + 1;
    char* newKey = calloc(keyLen, sizeof(char));

    if (NULL == newKey) {
        free(newEntry);
        return NULL;
    }

    memcpy(newKey, key, keyLen);
    newEntry->key = newKey;

    newEntry->value = value;
    newEntry->next = NULL;

    struct Entry* currentEntry = map->array[index];

    // is the "bucket" empty?
    if (NULL == currentEntry) {
        map->array[index] = newEntry;
    }
    else {
        while (NULL != currentEntry->next) {
            currentEntry = currentEntry->next;
        }

        currentEntry->next = newEntry;
    }

    map->size++;

    float loadFactor = (float)map->size / map->capacity;

    if (loadFactor >= 0.75f) {
        resizeHashMap(map);
    }

    return newEntry;
}

/**
 * Retrieves the entry associated with the given key from the HashMap.
 *
 * @param map The HashMap structure to be searched.
 * @param key The key to look for in the HashMap
 * @return A pointer to the Entry on success, or NULL if the key could not be found
 */
struct Entry* getEntry(struct HashMap* map, char* key) {
    if (NULL == map) {
        return NULL;
    }

    size_t index = getHash(map, key);

    struct Entry* currentEntry = map->array[index];

    while (NULL != currentEntry && 0 != strcmp(key, currentEntry->key)) {
        currentEntry = currentEntry->next;
    }

    return currentEntry;
}

/**
 *  Frees the memory occupied by the HashMap and all its associated entries.
 *
 *  @param map The HashMap structure to be freed.
 */
void freeHashMap(struct HashMap* map) {
    if (NULL == map) {
        return;
    }

    for (size_t i = 0; i < map->capacity; i++) {
        struct Entry* entry = map->array[i];

        while (NULL != entry) {
            struct Entry* nextEntry = entry->next;
            free(entry->key);
            free(entry);
            entry = nextEntry;
        }
    }

    free(map->array);
    free(map);
    map = NULL;
}
