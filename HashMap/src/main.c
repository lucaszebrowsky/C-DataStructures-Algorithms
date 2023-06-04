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
#include "HashMap.h"

int main(void) {

    struct HashMap* map = initHashMap(10);

    if (NULL == map) {
        fprintf(stderr, "Could not allocate memory for the hashmap!\n");
        return 1;
    }

    // 2 Items that create a collison (same Hash)
    char* key1 = "Foo";
    int val1 = 69;

    char* key2 = "ooF";
    int val2 = 420;

    addEntry(map, key1, val1);
    addEntry(map, key2, val2);

    struct Entry* entry1 = getEntry(map, key1);
    struct Entry* entry2 = getEntry(map, key2);

    if (NULL != entry1) {
        printf("Item 1: Key: %s, Value: %d\n", entry1->key, entry1->value);
    }

    if (NULL != entry2) {
        printf("Item 2: Key: %s, Value: %d\n", entry2->key, entry2->value);
    }

    freeHashMap(map);

    return 0;
}