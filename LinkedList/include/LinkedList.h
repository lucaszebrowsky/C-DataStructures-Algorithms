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

struct node {
    int value;
    struct node* next;
};

struct LinkedList {
    struct node* head;
    size_t size;
};

// Initilaizes the LinkedList by setting the head to NULL and size to 0
struct LinkedList* initLinkedList(void);

// Allocates and returns a new node. The value of the new node gets set to the specified one
struct node* newNode(int value);

// Add a new node at the end of the LinkedList
struct node* addNode(struct LinkedList* list, struct node* newNode);

/*
 *  on success returns a pointer to the node at the specified index,
 *  otherwise returns NULL
 */
struct node* getNode(struct LinkedList* list, size_t index);

/*
 *  Loops through the linked list and removes the node at the given index,
 *  ensures the integrity of the list by updating the next pointer of the previous node
 *  to pointer to the next node after the one being removed, if necessary.
 */
void removeNode(struct LinkedList* list, size_t index);
