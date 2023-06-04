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
#include "SelectionSort.h"

#define ARRAYLEN(x) sizeof(x)/sizeof(x[0])
#define SIZE 100000

void printArray(int array[], size_t len) {
    for (size_t i = 0; i < len; i++) {

        printf("%zu:%i\n", i, array[i]);
    }
}

int main(void) {
    int array[SIZE];

    size_t len = ARRAYLEN(array);

    // Initialize the array
    for (int i = 0; i < SIZE; i++) {
        array[i] = SIZE - i;
    }

    printArray(array, len);

    printf("**** Start Ascending Selection Sort ****\n");

    selectionSortAscending(array, len);

    printArray(array, len);

    printf("**** Start Descending Selection Sort ****\n");

    selectionSortDescending(array, len);

    printArray(array, len);
}
