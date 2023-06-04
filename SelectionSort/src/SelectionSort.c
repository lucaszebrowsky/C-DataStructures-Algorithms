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
#include <time.h>
#include "SelectionSort.h"

 /**
  * Sorts the array in ascending order (smallest to biggest value) using the selection sort algorithm.
  *
  * @param array The array to be sorted.
  * @param len The length of the array.
  */
void selectionSortAscending(int array[], size_t len) {
    time_t start = time(NULL);
    printf("Sorting...\n");

    for (size_t i = 0; i < (len - 1); i++) {
        size_t index = i;

        for (size_t j = (i + 1); j < len; j++) {

            if (array[j] > array[index]) {
                index = j;
            }
        }

        if (index != i) {
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
    }

    time_t end = time(NULL);
    double interval = difftime(end, start);

    printf("Done in %fs\n", interval);
}

/**
 * Sorts the array in descending order (biggest to smallest value) using the selection sort algorithm.
 *
 * @param array The array to be sorted.
 * @param len The length of the array.
 */
void selectionSortDescending(int array[], size_t len) {
    time_t start = time(NULL);
    printf("Sorting...\n");

    for (size_t i = 0; i < (len - 1); i++) {
        size_t index = i;

        for (size_t j = (i + 1); j < len; j++) {

            if (array[j] < array[index]) {
                index = j;
            }
        }

        if (index != i) {
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }

    }

    time_t end = time(NULL);
    double interval = difftime(end, start);

    printf("Done in %fs\n", interval);
}
