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
#include <string.h>
#include "Stack.h"

void initStack(struct stack* stack) {
    stack->top = -1;
}

/**
 * Pushes the return address of a function onto the stack.
 *
 * @param stack A pointer to the stack structure.
 * @param function The return address to be pushed onto the stack.
 * @return The return address that was pushed onto the stack, or NULL if the stack is full.
 */
void* push(struct stack* stack, void* function) {
    if (STACKSIZE - 1 == stack->top) {
        return NULL;
    }

    stack->top++;
    stack->stack[stack->top] = function;
    return function;
}

/**
 * Pops an element from the top of the stack.
 *
 * @param stack A pointer to the stack structure.
 * @return The element that was popped from the stack, or NULL if the stack is empty.
 */
void* pop(struct stack* stack) {
    if (-1 == stack->top) {
        fprintf(stderr, "Stack is empty!\n");
        return NULL;
    }

    void* pop = stack->stack[stack->top];
    stack->top--;
    return pop;
}

/**
 * Prints the addresses of elements in the stack, starting from the top.
 *
 * @param stack A pointer to the stack structure.
 */
void stackTrace(struct stack* stack) {
    if (-1 == stack->top) {
        fprintf(stderr, "Stack is empty!\n");
        return;
    }

    printf("**** Start of Stack trace ****\n");

    for (int index = stack->top; index >= 0; index--) {
        printf("%d: %p\n", index, stack->stack[index]);
    }

    printf("**** End of Stack trace ****\n");
}
