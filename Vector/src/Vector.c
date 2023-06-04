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
#include "Vector.h"

/**
  * Allocates an initial capacity for the vector and sets every element to 0.
  *
  * @param capacity An initial capacity for the vector structure
  * @return A pointer to a vector structure on success, or NULL on failure.
  */
struct vector* initVector(size_t capacity) {
    struct vector* vector = calloc(1, sizeof(struct vector));

    if (NULL == vector) {
        return NULL;
    }

    vector->array = calloc(capacity, sizeof(int));

    if (NULL == vector->array) {
        free(vector);
        return NULL;
    }

    vector->size = 0;
    vector->capacity = capacity;

    return vector;
}

/**
 * Adds an integer to the vector.
 *
 * @param vector A pointer to the vector structure.
 * @param value The integer value to be added to the vector.
 */
void addToVector(struct vector* vector, int value) {
    // Checking if the array has to be resized.
    if (vector->size > vector->capacity) {
        vector->capacity *= 2;
        vector->array = realloc(vector->array, sizeof(int) * vector->capacity);
    }

    vector->array[vector->size] = value;
    vector->size++;
}

/**
 * Returns the value stored in the vector at the given position.
 *
 * @param vector A pointer to the vector structure.
 * @param index The index position of the value to retrieve.
 * @return The value stored in the vector at the specified index.
 */
int getValueFromVector(struct vector* vector, size_t index) {
    if (index > vector->size - 1) {
        fprintf(stderr, "Index %zu out of bounds for vector size: %zu!\n",
            index, vector->size);
        exit(EXIT_FAILURE);
    }

    return vector->array[index];
}

/**
 * Removes the element at the specified index from the vector.
 *
 * @param vector A pointer to the vector structure.
 * @param index The index position of the element to be removed.
 */
void removeFromVector(struct vector* vector, size_t index) {
    if (index > vector->size - 1) {
        fprintf(stderr, "Index %zu out of bounds for vector size: %zu!\n",
            index, vector->size);
        exit(EXIT_FAILURE);
    }

    for (size_t i = index; i < vector->size - 1; i++) {
        vector->array[i] = vector->array[i + 1];
    }

    vector->size--;
}

/**
 * Deallocates the memory occupied by the vector if it is no longer in use.
 *
 * @param vector A pointer to the vector structure.
 */
void freeVector(struct vector* vector) {
    if (NULL == vector) {
        return;
    }

    free(vector->array);
    free(vector);
}