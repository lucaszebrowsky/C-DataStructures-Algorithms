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
#include "LinkedList.h"

int main(void) {

    struct LinkedList* list = initLinkedList();

    struct node* node1 = newNode(12);
    struct node* node2 = newNode(45);
    struct node* node3 = newNode(100);

    addNode(list, node1);
    addNode(list, node2);
    addNode(list, node3);

    struct node* temp = getNode(list, 0);

    if (NULL != temp) {
        printf("Value of the first Node: %d\n", temp->value);
    }

    removeNode(list, 0);

    struct node* temp2 = getNode(list, 0);

    if (NULL != temp2) {
        printf("Value of the new first Node: %d\n", temp2->value);
    }

    return 0;
}
