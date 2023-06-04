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

#pragma once

struct Entry {
    char* key;
    int value;
    struct Entry* next;
};

struct HashMap {
    struct Entry** array;           // array of pointers to entries
    size_t size;                    // number of items in the hashmap
    size_t capacity;                // length of the array of entries
};

/*
 * Allocates a new HashMap with the specified initial capacity.
 * Returns a pointer to the newly created HashMap on success, or NULL if allocation fails.
 * It is the caller's responsibility to free the HashMap using
 * the freeHashMap function when it is no longer needed.
 */
struct HashMap* initHashMap(size_t capacity);

/*
 * Adds an entry with the specified key-value pair to the HashMap.
 * Returns a pointer to the newly created Entry on success, or NULL if an error occurs.
 * If the key already exists, the value will be updated.
 * If the HashMap needs to be resized due to a high load factor, it will be automatically resized.
 * Note: The key string will be copied internally, so the caller is responsible for managing the original key's memory.
 */
struct Entry* addEntry(struct HashMap* map, char* key, int value);

/*
 * Retrieves the entry associated with the given key from the HashMap.
 * Returns a pointer to the Entry if found, or NULL if the key is not present in the HashMap.
 */
struct Entry* getEntry(struct HashMap* map, char* key);

/*
 * Frees the memory occupied by the HashMap and all its associated entries.
 * Note: This function does not free the memory occupied by the original key strings.
 * It is the caller's responsibility to manage the memory of key strings before calling this function.
 */
void freeHashMap(struct HashMap* map);
