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
#include "Vector.h"

int main(void) {

    struct vector vector;

    initVector(&vector);

    for (int i = 0; i <= 100; i++) {
        addToVector(&vector, i);
    }

    for (size_t i = 0; i < vector.size; i++) {
        printf("Vector %zu: %d\n", i, getValueFromVector(&vector, i));
    }

    // Testing if the remove function works as expected
    printf("Removing element on index 99...\n");
    printf("Before: { index: 99, value: %d }\n", getValueFromVector(&vector, 99));

    removeFromVector(&vector, 99);

    printf("After: { index: 99, value: %d }\n", getValueFromVector(&vector, 99));

    return 0;
}
