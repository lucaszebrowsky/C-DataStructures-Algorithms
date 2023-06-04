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

// Vector of Ints
struct vector {
    int* array;
    size_t size;
    size_t capacity;
};

/*
 * Allocates an initial capacity for the vector.
 * Returns a pointer to the vector struct on success otherwise NULL
 */
struct vector* initVector(size_t capacity);

// Adds an integer to the vector
void addToVector(struct vector* vector, int value);

// Returns the value stored in the vector at the given position
int getValueFromVector(struct vector* vector, size_t index);

// Removes the element at the specified index from the vector
void removeFromVector(struct vector* vector, size_t index);

// Deallocates the memory occupied by the vector if it is no longer in use
void freeVector(struct vector* vector);
