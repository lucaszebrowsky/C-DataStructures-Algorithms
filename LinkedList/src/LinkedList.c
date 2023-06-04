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
#include "LinkedList.h"

 /**
  * Allocates memory for a zero-initialized LinkedList structure.
  *
  * @return A pointer to the newly created LinkedList structure or NULL on failure
  */
struct LinkedList* initLinkedList(void) {
    struct LinkedList* list = calloc(1, sizeof(struct LinkedList));
    return list;
}

/**
 * Creates and returns a new node whos value is the specified one.
 *
 * @param value The specified value whichh shhould be stored in the node.
 * @return A pointer to the newly created node, or NULL on failure
 */
struct node* newNode(int value) {
    struct node* node = calloc(1, (sizeof(struct node)));

    if (NULL == node) {
        return NULL;
    }

    node->next = NULL;
    node->value = value;

    return node;
}

/**
 * Appends a new node at the end of the LinkedList
 *
 * @param list The linked list to which the node should be appended.
 * @param newNode The new node that should be added.
 * @return A pointer to the node on success or NULL on failure
 */
struct node* addNode(struct LinkedList* list, struct node* newNode) {
    if (NULL == list || NULL == newNode) {
        return NULL;
    }

    if (NULL == list->head) {
        list->head = newNode;
        list->size++;
        return newNode;
    }

    struct node* temp = list->head;

    while (NULL != temp->next) {
        temp = temp->next;
    }

    temp->next = newNode;
    list->size++;

    return newNode;
}

/**
 * Retrieves the node at the specified index from the linked list.
 *
 * @param list The linked list to traverse.
 * @param index The index of the desired node.
 * @return A pointer to the node at the specified index if found,
 *  or NULL if the index is out of range or the list is empty.
 */
struct node* getNode(struct LinkedList* list, size_t index) {
    if (NULL == list) {
        return NULL;
    }

    if (index > list->size - 1) {
        return NULL;
    }

    size_t i = 0;

    struct node* currentNode = list->head;

    while (i < index) {
        currentNode = currentNode->next;
        i++;
    }

    return currentNode;
}

/**
 * Removes the node at the specified index from the linked list. *  ensures the integrity of the list by updating the next pointer of the previous node
 *
 * @param list The linked list from which to remove the node.
 * @param index The index of the node to remove.
 */
void removeNode(struct LinkedList* list, size_t index) {
    if (NULL == list || NULL == list->head) {
        return;
    }

    if (index >= list->size) {
        return;
    }

    // Is it the first node?
    if (0 == index) {

        struct node* nodeToRemove = list->head;
        list->head = list->head->next;
        free(nodeToRemove);
        nodeToRemove = NULL;
    }
    else {
        struct node* previousNode = list->head;
        struct node* currentNode = list->head->next;

        size_t i = 1;

        while (i < index) {
            previousNode = currentNode;
            currentNode = currentNode->next;
            i++;
        }

        previousNode->next = currentNode->next;

        free(currentNode);
        currentNode = NULL;
    }

    list->size--;
}

/**
 * Deallocates the memory occupied by the LinkedList if it is no longer in use.
 *
 * @param list A pointer to the LinkedList structure.
 */
void freeLinkedList(struct LinkedList* list) {
    if (NULL == list) {
        return;
    }

    struct node* currentNode = list->head;
    struct node* nextNode;

    while (NULL != currentNode) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    free(list);
}
